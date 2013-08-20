/*
 * AvoidObstacles.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "AvoidObstacles.h"
#include "math/Vector2.h"

void AvoidObstacles::update(AvoidObstaclesUnicycleRequest& theUnicycleRequest)
{

  const static double constantThetaDot(config.getValue("constantThetaDot", 300.0f));
  Vector2<> thetaDot(constantThetaDot, constantThetaDot); // (left, right)

  double w = 0.0f;
  // Simple avoid obstacle behavior
  // detect obsctacles
  bool leftObstacle = theSensorData->distanceValues[0] > 100.0
      || theSensorData->distanceValues[1] > 100.0 || theSensorData->distanceValues[2] > 100.0;
  bool rightObstacle = theSensorData->distanceValues[5] > 100.0
      || theSensorData->distanceValues[6] > 100.0 || theSensorData->distanceValues[7] > 100.0;
  theUnicycleRequest.active =  leftObstacle || rightObstacle;
  if (leftObstacle)
  {
    // turn right
    //thetaDot += Vector2<>(-constantThetaDot, constantThetaDot);
    w += 400.0f;
  }
  else if (rightObstacle)
  {
    // turn left
    //thetaDot += Vector2<>(constantThetaDot, -constantThetaDot);
    w -= 400.0f;
  }

  theUnicycleRequest.w = w;
  theUnicycleRequest.v = 15.0f / (log(abs(theUnicycleRequest.w) + 5.0f) + 1.0f);

  std::cout << "AvoidObstacles=" << theUnicycleRequest.v << " " << theUnicycleRequest.w << std::endl;
}

MAKE_MODULE(AvoidObstacles)

