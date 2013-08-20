/*
 * EPuckBodyProvider.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#include "EPuckBodyProvider.h"

void EPuckBodyProvider::init()
{
  // Enter here exit cleanup code
  for (int i = 0; i < DistanceSensor::DISTANCE_SENSOR_SIZE; i++)
  {
    std::stringstream ss;
    ss << "ps" << i;
    distanceSensorNames[i] = ss.str().c_str();
    distanceSensors[i] = EPuckFramework::getController().getDistanceSensor(distanceSensorNames[i]);
    distanceSensors[i]->enable(EPuckFramework::getController().getBasicTimeStep());
  }
}

void EPuckBodyProvider::update(DistanceSensor& theDistanceSensor)
{
  for (int i = 0; i < DistanceSensor::DISTANCE_SENSOR_SIZE; i++)
    theDistanceSensor.distanceSensorValues[i] = distanceSensors[i]->getValue();
}

MAKE_MODULE(EPuckBodyProvider)

