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
  for (int i = 0; i < Specifications::SENSOR_SIZE; i++)
  {
    std::stringstream ss;
    ss << "ps" << i;
    distanceSensors[i] = conn.getDistanceSensor(ss.str().c_str());
    distanceSensors[i]->enable(conn.getBasicTimeStep());
  }

  for (int i = 0; i < Specifications::SENSOR_SIZE; i++)
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
  for (int i = 0; i < Specifications::SENSOR_SIZE; i++)
  {
    // [0.02->0.7)
    theSensorData.distanceValues[i] = distanceSensors[i]->getValue(); // From doc
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

    // poses
    theSpecifications.distanceSensorPoses[0].rotateZ(-M_PI_2).translate(0.010,  0.033,  -0.030).rotateZ(1.27);
    theSpecifications.distanceSensorPoses[1].rotateZ(-M_PI_2).translate(0.025,  0.033,  -0.022).rotateZ(0.77);
    theSpecifications.distanceSensorPoses[2].rotateZ(-M_PI_2).translate(0.031,  0.033,  0.00).rotateZ(0.00);
    theSpecifications.distanceSensorPoses[3].rotateZ(-M_PI_2).translate(0.015,  0.033,  0.030).rotateZ(5.21);
    theSpecifications.distanceSensorPoses[4].rotateZ(-M_PI_2).translate(-0.015, 0.033,  0.030).rotateZ(4.21);
    theSpecifications.distanceSensorPoses[5].rotateZ(-M_PI_2).translate(-0.031, 0.033,  0.00).rotateZ(3.14159);
    theSpecifications.distanceSensorPoses[6].rotateZ(-M_PI_2).translate(-0.025, 0.033,  -0.022).rotateZ(2.37);
    theSpecifications.distanceSensorPoses[7].rotateZ(-M_PI_2).translate(0.010,  0.033,  -0.030).rotateZ(1.87);
  }
}

MAKE_MODULE(EPuckBodyProvider)

