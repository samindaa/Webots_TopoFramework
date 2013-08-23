/*
 * EPuckBodyProvider.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#include "EPuckBodyProvider.h"

EPuckBodyProvider::EPuckBodyProvider() :
    acc(0), conn(EPuckFramework::getController()), simulationStep(0)
{
}

void EPuckBodyProvider::init()
{
  // Simulation time
  simulationStep = conn.getBasicTimeStep();
  // Enter here exit cleanup code
  for (int i = 0; i < Specifications::SENSOR_SIZE; i++)
  {
    std::stringstream ss;
    ss << "ps" << i;
    distanceSensors[i] = conn.getDistanceSensor(ss.str().c_str());
    distanceSensors[i]->enable(simulationStep);
  }

  for (int i = 0; i < Specifications::SENSOR_SIZE; i++)
  {
    std::stringstream ss;
    ss << "ls" << i;
    lightSensors[i] = conn.getLightSensor(ss.str().c_str());
    lightSensors[i]->enable(simulationStep);
  }

  acc = conn.getAccelerometer("accelerometer");
  acc->enable(simulationStep);
  conn.enableEncoders(simulationStep);
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

}

void EPuckBodyProvider::update(Specifications& theSpecifications)
{
  if (!theSpecifications.initialized)
  {
    theSpecifications.initialized = true;
    theSpecifications.encoderResolution = 159.23f;
    theSpecifications.wheelRadius = 20.5f / 1000.0f;
    theSpecifications.robotRadius = 37.0f / 1000.0f;
    theSpecifications.wheelBaseLength = 52.0f / 1000.0f;
    theSpecifications.maxSpeed = 1000.0f;
    theSpecifications.speedUnit = 0.00628; // rad/s
    theSpecifications.simulationStep = simulationStep / 1000.0f; // s (e.g., 32 ms)
    theSpecifications.maxDistanceSensorResolution = 4096.0f;

    // poses
    distanceSensorPose(theSpecifications.distanceSensorPoses[0], -17.0f,
        theSpecifications.robotRadius);
    distanceSensorPose(theSpecifications.distanceSensorPoses[1], -45.0f,
        theSpecifications.robotRadius);
    distanceSensorPose(theSpecifications.distanceSensorPoses[2], -90.0f,
        theSpecifications.robotRadius);
    distanceSensorPose(theSpecifications.distanceSensorPoses[3], -150.0f,
        theSpecifications.robotRadius);
    distanceSensorPose(theSpecifications.distanceSensorPoses[4], 150.0f,
        theSpecifications.robotRadius);
    distanceSensorPose(theSpecifications.distanceSensorPoses[5], 90.0f,
        theSpecifications.robotRadius);
    distanceSensorPose(theSpecifications.distanceSensorPoses[6], 45.0f,
        theSpecifications.robotRadius);
    distanceSensorPose(theSpecifications.distanceSensorPoses[7], 17.0f,
        theSpecifications.robotRadius);
  }
}

void EPuckBodyProvider::distanceSensorPose(Pose3D& pose, double zAngleDegree, double x)
{
  pose.rotateZ(zAngleDegree * M_PI / 180.0f);
  Pose3D sensor;
  sensor.translate(x, 0.0f, 0.0f);
  pose.conc(sensor);
}

MAKE_MODULE(EPuckBodyProvider)

