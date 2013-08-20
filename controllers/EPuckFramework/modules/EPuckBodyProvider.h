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
#include "representations/DistanceSensor.h"
#include "representations/LightSensor.h"
#include <webots/DifferentialWheels.hpp>

MODULE(EPuckBodyProvider)
  PROVIDES(DistanceSensor)
  PROVIDES(LightSensor)
END_MODULE

class EPuckBodyProvider: public EPuckBodyProviderBase
{
  private:
    webots::DistanceSensor* distanceSensors[DistanceSensor::SENSOR_SIZE];
    webots::LightSensor* lightSensors[LightSensor::SENSOR_SIZE];
  public:
    void init();
    void update(DistanceSensor& theDistanceSensor);
    void update(LightSensor& theLightSensor);

};

#endif /* EPUCKBODYPROVIDER_H_ */
