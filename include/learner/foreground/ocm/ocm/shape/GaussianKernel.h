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

// Package includes
#include <Eigen/Core>
#include <Eigen/Geometry>

#include <boost/shared_ptr.hpp>
#include <boost/property_tree/ptree.hpp>

#include <visualization/psm/ProbabilisticSecondarySceneObjectVisualization.h>

// Local includes
#include "helper/SerializationHelper.h"

namespace ProbabilisticSceneRecognition {

namespace PSMLearner {

  /**
   * This class is a wrapper for a single gaussian kernel.
   *
   * @author Joachim Gehrung
   * @version See SVN
   */
  class GaussianKernel {
  public:

    /**
     * Constructor.
     */
    GaussianKernel();
    
    /**
     * Destructor.
     */
    ~GaussianKernel();
    
    /**
     * Initializes the visualization mechanism.
     * 
     * @param mSuperior The superior visualizer coordinating the scene visualizers.
     */
    void initializeVisualizer(boost::shared_ptr<Visualization::ProbabilisticSecondarySceneObjectVisualization> mSuperior);
    
    /**
     * Compares this kernel with the given one.
     * 
     * @param pKernel The kernel to compare this one with.
     * @return True, if both kernels are equal.
     */
    bool compare(const GaussianKernel pKernel);
    
    /**
     * Saves the content to XML.
     * 
     * @param pPt Datastructure for handling XML operations.
     */
    void save(boost::property_tree::ptree& pPt);
    
  public:
    
    /**
     * The weight of the gaussian kernel.
     */
    double mWeight;
    
    /**
     * The mean vector of the gaussien kernel.
     */
    boost::shared_ptr<Eigen::VectorXd> mMean;
    
    /**
     * The cocovariance matrix of the gaussian kernel.
     */
    boost::shared_ptr<Eigen::MatrixXd> mCovariance;
  };
}
}
