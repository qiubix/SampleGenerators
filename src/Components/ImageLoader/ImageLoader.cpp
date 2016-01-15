/*!
 * \file ImageLoader.cpp
 * \brief
 */

#include <memory>
#include <string>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>

#include "ImageLoader.hpp"

#include "Logger.hpp"

namespace Generators {
namespace Sample {

ImageLoader::ImageLoader(const std::string & name) :
    Base::Component(name),
    prop_directory("sequence.directory", std::string(".")),
    prop_pattern("sequence.pattern", std::string(".*\\.(jpg|png|bmp|yaml|yml)"))
{
  LOG(LTRACE)<<"Hello ImageLoader\n";
  registerProperty(prop_directory);
  registerProperty(prop_pattern);
}

ImageLoader::~ImageLoader() {
  LOG(LTRACE)<<"Good bye ImageLoader\n";
}

void ImageLoader::prepareInterface() {
  LOG(LTRACE) << "ImageLoader::prepareInterface\n";
  //registerStream("in_cloud", &in_cloud);
  registerStream("out_img", &out_img);
  registerHandler("onLoadImage", boost::bind(&ImageLoader::onLoadImage, this));
  addDependency("onLoadImage", NULL);
}

bool ImageLoader::findFiles() {
  files.clear();

  files = Utils::searchFiles(prop_directory, prop_pattern);

  LOG(LINFO) << "Sequence loaded.";
  BOOST_FOREACH(std::string fname, files)
    LOG(LINFO) << fname;

  return !files.empty();
}

void ImageLoader::setPropertyValue(const std::string &propertyName, const std::string &newValue) {
  if (propertyName == prop_directory.name()) {
    prop_directory = newValue;
  }
  else {
    prop_pattern = newValue;
  }
}

bool ImageLoader::onInit() {
  LOG(LTRACE) << "ImageLoader::initialize\n";
  return true;
}

bool ImageLoader::onFinish() {
  LOG(LTRACE) << "ImageLoader::finish\n";
  return true;
}

bool ImageLoader::onStop() {
  LOG(LTRACE) << "ImageLoader::onStop\n";
  return true;
}

bool ImageLoader::onStart() {
  LOG(LTRACE) << "ImageLoader::onStart\n";
  return true;
}

void ImageLoader::onLoadImage() {
  LOG(LTRACE) << "ImageLoader::onLoadImage\n";

  findFiles();

  try {
    string ext = getFileExtension(files[0]);
    CLOG(LDEBUG) << "Extracted file Extension " << ext;
    img = cv::imread(files[0], CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
  } catch (...) {
    CLOG(LWARNING) << name() << ": image reading failed! [" << files[0] << "]";
  }

  out_img.write(img);

}

string ImageLoader::getFileExtension(const string & fileName) const {
  return fileName.substr(fileName.rfind(".") + 1);
}

}//: namespace Sample
}//: namespace Generators
