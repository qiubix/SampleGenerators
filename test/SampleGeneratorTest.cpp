#include <gmock/gmock.h>
using ::testing::Eq;
#include <gtest/gtest.h>
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
