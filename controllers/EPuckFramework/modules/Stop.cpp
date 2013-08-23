/*
 * Stop.cpp
 *
 *  Created on: Aug 22, 2013
 *      Author: sam
 */

#include "Stop.h"

void Stop::update(StopUnicycleRequestOutput& theStopUnicycleRequestOutput)
{
  theStopUnicycleRequestOutput.active = false;
  if ((theBehaviorOutput->target.translation - theRobotPose->pose.translation).abs() < 0.02)
  {
    theStopUnicycleRequestOutput.w = theStopUnicycleRequestOutput.v = 0.0f;
    theStopUnicycleRequestOutput.active = true;
  }
}

MAKE_MODULE(Stop)

