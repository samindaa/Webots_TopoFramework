/*
 * BehaviorOutput.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "kernel/Template.h"
#include "math/Pose2D.h"

REPRESENTATION(BehaviorOutput)
class BehaviorOutput: public BehaviorOutputBase
{
  public:
    Pose2D target; // This is the target that needs go to
};

