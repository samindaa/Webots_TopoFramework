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
  for (int i = 0; i < DistanceSensor::SENSOR_SIZE; i++)
  {
    std::stringstream ss;
    ss << "ps" << i;
    distanceSensors[i] = EPuckFramework::getController().getDistanceSensor(ss.str().c_str());
    distanceSensors[i]->enable(EPuckFramework::getController().getBasicTimeStep());
  }

  for (int i = 0; i < LightSensor::SENSOR_SIZE; i++)
  {
    std::stringstream ss;
    ss << "ls" << i;
    lightSensors[i] = EPuckFramework::getController().getLightSensor(ss.str().c_str());
    lightSensors[i]->enable(EPuckFramework::getController().getBasicTimeStep());
  }
}

void EPuckBodyProvider::update(DistanceSensor& theDistanceSensor)
{
  for (int i = 0; i < DistanceSensor::SENSOR_SIZE; i++)
    theDistanceSensor.values[i] = distanceSensors[i]->getValue();
}

void EPuckBodyProvider::update(LightSensor& theLightSensor)
{
  for (int i = 0; i < LightSensor::SENSOR_SIZE; i++)
    theLightSensor.values[i] = distanceSensors[i]->getValue();
}

MAKE_MODULE(EPuckBodyProvider)

