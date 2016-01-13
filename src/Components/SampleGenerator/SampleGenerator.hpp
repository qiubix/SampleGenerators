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

namespace Generators {
namespace Sample {

/*!
 * \class SampleGenerator
 * \brief Component for building octree from point cloud
 * \author Karol Katerżawa
 */
class SampleGenerator: public Base::Component
{
public:
  SampleGenerator(const std::string & name = "SampleGenerator");
  virtual ~SampleGenerator();

  void prepareInterface();

protected:

  /// Input data stream

  /// Output data stream

  bool onInit();
  bool onFinish();
  bool onStart();
  bool onStop();

  /*!
   * Event handler function.
   */

};

}//: namespace Sample
}//: namespace Generators


/*
 * Register processor component.
 */
REGISTER_COMPONENT("SampleGenerator", Generators::Sample::SampleGenerator)

#endif /* OCTREE_BUILDER_HPP_ */

