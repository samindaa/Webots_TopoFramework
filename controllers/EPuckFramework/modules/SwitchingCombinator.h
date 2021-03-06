/*
 * SwitchingCombinator.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef SWITCHINGCOMBINATOR_H_
#define SWITCHINGCOMBINATOR_H_

#include "kernel/Template.h"
#include "representations/UnicycleRequest.h"
#include "representations/WheelSpeedRequest.h"
#include "representations/BehaviorOutput.h"

MODULE(SwitchingCombinator)
  REQUIRES(GenericUnicycleRequestOutput)
  REQUIRES(GoToGoalUnicycleRequestOutput)
  REQUIRES(AvoidObstaclesUnicycleRequestOutput)
  REQUIRES(StopUnicycleRequestOutput)
  REQUIRES(BehaviorOutput)
  PROVIDES(UnicycleRequestOutput)
END_MODULE
class SwitchingCombinator: public SwitchingCombinatorBase
{
  public:
    void update(UnicycleRequestOutput& theUnicycleRequestOutput);
};

#endif /* SWITCHINGCOMBINATOR_H_ */
