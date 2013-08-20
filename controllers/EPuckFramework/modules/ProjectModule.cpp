/*
 * ProjectModule.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#include "ProjectModule.h"

void ProjectModule::update(WheelSpeed& theWheelSpeed)
{
  const static double constantThetaDot(500.0f);
  Vector2<> thetaDot(constantThetaDot, constantThetaDot); // (left, right)

  // Simple avoid obstacle behavior
  // detect obsctacles
  bool leftObstacle = theDistanceSensor->distanceSensorValues[0] > 100.0
      || theDistanceSensor->distanceSensorValues[1] > 100.0
      || theDistanceSensor->distanceSensorValues[2] > 100.0;
  bool rightObstacle = theDistanceSensor->distanceSensorValues[5] > 100.0
      || theDistanceSensor->distanceSensorValues[6] > 100.0
      || theDistanceSensor->distanceSensorValues[7] > 100.0;

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

  theWheelSpeed.dot.x = thetaDot.x;
  theWheelSpeed.dot.y = thetaDot.y;
}

MAKE_MODULE(ProjectModule)

