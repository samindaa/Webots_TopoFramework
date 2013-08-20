/*
 * EPuckBodyProvider.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#include "EPuckBodyProvider.h"

EPuckBodyProvider::EPuckBodyProvider() :
    acc(0), conn(EPuckFramework::getController())
{
}

void EPuckBodyProvider::init()
{
  // Enter here exit cleanup code
  for (int i = 0; i < SensorData::SENSOR_SIZE; i++)
  {
    std::stringstream ss;
    ss << "ps" << i;
    distanceSensors[i] = conn.getDistanceSensor(ss.str().c_str());
    distanceSensors[i]->enable(conn.getBasicTimeStep());
  }

  for (int i = 0; i < SensorData::SENSOR_SIZE; i++)
  {
    std::stringstream ss;
    ss << "ls" << i;
    lightSensors[i] = conn.getLightSensor(ss.str().c_str());
    lightSensors[i]->enable(conn.getBasicTimeStep());
  }

  acc = conn.getAccelerometer("accelerometer");
  acc->enable(conn.getBasicTimeStep());
  conn.enableEncoders(conn.getBasicTimeStep());
}

void EPuckBodyProvider::update(SensorData& theSensorData)
{
  for (int i = 0; i < SensorData::SENSOR_SIZE; i++)
  {
    // [0.02->0.7)
    theSensorData.distanceValues[i] = distanceSensors[i]->getValue() / 4096.0f; // From doc
    theSensorData.lightValues[i] = lightSensors[i]->getValue();
  }

  const double* accValues = acc->getValues();
  theSensorData.acc = Vector3<>(accValues[0], accValues[1], accValues[2]);
  theSensorData.leftEncoder = conn.getLeftEncoder();
  theSensorData.rightEncoder = conn.getRightEncoder();
  theSensorData.leftSpeed = conn.getLeftSpeed();
  theSensorData.rightSpeed = conn.getRightSpeed();

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
    theSpecifications.maxSpeed = 1000.0f;
    theSpecifications.speedUnit = 0.00628; // rad/s
    theSpecifications.timeStep = conn.getBasicTimeStep() / 1000.0f; // s
  }
}

MAKE_MODULE(EPuckBodyProvider)

