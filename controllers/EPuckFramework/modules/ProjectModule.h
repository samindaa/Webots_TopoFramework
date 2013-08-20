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
#include "representations/WheelSpeed.h"

MODULE(ProjectModule)
REQUIRES(DistanceSensor)
PROVIDES(WheelSpeed)
END_MODULE

class ProjectModule: public ProjectModuleBase
{
  public:
    void update(WheelSpeed& theWheelSpeed);
};

#endif /* PROJECTMODULE_H_ */
