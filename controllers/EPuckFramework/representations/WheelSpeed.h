/*
 * WheelSpeed.h
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#ifndef WHEELSPEED_H_
#define WHEELSPEED_H_

#include "kernel/Template.h"
#include "math/Vector3.h"

REPRESENTATION(WheelSpeed)
class WheelSpeed: public WheelSpeedBase
{
  public:
    Vector3<> dot;
};

#endif /* WHEELSPEED_H_ */
