#include <gmock/gmock.h>

#include "../src/Components/CvMatGenerator/CvMatGenerator.hpp"

using Generators::Sample::CvMatGenerator;
using namespace testing;

class CvMatGeneratorTest : public Test {
public:
  CvMatGenerator generator;
//  typedef Base::Property<string> StringProperty;
  typedef Base::Property<int> IntProperty;
};

TEST_F(CvMatGeneratorTest, shouldCreateCvMatGeneratorComponent) {
  ASSERT_THAT(generator.name(), Eq("CvMatGenerator"));
}

TEST_F(CvMatGeneratorTest, shouldInitializeStreams) {
  generator.prepareInterface();

  ASSERT_THAT(generator.getStream("out_img"), NotNull());
}

TEST_F(CvMatGeneratorTest, shouldSetDefaultPropertiesOnInit) {
  EXPECT_THAT(generator.listProperties(), HasSubstr("mat.width"));
  EXPECT_THAT(generator.listProperties(), HasSubstr("mat.height"));
  EXPECT_THAT(generator.getAllProperties(), SizeIs(2));

  IntProperty* widthProperty = dynamic_cast<IntProperty* > (generator.getProperty("mat.width"));
  int widthValue = *widthProperty;
  EXPECT_THAT(widthValue, Eq(4));

  IntProperty* heightProperty = dynamic_cast<IntProperty* > (generator.getProperty("mat.height"));
  int heightValue = *heightProperty;
  EXPECT_THAT(heightValue, Eq(3));
}
