/*
 * Stop.h
 *
 *  Created on: Aug 22, 2013
 *      Author: sam
 */

#ifndef STOP_H_
#define STOP_H_

#include "kernel/Template.h"
#include "representations/RobotPose.h"
#include "representations/BehaviorOutput.h"
#include "representations/UnicycleRequest.h"

MODULE(Stop)
  REQUIRES(RobotPose)
  REQUIRES(BehaviorOutput)
  PROVIDES(StopUnicycleRequestOutput)
END_MODULE
class Stop: public StopBase
{
  public:
    void update(StopUnicycleRequestOutput& theStopUnicycleRequestOutput);
};

#endif /* STOP_H_ */
