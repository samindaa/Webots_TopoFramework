/*
 * AvoidObstacles.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "AvoidObstacles.h"
#include "math/Vector2.h"

void AvoidObstacles::init()
{
  kp = 50.0f;
  ki = 0.0f;
  kd = 10.0f;
  E_k = 0.0f;
  e_k_1 = 0.0f;

}

void AvoidObstacles::update(
    AvoidObstaclesUnicycleRequestOutput& theAvoidObstaclesUnicycleRequestOutput)
{

  static const double distT = 0.03f;
  theAvoidObstaclesUnicycleRequestOutput.w = theAvoidObstaclesUnicycleRequestOutput.v = 0.0f;
  theAvoidObstaclesUnicycleRequestOutput.active = false;
  // Activity check and sensor gains
  if (theCalibratedSensorData->distanceValues[0] < distT
      || theCalibratedSensorData->distanceValues[1] < distT
      || theCalibratedSensorData->distanceValues[7] < distT
      || theCalibratedSensorData->distanceValues[6] < distT)
  {
    double mySensorGains[Specifications::SENSOR_SIZE] =
    { 0, 0.1, 0.8, 1, 1, 0.8, 0.1, 0 };
    theAvoidObstaclesUnicycleRequestOutput.active = true;
    std::copy(mySensorGains, mySensorGains + Specifications::SENSOR_SIZE, sensorGains);
  }
  else if (theCalibratedSensorData->distanceValues[2] < distT)
  {
    double mySensorGains[Specifications::SENSOR_SIZE] =
    { 0, 0.0, 0.0, 0.0, 1, 1, 1, 1 };
    theAvoidObstaclesUnicycleRequestOutput.active = true;
    std::copy(mySensorGains, mySensorGains + Specifications::SENSOR_SIZE, sensorGains);
  }
  else if (theCalibratedSensorData->distanceValues[5] < distT)
  {
    double mySensorGains[Specifications::SENSOR_SIZE] =
    { 1, 1, 1, 1, 0, 0, 0, 0 };
    theAvoidObstaclesUnicycleRequestOutput.active = true;
    std::copy(mySensorGains, mySensorGains + Specifications::SENSOR_SIZE, sensorGains);
  }

  if (!theAvoidObstaclesUnicycleRequestOutput.active)
  {
    std::cout << "AvoidObstacles=" << theAvoidObstaclesUnicycleRequestOutput.active << std::endl;
    return;
  }
  obstacleAvoidanceVector = Vector2<>(0, 0);
  // Lets get the resultant vectors
  for (int i = 0; i < Specifications::SENSOR_SIZE; i++)
    obstacleAvoidanceVector += (theCalibratedSensorData->distanceVectors[i] * sensorGains[i]);

  // Heading error
  double e_k = obstacleAvoidanceVector.angle() - theRobotPose->pose.rotation;
  e_k = normalize(e_k);

  double e_p = e_k;
  double e_i = E_k + e_k * theSpecifications->simulationStep;
  double e_d = (e_k - e_k_1) / theSpecifications->simulationStep;

  // PID heading
  theAvoidObstaclesUnicycleRequestOutput.w = kp * e_p + ki * e_i + kd * e_d;
  theAvoidObstaclesUnicycleRequestOutput.v = 6.28
      / (std::log(abs(theAvoidObstaclesUnicycleRequestOutput.w) + 2.0f) + 1.0f);

  E_k = e_i;
  e_k_1 = e_k;

  std::cout << "AvoidObstacles=" << theAvoidObstaclesUnicycleRequestOutput.active << " | "
      << theAvoidObstaclesUnicycleRequestOutput.v << " " << theAvoidObstaclesUnicycleRequestOutput.w
      << " | " << e_k << " || " << (obstacleAvoidanceVector.angle() * 180.0 / M_PI) << " # "
      << obstacleAvoidanceVector.x << " " << obstacleAvoidanceVector.y << std::endl;

}

MAKE_MODULE(AvoidObstacles)

