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
      SENSOR_SIZE = 8
    };

    double values[SENSOR_SIZE];

    DistanceSensor()
    {
      std::fill(values, values + SENSOR_SIZE, 0.0f);
    }

};

#endif /* DISTANCESENSOR_H_ */
