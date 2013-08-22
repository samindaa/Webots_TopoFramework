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

    if (theAvoidObstaclesUnicycleRequestOutput->active)
    {
      theUnicycleRequestOutput.w = theAvoidObstaclesUnicycleRequestOutput->w;
      theUnicycleRequestOutput.v = theAvoidObstaclesUnicycleRequestOutput->v;
    }

    if (!(theGoToGoalUnicycleRequestOutput->active || theAvoidObstaclesUnicycleRequestOutput->active))
    {
      theUnicycleRequestOutput.w = 0.0f;
      theUnicycleRequestOutput.v = 0.0f;
    }
  }
}

MAKE_MODULE(SwitchingCombinator)

