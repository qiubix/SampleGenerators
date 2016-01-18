#include <gmock/gmock.h>

#include "../src/Components/CvMatSink/CvMatSink.hpp"

using Sinks::Sample::CvMatSink;
using namespace testing;

class CvMatSinkTest : public Test {
public:
  CvMatSink generator;

  typedef Base::Property<int> IntProperty;

  int getIntPropertyValue(const string & propertyName) {
    IntProperty* property = dynamic_cast<IntProperty* > (generator.getProperty(propertyName));
    int propertyValue = *property;
    return propertyValue;
  }
};

TEST_F(CvMatSinkTest, shouldCreateCvMatSinkComponent) {
  ASSERT_THAT(generator.name(), Eq("CvMatSink"));
}

TEST_F(CvMatSinkTest, shouldInitializeStreams) {
  generator.prepareInterface();

  ASSERT_THAT(generator.getStream("in_img"), NotNull());
}
