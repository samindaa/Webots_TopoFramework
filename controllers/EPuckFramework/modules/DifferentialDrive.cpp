/*
 * DifferentialDrive.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "DifferentialDrive.h"

void DifferentialDrive::update(MotionRequest& theMotionRequest)
{
  // Linear and angular velocities to velocities left and right
  theMotionRequest.wheelSpeedRequest.left = theBehaviorOutput->unicycleRequest.v
      / theSpecifications->wheelRadius
      - (theBehaviorOutput->unicycleRequest.w * theSpecifications->wheelBaseLength)
          / (2.0f * theSpecifications->wheelRadius);
  theMotionRequest.wheelSpeedRequest.right = theBehaviorOutput->unicycleRequest.v
      / theSpecifications->wheelRadius
      + (theBehaviorOutput->unicycleRequest.w * theSpecifications->wheelBaseLength)
          / (2 * theSpecifications->wheelRadius);
  // fixMe: probably have to limit this

  std::cout << theMotionRequest.wheelSpeedRequest.left << " "
      << theMotionRequest.wheelSpeedRequest.right << std::endl;
}

MAKE_MODULE(DifferentialDrive)

