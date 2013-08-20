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
#include <webots/DifferentialWheels.hpp>

MODULE(EPuckBodyProvider)
  PROVIDES(DistanceSensor)
END_MODULE

class EPuckBodyProvider: public EPuckBodyProviderBase
{
  private:
    webots::DistanceSensor* distanceSensors[DistanceSensor::DISTANCE_SENSOR_SIZE];
    const char* distanceSensorNames[DistanceSensor::DISTANCE_SENSOR_SIZE];
  public:
    void init();
    void update(DistanceSensor& theDistanceSensor);

};

#endif /* EPUCKBODYPROVIDER_H_ */
