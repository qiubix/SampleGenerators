#include <gmock/gmock.h>
using ::testing::Eq;
using ::testing::NotNull;
using ::testing::Test;

#include "../src/Components/SampleGenerator/SampleGenerator.hpp"

using Generators::Sample::SampleGenerator;

class SampleGeneratorTest : public Test {
};

TEST_F(SampleGeneratorTest, shouldCreateSampleGeneratorComponent) {
  SampleGenerator generator("generator");

  ASSERT_THAT(generator.name(), Eq("generator"));
}

TEST_F(SampleGeneratorTest, shouldInitializeHandlers) {
  SampleGenerator generator("generator");
  generator.prepareInterface();

  ASSERT_THAT(generator.listHandlers(), Eq("onLoadImage\n"));
}

TEST_F(SampleGeneratorTest, shouldInitializeStreams) {
  SampleGenerator generator("generator");
  generator.prepareInterface();

  ASSERT_THAT(generator.getStream("out_img"), NotNull());
}

TEST_F(SampleGeneratorTest, shouldInitializeProperties) {
  SampleGenerator generator("generator");

  ASSERT_THAT(generator.listProperties(), Eq("sequence.directory\nsequence.pattern\n"));
  ASSERT_THAT(generator.getAllProperties(), testing::SizeIs(2));
//  generator.getProperty("sequence.directory")->retrieve(directoryValue);
  Base::Property<string>* directoryProperty = dynamic_cast<Base::Property<string>* > (generator.getProperty("sequence.directory"));
//  ASSERT_THAT(directoryProperty.retrieve(), Eq("."));
//  directoryProperty.retrieve(directoryValue);
  string directoryValue = *directoryProperty;
  ASSERT_THAT(directoryValue, Eq("."));
  Base::Property<string>* patternProperty = dynamic_cast<Base::Property<string>* > (generator.getProperty("sequence.pattern"));
  string patternValue = *patternProperty;
  ASSERT_THAT(patternValue, Eq(".*\\.(jpg|png|bmp|yaml|yml)"));
//  ASSERT_THAT((*generator.getProperty("sequence.directory"))(), Eq("."));
//  ASSERT_THAT(generator.getProperty("sequence.pattern")->retrieve(), Eq(".*\\.(jpg|png|bmp|yaml|yml)"));
}

TEST_F(SampleGeneratorTest, shouldSetNewPropertyValue) {
  SampleGenerator generator("generator");

  generator.setPropertyValue("sequence.pattern", "new\\.value");

  Base::Property<string>* patternProperty = dynamic_cast<Base::Property<string>* > (generator.getProperty("sequence.pattern"));
  string patternValue = *patternProperty;
  ASSERT_THAT(patternValue, Eq("new\\.value"));
}

TEST_F(SampleGeneratorTest, shouldReturnFalseWhenNoFilesFound) {
  SampleGenerator generator("generator");

  ASSERT_THAT(generator.findFiles(), Eq(false));
}

TEST_F(SampleGeneratorTest, shouldReturnTrueWhenFileIsFound) {
  SampleGenerator generator("generator");
  generator.setPropertyValue("sequence.pattern", "first\\.testfile");

  ASSERT_THAT(generator.findFiles(), Eq(true));
}

TEST_F(SampleGeneratorTest, shouldSaveFileNameToFilesOnSearch) {
  SampleGenerator generator("generator");
  generator.setPropertyValue("sequence.pattern", ".*\\.testfile");
  generator.findFiles();

  vector<string> files = generator.getFiles();
  ASSERT_THAT(files, testing::SizeIs(2));
  ASSERT_THAT(files, testing::Contains("./first.testfile"));
  ASSERT_THAT(files, testing::Contains("./second.testfile"));
}
