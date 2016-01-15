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
  EXPECT_THAT(generator.listProperties(), HasSubstr("matrix.value"));
  EXPECT_THAT(generator.getAllProperties(), SizeIs(3));

  int widthValue = getIntPropertyValue("matrix.width");
  EXPECT_THAT(widthValue, Eq(4));

  int heightValue = getIntPropertyValue("matrix.height");
  EXPECT_THAT(heightValue, Eq(3));

  int fieldValue = getIntPropertyValue("matrix.value");
  EXPECT_THAT(fieldValue, Eq(1));
}

TEST_F(CvMatGeneratorTest, shouldSetNewPropertyValue) {
  generator.setPropertyValue("matrix.width", 9);
  generator.setPropertyValue("matrix.height", 13);
  generator.setPropertyValue("matrix.value", 23);

  int widthValue = getIntPropertyValue("matrix.width");
  EXPECT_THAT(widthValue, Eq(9));

  int heightValue = getIntPropertyValue("matrix.height");
  EXPECT_THAT(heightValue, Eq(13));

  int fieldValue = getIntPropertyValue("matrix.value");
  EXPECT_THAT(fieldValue, Eq(23));
}

TEST_F(CvMatGeneratorTest, shouldCreateMatrixWithSpecificDimentionsOnStart) {
  generator.onStart();

  cv::Mat matrix = generator.getImg();
  EXPECT_THAT(matrix.rows, Eq(3));
  EXPECT_THAT(matrix.cols, Eq(4));
}

TEST_F(CvMatGeneratorTest, shouldFillMatrixWithSpecificValue) {
  generator.setPropertyValue("matrix.value", 3);

  generator.onStart();

  cv::Mat matrix = generator.getImg();
  for (int row = 0; row < matrix.rows; ++row) {
    const int * row_i = matrix.ptr<int>(row);
    for (int column = 0; column < matrix.cols; ++column) {
      EXPECT_THAT(row_i[column], Eq(3));
    }
  }
}
