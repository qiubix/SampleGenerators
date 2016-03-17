#include <gmock/gmock.h>

#include "../src/Components/CvMatSink/CvMatSink.hpp"

using Sinks::Sample::CvMatSink;
using namespace testing;

class CvMatSinkTest : public Test {
public:
  CvMatSink sink;

  typedef Base::Property<int> IntProperty;

  int getIntPropertyValue(const string & propertyName) {
    IntProperty* property = dynamic_cast<IntProperty* > (sink.getProperty(propertyName));
    int propertyValue = *property;
    return propertyValue;
  }
};

TEST_F(CvMatSinkTest, shouldCreateCvMatSinkComponent) {
  ASSERT_THAT(sink.name(), Eq("CvMatSink"));
}

TEST_F(CvMatSinkTest, shouldInitializeStreams) {
  sink.prepareInterface();

  ASSERT_THAT(sink.getStream("in_img"), NotNull());
}

TEST_F(CvMatSinkTest, shouldInitializeHandlers) {
  sink.prepareInterface();

  ASSERT_THAT(sink.getHandler("onNewMat"), NotNull());
}

TEST_F(CvMatSinkTest, shouldDisplayCvMatOnNewMat) {
  cv::Mat img;
  img = cv::Mat::ones(3, 4, CV_32S);
  sink.setImg(img);

  internal::CaptureStdout();
  sink.display();

  string output = internal::GetCapturedStdout();
  ASSERT_THAT(output, Eq("[1, 1, 1, 1;\n  1, 1, 1, 1;\n  1, 1, 1, 1]\n"));
}
