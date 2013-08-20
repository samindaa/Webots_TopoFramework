/*
 * AccEvaluator.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "AccEvaluator.h"

void AccEvaluator::update(Odometry& theOdometry)
{
  Vector3<> stateDot = RotationMatrix().rotateZ(pose.rotation)
      * Vector3<>(
          theSpecifications->wheelRadius * (theSensorData->rightSpeed + theSensorData->leftSpeed)
              / 2.0f, 0.0f,
          theSpecifications->wheelRadius * (theSensorData->rightSpeed - theSensorData->leftSpeed)
              / theSpecifications->wheelBaseLength);

  pose.translation += (Vector2<>(stateDot.x, stateDot.y) * theSpecifications->timeStep
      * theSpecifications->speedUnit);
  pose.rotation += (stateDot.z * theSpecifications->timeStep * theSpecifications->speedUnit * 0.90f);

  theOdometry.pose.translation = pose.translation;
  theOdometry.pose.rotation = normalize(pose.rotation);

  std::cout << "odom=" << theOdometry.pose.translation.x << " " << theOdometry.pose.translation.y
      << " " << (theOdometry.pose.rotation * 180.0f / M_PI) << std::endl;

}

MAKE_MODULE(AccEvaluator)

