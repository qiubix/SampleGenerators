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
  //registerStream("out_octree", &out_octree);
  //registerHandler("onNewCloud", boost::bind(&SampleGenerator::onNewCloud, this));
  //addDependency("onNewCloud", &in_cloud);
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

}//: namespace Sample
}//: namespace Generators
