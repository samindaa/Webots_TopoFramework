/*
 * SelfLocator.h
 *
 *  Created on: Aug 23, 2013
 *      Author: sam
 */

#ifndef SELFLOCATOR_H_
#define SELFLOCATOR_H_

#include "kernel/Template.h"
#include "representations/Odometry.h"
#include "representations/RobotPose.h"

MODULE(SelfLocator)
  REQUIRES(Odometry)
  PROVIDES(RobotPose)
END_MODULE

class SelfLocator : public SelfLocatorBase
{
  public:
    void update(RobotPose& theRobotPose);

};

#endif /* SELFLOCATOR_H_ */
