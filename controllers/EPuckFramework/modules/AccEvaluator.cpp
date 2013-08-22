/*
 * AccEvaluator.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "AccEvaluator.h"

void AccEvaluator::update(Odometry& theOdometry)
{
  /*
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

   */

  static double prevRightTicks = 0.0f;
  static double prevLeftTicks = 0.0f;
  static double metersPerTicks = 2.0 * M_PI * theSpecifications->wheelRadius
      / theSpecifications->maxSpeed;

  double rightTicks = theSensorData->rightEncoder;
  double leftTicks = theSensorData->leftEncoder;

  double dRight = (rightTicks - prevRightTicks) * metersPerTicks;
  double dLeft = (leftTicks - prevLeftTicks) * metersPerTicks;
  double dCenter = (dRight + dLeft) / 2.0f;
  double dRotation = (dRight - dLeft) / theSpecifications->wheelBaseLength;

  pose.rotation += dRotation;
  pose.translation += Vector2<>(dCenter * cos(pose.rotation), dCenter * sin(pose.rotation));

  prevRightTicks = rightTicks;
  prevLeftTicks = leftTicks;

  theOdometry.pose = pose;
  theOdometry.pose.rotation = normalize(theOdometry.pose.rotation);

  std::cout << "odom=" << theOdometry.pose.translation.x << " " << theOdometry.pose.translation.y
      << " " << (theOdometry.pose.rotation * 180.0f / M_PI) << std::endl;

}

MAKE_MODULE(AccEvaluator)

