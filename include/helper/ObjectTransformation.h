/**

Copyright (c) 2016, Braun Kai, Gehrung Joachim, Heizmann Heinrich, Meißner Pascal
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#pragma once

// Global includes
#include <cmath>
#include <vector>

// Package includes
#include <Eigen/Core>

#include <boost/shared_ptr.hpp>

#include <asr_msgs/AsrObject.h>

#include <tf/transform_listener.h>


namespace ProbabilisticSceneRecognition {
  
  /**
   * This class transforms AsrObjects into a destination frame.
   *
   */
  class ObjectTransformation {
  public:
    
    /**
     * Constructor.
     */
    ObjectTransformation();
    
    /**
     * Destructor.
     */
    ~ObjectTransformation();
    
    /**
     * Sets the base frame to convert the AsrObject messages to.
     * 
     * @param pBaseFrame The base coordinate frame to transform the objects to.
     */
    void setBaseFrame(std::string pBaseFrame);
    
    /**
     * Transforms an object into the given destination frame.
     */
    void transform(const boost::shared_ptr<asr_msgs::AsrObject>& pObject);
    
  private:
    
    /**
     * The name of the frame the objects poses should be converted to.
     */
    std::string mBaseFrame;
    
    /**
     * A transformation listener that is responsible for transforming the evidences into the target coordinate system.
     */
    tf::TransformListener mTfListener;
    
  };
}
