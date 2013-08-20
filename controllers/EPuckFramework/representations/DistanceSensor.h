/*
 * DistanceSensor.h
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#ifndef DISTANCESENSOR_H_
#define DISTANCESENSOR_H_

#include "kernel/Template.h"
#include <algorithm>

REPRESENTATION(DistanceSensor)
class DistanceSensor: public DistanceSensorBase
{
  public:
    enum
    {
      DISTANCE_SENSOR_SIZE = 8
    };

    double distanceSensorValues[DISTANCE_SENSOR_SIZE];

    DistanceSensor()
    {
      std::fill(distanceSensorValues, distanceSensorValues + DISTANCE_SENSOR_SIZE, 0.0f);
    }

};

#endif /* DISTANCESENSOR_H_ */
