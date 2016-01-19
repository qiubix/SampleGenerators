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
    Base::Component(name)
{
  LOG(LTRACE)<<"Hello CvMatSink\n";
}

CvMatSink::~CvMatSink() {
  LOG(LTRACE)<<"Good bye CvMatSink\n";
}

void CvMatSink::prepareInterface() {
  LOG(LTRACE) << "CvMatSink::prepareInterface\n";
  registerStream("in_img", &in_img);
  registerHandler("onNewMat", boost::bind(&CvMatSink::onNewMat, this));
  addDependency("onNewMat", &in_img);
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
  return true;
}

void CvMatSink::onNewMat() {
  img = in_img.read();
  display();
}

void CvMatSink::display() {
  cout << img;
}

}//: namespace Sample
}//: namespace Sinks
