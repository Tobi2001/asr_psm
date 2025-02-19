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
#include <string>

// Package includes
#include <boost/property_tree/ptree.hpp>

namespace ProbabilisticSceneRecognition {
  
  /**
   * This class wrapps a scene's identity
   *
   * @author Joachim Gehrung
   * @version See SVN
   */
  class SceneIdentifier {
  public:
    
    /**
     * Constructor.
     */
    SceneIdentifier();
    
    /**
     * Constructor.
     * 
     * @param pType The type of the scene content wrapped by this class.
     * @param pDescription A short and meaningful description of the scene.
     */
    SceneIdentifier(std::string pType, std::string pDescription);
    
    /**
     * Copy constructor.
     * 
     * @param pOther The instance to copy.
     */
    SceneIdentifier(const SceneIdentifier& pOther);
    
    /**
     * Destructor.
     */
    ~SceneIdentifier();
    
    /**
     * Loads the scene identifier from XML.
     * 
     * @param pPt Data structure for performing XML operations.
     */
    void load(boost::property_tree::ptree& pPt);
    
    /**
     * Saves the scene identifier from XML.
     * 
     * @param pPt Data structure for performing XML operations.
     */
    void save(boost::property_tree::ptree& pPt);
    
  public:
    
    /**
     * The type of the scene content wrapped by this class.
     */
    std::string mType;
    
    /**
     * A short and meaningful description of the scene (e.g. breakfast, lunch, ...).
     */
    std::string mDescription;
    
    /**
     * The a priori plobability of the scene.
     */
    double mPriori;
    
    /**
     * The current probability of the scene.
     */
    double mLikelihood;
  };
}
