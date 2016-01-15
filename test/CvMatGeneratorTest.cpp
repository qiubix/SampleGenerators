#include <gmock/gmock.h>

#include "../src/Components/CvMatGenerator/CvMatGenerator.hpp"

using Generators::Sample::CvMatGenerator;
using namespace testing;

class CvMatGeneratorTest : public Test {
public:
  CvMatGenerator generator;

  typedef Base::Property<int> IntProperty;

  int getIntPropertyValue(const string & propertyName) {
    IntProperty* property = dynamic_cast<IntProperty* > (generator.getProperty(propertyName));
    int propertyValue = *property;
    return propertyValue;
  }
};

TEST_F(CvMatGeneratorTest, shouldCreateCvMatGeneratorComponent) {
  ASSERT_THAT(generator.name(), Eq("CvMatGenerator"));
}

TEST_F(CvMatGeneratorTest, shouldInitializeStreams) {
  generator.prepareInterface();

  ASSERT_THAT(generator.getStream("out_img"), NotNull());
}

TEST_F(CvMatGeneratorTest, shouldSetDefaultPropertiesOnInit) {
  EXPECT_THAT(generator.listProperties(), HasSubstr("matrix.width"));
  EXPECT_THAT(generator.listProperties(), HasSubstr("matrix.height"));
  EXPECT_THAT(generator.getAllProperties(), SizeIs(2));

  int widthValue = getIntPropertyValue("matrix.width");
  EXPECT_THAT(widthValue, Eq(4));

  int heightValue = getIntPropertyValue("matrix.height");
  EXPECT_THAT(heightValue, Eq(3));
}

TEST_F(CvMatGeneratorTest, shouldSetNewPropertyValue) {
  generator.setPropertyValue("matrix.width", 9);
  generator.setPropertyValue("matrix.height", 13);

  int widthValue = getIntPropertyValue("matrix.width");
  EXPECT_THAT(widthValue, Eq(9));

  int heightValue = getIntPropertyValue("matrix.height");
  EXPECT_THAT(heightValue, Eq(13));
}

TEST_F(CvMatGeneratorTest, shouldCreateMatrixWithSpecificDimentionsOnStart) {
  generator.onStart();

  cv::Mat matrix = generator.getImg();
  EXPECT_THAT(matrix.rows, Eq(3));
  EXPECT_THAT(matrix.cols, Eq(4));
}
