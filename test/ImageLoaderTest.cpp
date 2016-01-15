#include <gmock/gmock.h>
using ::testing::Eq;
using ::testing::NotNull;
using ::testing::Test;

#include "../src/Components/ImageLoader/ImageLoader.hpp"

using Generators::Sample::ImageLoader;

class ImageLoaderTest : public Test {
};

TEST_F(ImageLoaderTest, shouldCreateImageLoaderComponent) {
  ImageLoader generator("generator");

  ASSERT_THAT(generator.name(), Eq("generator"));
}

TEST_F(ImageLoaderTest, shouldInitializeHandlers) {
  ImageLoader generator("generator");
  generator.prepareInterface();

  ASSERT_THAT(generator.listHandlers(), Eq("onLoadImage\n"));
}

TEST_F(ImageLoaderTest, shouldInitializeStreams) {
  ImageLoader generator("generator");
  generator.prepareInterface();

  ASSERT_THAT(generator.getStream("out_img"), NotNull());
}

TEST_F(ImageLoaderTest, shouldInitializeProperties) {
  ImageLoader generator("generator");

  ASSERT_THAT(generator.listProperties(), Eq("sequence.directory\nsequence.pattern\n"));
  ASSERT_THAT(generator.getAllProperties(), testing::SizeIs(2));

  Base::Property<string>* directoryProperty =
      dynamic_cast<Base::Property<string>* > (generator.getProperty("sequence.directory"));
  string directoryValue = *directoryProperty;
  ASSERT_THAT(directoryValue, Eq("."));

  Base::Property<string>* patternProperty =
      dynamic_cast<Base::Property<string>* > (generator.getProperty("sequence.pattern"));
  string patternValue = *patternProperty;
  ASSERT_THAT(patternValue, Eq(".*\\.(jpg|png|bmp|yaml|yml)"));
}

TEST_F(ImageLoaderTest, shouldSetNewPropertyValue) {
  ImageLoader generator("generator");

  generator.setPropertyValue("sequence.pattern", "new\\.value");

  Base::Property<string>* patternProperty =
      dynamic_cast<Base::Property<string>* > (generator.getProperty("sequence.pattern"));
  string patternValue = *patternProperty;
  ASSERT_THAT(patternValue, Eq("new\\.value"));
}

TEST_F(ImageLoaderTest, shouldReturnFalseWhenNoFilesFound) {
  ImageLoader generator("generator");
  generator.setPropertyValue("sequence.pattern", "notexisting\\.file");

  ASSERT_THAT(generator.findFiles(), Eq(false));
}

TEST_F(ImageLoaderTest, shouldReturnTrueWhenFileIsFound) {
  ImageLoader generator("generator");
  generator.setPropertyValue("sequence.pattern", "first\\.testfile");

  ASSERT_THAT(generator.findFiles(), Eq(true));
}

TEST_F(ImageLoaderTest, shouldSaveFileNameToFilesOnSearch) {
  ImageLoader generator("generator");
  generator.setPropertyValue("sequence.pattern", ".*\\.testfile");

  generator.findFiles();

  vector<string> files = generator.getFiles();
  ASSERT_THAT(files, testing::SizeIs(2));
  ASSERT_THAT(files, testing::Contains("./first.testfile"));
  ASSERT_THAT(files, testing::Contains("./second.testfile"));
}

TEST_F(ImageLoaderTest, shouldFindFilesAutomaticallyOnLoadImage) {
  ImageLoader generator("generator");

  generator.onLoadImage();

  vector<string> files = generator.getFiles();
  ASSERT_THAT(files, testing::SizeIs(1));
  ASSERT_THAT(files, testing::Contains("./43074.jpg"));
}

TEST_F(ImageLoaderTest, shouldSaveLoadedImageToCvMat) {
  ImageLoader generator("generator");

  generator.onLoadImage();

  cv::Mat img = generator.getImg();
  ASSERT_THAT(img.rows, Eq(321));
  ASSERT_THAT(img.cols, Eq(481));
}
