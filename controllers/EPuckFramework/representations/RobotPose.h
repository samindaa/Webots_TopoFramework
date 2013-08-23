/*
 * RobotPose.h
 *
 *  Created on: Aug 23, 2013
 *      Author: sam
 */

#ifndef ROBOTPOSE_H_
#define ROBOTPOSE_H_

#include "kernel/Template.h"
#include "math/Pose2D.h"

REPRESENTATION(RobotPose)
class RobotPose: public RobotPoseBase
{
  public:
    Pose2D pose;
};

#endif /* ROBOTPOSE_H_ */
