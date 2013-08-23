/*
 * SwitchingCombinator.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "SwitchingCombinator.h"

void SwitchingCombinator::update(UnicycleRequestOutput& theUnicycleRequestOutput)
{
  if (theGenericUnicycleRequestOutput->active)
  {
    theUnicycleRequestOutput.w = theGenericUnicycleRequestOutput->w;
    theUnicycleRequestOutput.v = theGenericUnicycleRequestOutput->v;
  }
  else
  {

    if (theGoToGoalUnicycleRequestOutput->active)
    {
      theUnicycleRequestOutput.w = theGoToGoalUnicycleRequestOutput->w;
      theUnicycleRequestOutput.v = theGoToGoalUnicycleRequestOutput->v;
    }

    // In switching logic highest priority is to avoid obstacle
    if (theAvoidObstaclesUnicycleRequestOutput->active)
    {
      theUnicycleRequestOutput.w = theAvoidObstaclesUnicycleRequestOutput->w;
      theUnicycleRequestOutput.v = theAvoidObstaclesUnicycleRequestOutput->v;
    }

    if (theStopUnicycleRequestOutput->active)
    {
      theUnicycleRequestOutput.w = theStopUnicycleRequestOutput->w;
      theUnicycleRequestOutput.v = theStopUnicycleRequestOutput->v;
    }

    if (!(theGoToGoalUnicycleRequestOutput->active || theAvoidObstaclesUnicycleRequestOutput->active
        || theStopUnicycleRequestOutput->active))
    {
      theUnicycleRequestOutput.w = 0.0f;
      theUnicycleRequestOutput.v = 0.0f;
    }
  }
}

MAKE_MODULE(SwitchingCombinator)

