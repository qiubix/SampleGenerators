/*!
 * \file CvMatGenerator.cpp
 * \brief
 */

#include <memory>
#include <string>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>

#include "CvMatGenerator.hpp"

#include "Logger.hpp"

namespace Generators {
namespace Sample {

CvMatGenerator::CvMatGenerator(const std::string & name) :
    Base::Component(name),
    property_width("matrix.width", 4),
    property_height("matrix.height", 3)
{
  LOG(LTRACE)<<"Hello CvMatGenerator\n";
  registerProperty(property_width);
  registerProperty(property_height);
}

CvMatGenerator::~CvMatGenerator() {
  LOG(LTRACE)<<"Good bye CvMatGenerator\n";
}

void CvMatGenerator::prepareInterface() {
  LOG(LTRACE) << "CvMatGenerator::prepareInterface\n";
  registerStream("out_img", &out_img);
}

bool CvMatGenerator::onInit() {
  LOG(LTRACE) << "CvMatGenerator::initialize\n";
  return true;
}

bool CvMatGenerator::onFinish() {
  LOG(LTRACE) << "CvMatGenerator::finish\n";
  return true;
}

bool CvMatGenerator::onStop() {
  LOG(LTRACE) << "CvMatGenerator::onStop\n";
  return true;
}

bool CvMatGenerator::onStart() {
  LOG(LTRACE) << "CvMatGenerator::onStart\n";
  return true;
}

}//: namespace Sample
}//: namespace Generators
