#include <gmock/gmock.h>
using ::testing::Eq;
using ::testing::NotNull;
using ::testing::Test;

#include "../src/Components/CvMatGenerator/CvMatGenerator.hpp"

using Generators::Sample::CvMatGenerator;

class CvMatGeneratorTest : public Test {
public:
  CvMatGenerator generator;
  typedef Base::Property<string> StringProperty;
};

TEST_F(CvMatGeneratorTest, shouldCreateCvMatGeneratorComponent) {
  ASSERT_THAT(generator.name(), Eq("CvMatGenerator"));
}

TEST_F(CvMatGeneratorTest, shouldInitializeStreams) {
  generator.prepareInterface();

  ASSERT_THAT(generator.getStream("out_img"), NotNull());
}

