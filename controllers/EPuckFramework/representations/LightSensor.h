/*
 * LightSensor.h
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#ifndef LIGHTSENSOR_H_
#define LIGHTSENSOR_H_

#include "kernel/Template.h"
#include <algorithm>

REPRESENTATION(LightSensor)
class LightSensor: public LightSensorBase
{
  public:
    enum
    {
      SENSOR_SIZE = 8
    };

    double values[SENSOR_SIZE];

    LightSensor()
    {
      std::fill(values, values + SENSOR_SIZE, 0.0f);
    }

};

#endif /* LIGHTSENSOR_H_ */
