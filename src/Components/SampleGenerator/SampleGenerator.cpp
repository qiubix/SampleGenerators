/*!
 * \file SampleGenerator.cpp
 * \brief
 */

#include <memory>
#include <string>
#include <iostream>

#include "SampleGenerator.hpp"

#include "Logger.hpp"

namespace Generators {
namespace Sample {

SampleGenerator::SampleGenerator(const std::string & name) : Base::Component(name) {
  LOG(LTRACE)<<"Hello SampleGenerator\n";
}

SampleGenerator::~SampleGenerator() {
  LOG(LTRACE)<<"Good bye SampleGenerator\n";
}

void SampleGenerator::prepareInterface() {
  LOG(LTRACE) << "SampleGenerator::prepareInterface\n";
  //registerStream("in_cloud", &in_cloud);
  registerStream("out_img", &out_img);
  registerHandler("onLoadImage", boost::bind(&SampleGenerator::onLoadImage, this));
  addDependency("onLoadImage", NULL);
}

bool SampleGenerator::onInit() {
  LOG(LTRACE) << "SampleGenerator::initialize\n";
  return true;
}

bool SampleGenerator::onFinish() {
  LOG(LTRACE) << "SampleGenerator::finish\n";
  return true;
}

bool SampleGenerator::onStop() {
  LOG(LTRACE) << "SampleGenerator::onStop\n";
  return true;
}

bool SampleGenerator::onStart() {
  LOG(LTRACE) << "SampleGenerator::onStart\n";
  return true;
}

void SampleGenerator::onLoadImage() {
  LOG(LTRACE) << "SampleGenerator::onLoadImage\n";

}

}//: namespace Sample
}//: namespace Generators
