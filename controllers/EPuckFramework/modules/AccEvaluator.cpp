/*
 * AccEvaluator.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "AccEvaluator.h"

void AccEvaluator::update(Odometry& theOdometry)
{
  // get the current encoder positions of both wheels
  EPuckController& conn = EPuckFramework::getController();
  Vector2<> currEncPos(conn.getLeftEncoder(), conn.getRightEncoder());

  // calculate the linear distance (number of ticks across a
  // given span of time (sample)) of each wheel has traveled ...
  Vector2<> dNTicks(currEncPos.x - prevEncPos.x, currEncPos.y - prevEncPos.y);

  // convert the number of the passed ticks (covered by each wheel) to meters ...
  Vector2<> dDist(dNTicks.x / theSpecifications->encoderResolution * theSpecifications->wheelRadius,
      dNTicks.y / theSpecifications->encoderResolution * theSpecifications->wheelRadius);

  // calculate the displacement (distance) from the center C
  // of the robot during the time span (sample) ...
  double dDispCR = (dDist.x + dDist.y) / 2.0f;
  // calculate the orientation (rotation) theta ...
  pos.rotation += (dDist.x - dDist.y) / theSpecifications->wheelBaseLength;
  pos.rotation = normalize(pos.rotation);

  // calculate the cartesian cooridnates (x, y) of the robot ...
  pos.translation += Vector2<>(dDispCR * sin(pos.rotation), dDispCR * cos(pos.rotation));

  // update the previous encoder positions ...
  prevEncPos = currEncPos;

  // write the calculated values into the buffer and return ...
  theOdometry.pose.translation.x = +pos.translation.y;
  theOdometry.pose.translation.y = -pos.translation.x;
  theOdometry.pose.rotation = -pos.rotation;

  std::cout << "odom=" << theOdometry.pose.translation.x << " " << theOdometry.pose.translation.y
      << " " << (theOdometry.pose.rotation * 180.0f / M_PI) << std::endl;

}

MAKE_MODULE(AccEvaluator)

