/*
 * ProjectModule.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#include "ProjectModule.h"

void ProjectModule::update(MotionRequest& theMotionRequest)
{
  const static double constantThetaDot(500.0f);
  Vector2<> thetaDot(constantThetaDot, constantThetaDot); // (left, right)

  // Simple avoid obstacle behavior
  // detect obsctacles
  bool leftObstacle = theDistanceSensor->values[0] > 100.0 || theDistanceSensor->values[1] > 100.0
      || theDistanceSensor->values[2] > 100.0;
  bool rightObstacle = theDistanceSensor->values[5] > 100.0 || theDistanceSensor->values[6] > 100.0
      || theDistanceSensor->values[7] > 100.0;

  if (leftObstacle)
  {
    // turn right
    thetaDot += Vector2<>(-constantThetaDot, constantThetaDot);
  }
  else if (rightObstacle)
  {
    // turn left
    thetaDot += Vector2<>(constantThetaDot, -constantThetaDot);
  }

  theMotionRequest.wheelSpeedRequest.left = thetaDot.x;
  theMotionRequest.wheelSpeedRequest.right = thetaDot.y;
}

MAKE_MODULE(ProjectModule)

