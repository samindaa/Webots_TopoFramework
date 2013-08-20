/*
 * ProjectModule.h
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#ifndef PROJECTMODULE_H_
#define PROJECTMODULE_H_

#include "kernel/Template.h"
#include "representations/DistanceSensor.h"
#include "representations/MotionRequest.h"

MODULE(ProjectModule)
REQUIRES(DistanceSensor)
PROVIDES(MotionRequest)
END_MODULE

class ProjectModule: public ProjectModuleBase
{
  public:
    void update(MotionRequest& theMotionRequest);
};

#endif /* PROJECTMODULE_H_ */
