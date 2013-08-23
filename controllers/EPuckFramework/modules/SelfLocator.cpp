/*
 * SelfLocator.cpp
 *
 *  Created on: Aug 23, 2013
 *      Author: sam
 */

#include "SelfLocator.h"

void SelfLocator::update(RobotPose& theRobotPose)
{
  // fixMe: this is temporary
  theRobotPose.pose = theOdometry->pose;
}

MAKE_MODULE(SelfLocator)

