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

SampleGenerator::SampleGenerator(const std::string & name) :
    Base::Component(name),
    prop_directory("sequence.directory", std::string(".")),
    prop_pattern("sequence.pattern", std::string(".*\\.(jpg|png|bmp|yaml|yml)"))
{
  LOG(LTRACE)<<"Hello SampleGenerator\n";
  registerProperty(prop_directory);
  registerProperty(prop_pattern);
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

bool SampleGenerator::findFiles() {
  files.clear();

  files = Utils::searchFiles(prop_directory, prop_pattern);

  LOG(LINFO) << "Sequence loaded.";
  BOOST_FOREACH(std::string fname, files)
    LOG(LINFO) << fname;

  return !files.empty();
}

void SampleGenerator::setPropertyValue(const std::string &propertyName, const std::string &newValue) {
  if (propertyName == prop_directory.name()) {
    prop_directory = newValue;
  }
  else {
    prop_pattern = newValue;
  }
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
