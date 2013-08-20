/*
 * SensorData.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef SENSORDATA_H_
#define SENSORDATA_H_

#include <algorithm>
#include "kernel/Template.h"
#include "math/Vector3.h"

REPRESENTATION(SensorData)
class SensorData: public SensorDataBase
{
  public:

    enum
    {
      SENSOR_SIZE = 8
    };

    double lightValues[SENSOR_SIZE];
    double distanceValues[SENSOR_SIZE];
    Vector3<> acc;

    SensorData()
    {
      std::fill(lightValues, lightValues + SENSOR_SIZE, 0.0f);
      std::fill(lightValues, lightValues + SENSOR_SIZE, 0.0f);
    }

};

#endif /* SENSORDATA_H_ */
