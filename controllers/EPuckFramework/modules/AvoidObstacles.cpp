/*
 * AvoidObstacles.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "AvoidObstacles.h"
#include "math/Vector2.h"

void AvoidObstacles::update(
    AvoidObstaclesUnicycleRequestOutput& theAvoidObstaclesUnicycleRequestOutput)
{

  const static double constantThetaDot(config.getValue("constantThetaDot", 300.0f));
  Vector2<> thetaDot(constantThetaDot, constantThetaDot); // (left, right)

  double w = 0.0f;
  // Simple avoid obstacle behavior
  // detect obsctacles
  static const double distT = 0.035f;

  bool leftObstacle = theCalibratedSensorData->distanceValues[0] < distT
      || theCalibratedSensorData->distanceValues[1] < distT
      || theCalibratedSensorData->distanceValues[2] < distT;
  bool rightObstacle = theCalibratedSensorData->distanceValues[5] < distT
      || theCalibratedSensorData->distanceValues[6] < distT
      || theCalibratedSensorData->distanceValues[7] < distT;
  theAvoidObstaclesUnicycleRequestOutput.active = leftObstacle || rightObstacle;
  if (leftObstacle)
  {
    // turn right
    //thetaDot += Vector2<>(-constantThetaDot, constantThetaDot);
    w += 200.0f;
  }
  else if (rightObstacle)
  {
    // turn left
    //thetaDot += Vector2<>(constantThetaDot, -constantThetaDot);
    w -= 200.0f;
  }

  theAvoidObstaclesUnicycleRequestOutput.w = w;
  theAvoidObstaclesUnicycleRequestOutput.v = 15.0f
      / (log(abs(theAvoidObstaclesUnicycleRequestOutput.w) + 5.0f) + 1.0f);

  std::cout << "AvoidObstacles=" << theAvoidObstaclesUnicycleRequestOutput.active << std::endl;
}

MAKE_MODULE(AvoidObstacles)

