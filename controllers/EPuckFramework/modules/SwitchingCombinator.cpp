/*
 * SwitchingCombinator.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "SwitchingCombinator.h"

void SwitchingCombinator::update(UnicycleRequestOutput& theUnicycleRequestOutput)
{
  if (theGoToGoalUnicycleRequest->active)
  {
    theUnicycleRequestOutput.w = theGoToGoalUnicycleRequest->w;
    theUnicycleRequestOutput.v = theGoToGoalUnicycleRequest->v;
  }
  else if (theAvoidObstaclesUnicycleRequest->active)
  {
    theUnicycleRequestOutput.w = theAvoidObstaclesUnicycleRequest->w;
    theUnicycleRequestOutput.v = theAvoidObstaclesUnicycleRequest->v;
  }
  else
  {
    theUnicycleRequestOutput.w = 0.0f;
    theUnicycleRequestOutput.v = 0.0f;
  }
}

MAKE_MODULE(SwitchingCombinator)

