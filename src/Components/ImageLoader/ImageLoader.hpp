/*!
 * \file ImageLoader.hpp
 * \brief
 */

#ifndef IMAGE_LOADER_HPP_
#define IMAGE_LOADER_HPP_

#define CV_NO_BACKWARD_COMPATIBILITY


#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"

#include <opencv2/core/core.hpp>

namespace Generators {
namespace Sample {

/*!
 * \class ImageLoader
 * \brief
 * \author Karol Katerżawa
 */
class ImageLoader: public Base::Component
{
public:
  ImageLoader(const std::string & name = "ImageLoader");
  virtual ~ImageLoader();

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

  string getFileExtension(const string &fileName) const;
};

}//: namespace Sample
}//: namespace Generators


/*
 * Register processor component.
 */
REGISTER_COMPONENT("ImageLoader", Generators::Sample::ImageLoader)

#endif /* IMAGE_LOADER_HPP_ */

