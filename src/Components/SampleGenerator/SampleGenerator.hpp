/*!
 * \file SampleGenerator.hpp
 * \brief
 */

#ifndef OCTREE_BUILDER_HPP_
#define OCTREE_BUILDER_HPP_

#define CV_NO_BACKWARD_COMPATIBILITY


#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"

#include <opencv2/core/core.hpp>

namespace Generators {
namespace Sample {

/*!
 * \class SampleGenerator
 * \brief
 * \author Karol Katerżawa
 */
class SampleGenerator: public Base::Component
{
public:
  SampleGenerator(const std::string & name = "SampleGenerator");
  virtual ~SampleGenerator();

  void prepareInterface();

  bool findFiles();

  void setPropertyValue(const std::string & propertyName, const std::string & newValue);

  const vector<string> & getFiles() const {
    return files;
  }

  const cv::Mat &getImg() const {
    return img;
  }

  /*!
   * Event handler function.
   */
  void onLoadImage();

protected:

  /// Input data stream

  /// Output data stream
  Base::DataStreamOut<cv::Mat> out_img;

  bool onInit();
  bool onFinish();
  bool onStart();
  bool onStop();

private:
  /// Directory containing the images sequence.
  Base::Property<std::string> prop_directory;

  /// Files pattern (regular expression).
  Base::Property<std::string> prop_pattern;

  std::vector<std::string> files;

  cv::Mat img;

};

}//: namespace Sample
}//: namespace Generators


/*
 * Register processor component.
 */
REGISTER_COMPONENT("SampleGenerator", Generators::Sample::SampleGenerator)

#endif /* OCTREE_BUILDER_HPP_ */

