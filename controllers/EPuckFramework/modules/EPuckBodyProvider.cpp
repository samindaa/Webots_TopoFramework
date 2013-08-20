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
  for (int i = 0; i < SensorData::SENSOR_SIZE; i++)
  {
    std::stringstream ss;
    ss << "ps" << i;
    distanceSensors[i] = EPuckFramework::getController().getDistanceSensor(ss.str().c_str());
    distanceSensors[i]->enable(EPuckFramework::getController().getBasicTimeStep());
  }

  for (int i = 0; i < SensorData::SENSOR_SIZE; i++)
  {
    std::stringstream ss;
    ss << "ls" << i;
    lightSensors[i] = EPuckFramework::getController().getLightSensor(ss.str().c_str());
    lightSensors[i]->enable(EPuckFramework::getController().getBasicTimeStep());
  }

  acc = EPuckFramework::getController().getAccelerometer("accelerometer");
  acc->enable(EPuckFramework::getController().getBasicTimeStep());

  EPuckFramework::getController().enableEncoders(
      EPuckFramework::getController().getBasicTimeStep());
}

void EPuckBodyProvider::update(SensorData& theSensorData)
{
  for (int i = 0; i < SensorData::SENSOR_SIZE; i++)
  {
    theSensorData.distanceValues[i] = distanceSensors[i]->getValue();
    theSensorData.lightValues[i] = lightSensors[i]->getValue();
  }

  const double* accValues = acc->getValues();
  theSensorData.acc = Vector3<>(accValues[0], accValues[1], accValues[2]);

  // We use the standard (x,y,z) right-hand coordinate system
  // where x-axis is front, y-axis is left, and z-axis is up
  //theSensorData.acc = RotationMatrix().rotateZ(M_PI_2) * theSensorData.acc;

  //std::cout << theSensorData.acc.x << " " << theSensorData.acc.y << " " << theSensorData.acc.z
  //    << std::endl;
}

void EPuckBodyProvider::update(Specifications& theSpecifications)
{
  if (!theSpecifications.initialized)
  {
    theSpecifications.initialized = true;
    theSpecifications.encoderResolution = 159.23f;
    theSpecifications.wheelRadius = 20.5f / 1000.0f;
    theSpecifications.wheelBaseLength = 52.0f / 1000.0f;
    theSpecifications.timeStep = EPuckFramework::getController().getBasicTimeStep() / 1000.0f; // s
  }
}

MAKE_MODULE(EPuckBodyProvider)

