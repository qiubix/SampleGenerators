/*!
 * \file CvMatSink.cpp
 * \brief
 */

#include <memory>
#include <string>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>

#include "CvMatSink.hpp"

#include "Logger.hpp"

namespace Sinks {
namespace Sample {

CvMatSink::CvMatSink(const std::string & name) :
    Base::Component(name),
    property_width("matrix.width", 4),
    property_height("matrix.height", 3),
    property_value("matrix.value", 1)
{
  LOG(LTRACE)<<"Hello CvMatSink\n";
  registerProperty(property_width);
  registerProperty(property_height);
  registerProperty(property_value);
}

CvMatSink::~CvMatSink() {
  LOG(LTRACE)<<"Good bye CvMatSink\n";
}

void CvMatSink::prepareInterface() {
  LOG(LTRACE) << "CvMatSink::prepareInterface\n";
  registerStream("out_img", &out_img);
}

void CvMatSink::setPropertyValue(const string &propertyName, const int newValue) {
  if (property_width.name() == propertyName) {
    property_width(newValue);
  } else if (property_height.name() == propertyName){
    property_height(newValue);
  } else {
    property_value(newValue);
  }
}

bool CvMatSink::onInit() {
  LOG(LTRACE) << "CvMatSink::initialize\n";
  return true;
}

bool CvMatSink::onFinish() {
  LOG(LTRACE) << "CvMatSink::finish\n";
  return true;
}

bool CvMatSink::onStop() {
  LOG(LTRACE) << "CvMatSink::onStop\n";
  return true;
}

bool CvMatSink::onStart() {
  LOG(LTRACE) << "CvMatSink::onStart\n";
  img = cv::Mat::ones(property_height,property_width, CV_32S);
  img = img * property_value;
  return true;
}

}//: namespace Sample
}//: namespace Sinks
