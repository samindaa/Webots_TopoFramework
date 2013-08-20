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
  const static double R = theSpecifications->wheelRadius;
  const static double L = theSpecifications->wheelBaseLength;
  const double v = theUnicycleRequest->v;
  const double w = theUnicycleRequest->w;

  theMotionRequest.wheelSpeedRequest.right = v / R + (w * L) / (2.0f * R);
  theMotionRequest.wheelSpeedRequest.left = v / R - (w * L) / (2.0f * R);

  theMotionRequest.wheelSpeedRequest.right = std::min(
      std::max(theMotionRequest.wheelSpeedRequest.right, -theSpecifications->maxSpeed),
      theSpecifications->maxSpeed);
  theMotionRequest.wheelSpeedRequest.left = std::min(
      std::max(theMotionRequest.wheelSpeedRequest.left, -theSpecifications->maxSpeed),
      theSpecifications->maxSpeed);

  //std::cout << theMotionRequest.wheelSpeedRequest.left << " "
  //    << theMotionRequest.wheelSpeedRequest.right << std::endl;
}

MAKE_MODULE(DifferentialDrive)

