/*!
 * \file CvMatGenerator.hpp
 * \brief
 */

#ifndef CV_MAT_GENERATOR_HPP_
#define CV_MAT_GENERATOR_HPP_

#define CV_NO_BACKWARD_COMPATIBILITY


#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"

#include <opencv2/core/core.hpp>

namespace Generators {
namespace Sample {

/*!
 * \class CvMatGenerator
 * \brief
 * \author Karol Katerżawa
 */
class CvMatGenerator: public Base::Component
{
public:
  CvMatGenerator(const std::string & name = "CvMatGenerator");
  virtual ~CvMatGenerator();

  void prepareInterface();

protected:

  /// Output data stream
  Base::DataStreamOut<cv::Mat> out_img;

  bool onInit();
  bool onFinish();
  bool onStart();
  bool onStop();

private:
  Base::Property<int> property_width;
  Base::Property<int> property_height;
};

}//: namespace Sample
}//: namespace Generators


/*
 * Register processor component.
 */
REGISTER_COMPONENT("CvMatGenerator", Generators::Sample::CvMatGenerator)

#endif /* CV_MAT_GENERATOR_HPP_ */

