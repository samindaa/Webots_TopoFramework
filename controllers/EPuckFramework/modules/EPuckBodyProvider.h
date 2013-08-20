/*
 * EPuckBodyProvider.h
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#ifndef EPUCKBODYPROVIDER_H_
#define EPUCKBODYPROVIDER_H_

#include "kernel/Template.h"
#include "EPuckFramework.h"
#include "math/Matrix.h"
#include "representations/SensorData.h"
#include "representations/Specifications.h"
#include <webots/DifferentialWheels.hpp>

MODULE(EPuckBodyProvider)
  PROVIDES(SensorData)
  PROVIDES(Specifications)
END_MODULE

class EPuckBodyProvider: public EPuckBodyProviderBase
{
  private:
    webots::DistanceSensor* distanceSensors[SensorData::SENSOR_SIZE];
    webots::LightSensor* lightSensors[SensorData::SENSOR_SIZE];
    webots::Accelerometer* acc;
  public:
    void init();
    void update(SensorData& theSensorData);
    void update(Specifications& theSpecifications);
};

#endif /* EPUCKBODYPROVIDER_H_ */
