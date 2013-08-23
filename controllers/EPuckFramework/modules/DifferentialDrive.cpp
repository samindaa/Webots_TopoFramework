/*
 * DifferentialDrive.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "DifferentialDrive.h"

void DifferentialDrive::update(WheelSpeedRequest& theWheelSpeedRequest)
{
  // Linear and angular velocities to velocities left and right
  const static double R = theSpecifications->wheelRadius;
  const static double L = theSpecifications->wheelBaseLength;
  const double v = theUnicycleRequestOutput->v;
  const double w = theUnicycleRequestOutput->w;

  theWheelSpeedRequest.right = v / R + (w * L) / (2.0f * R);
  theWheelSpeedRequest.left = v / R - (w * L) / (2.0f * R);
  theWheelSpeedRequest.right *= 1.3f;
  theWheelSpeedRequest.left *= 1.3f;

  theWheelSpeedRequest.right = std::min(
      std::max(theWheelSpeedRequest.right, -theSpecifications->maxSpeed),
      theSpecifications->maxSpeed);
  theWheelSpeedRequest.left = std::min(
      std::max(theWheelSpeedRequest.left, -theSpecifications->maxSpeed),
      theSpecifications->maxSpeed);

  std::cout << "DifferentialDrive=" << theWheelSpeedRequest.right << " "
      << theWheelSpeedRequest.left << std::endl;
}

MAKE_MODULE(DifferentialDrive)

