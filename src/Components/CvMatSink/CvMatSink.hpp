/*!
 * \file CvMatSink.hpp
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

namespace Sinks {
namespace Sample {

/*!
 * \class CvMatSink
 * \brief
 * \author Karol Katerżawa
 */
class CvMatSink: public Base::Component
{
public:
  CvMatSink(const std::string & name = "CvMatSink");
  virtual ~CvMatSink();

  void prepareInterface();

  const cv::Mat &getImg() const {
    return img;
  }

  void onNewMat();

protected:

  /// Input data stream
  Base::DataStreamIn<cv::Mat> in_img;

  bool onInit();
  bool onFinish();
  bool onStart();
  bool onStop();

private:
  cv::Mat img;
};

}//: namespace Sample
}//: namespace Sinks


/*
 * Register processor component.
 */
REGISTER_COMPONENT("CvMatSink", Sinks::Sample::CvMatSink)

#endif /* CV_MAT_GENERATOR_HPP_ */

