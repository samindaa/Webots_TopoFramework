/*
 * SensorCalibrator.cpp
 *
 *  Created on: Aug 21, 2013
 *      Author: sam
 */

#include "SensorCalibration.h"

SensorCalibration::SensorCalibration() :
    sensorCalibrationActive(false), stddev(0), mean(0)
{
}

SensorCalibration::~SensorCalibration()
{
  if (sensorCalibrationActive && dataOfstream.is_open())
    dataOfstream.close();
}

void SensorCalibration::init()
{

  sensorCalibrationActive = config.getValue("SensorCalibration.sensorCalibrationActive", false);
  if (sensorCalibrationActive)
  {
    dataOfstream.open(
        config.getValue("SensorCalibration.dataOfstream",
            std::string("mathlab/distanceRawSensorData.dat")).c_str(),
        std::ios::out | std::ios::app);
    objectPose = Pose2D(0.0f, 0.037f, 0.0f); // Webots
  }
  else
  {
    // After doing a regression: the coefficients are from 7 degree poly:
    mean = 369.9575;
    stddev = 553.8821;
    double pCoff[8] =
    { -0.000059414348363, 0.000982001155266, -0.006397453435698, 0.020910901891793,
        -0.036147452252582, 0.032641259943792, -0.018760730726124, 0.017248375332329 };
    coef.resize(8);
    for (int i = 0; i < 8; i++)
      coef[coef.size() - 1 - i] = pCoff[i]; // Reverse for easy computation
  }
}

void SensorCalibration::update(GenericUnicycleRequestOutput& theGenericUnicycleRequestOutput)
{
// Only for calibrate sensors
  theGenericUnicycleRequestOutput.active = sensorCalibrationActive;

  if (!theGenericUnicycleRequestOutput.active)
    return;

  static bool state = true; // binary state

  if (state)
  {
    theGenericUnicycleRequestOutput.v = -10.0f * theSpecifications->wheelRadius; // Go backward slowly
    theGenericUnicycleRequestOutput.w = 0.0f;

    if (theOdometry->pose.translation.abs() > 0.06)
      state = false;

    // Write the values of ps0 to disk
    if (dataOfstream.is_open())
    {
      const Pose2D diff = (objectPose - theOdometry->pose);
      Vector3<> pT(diff.translation.abs(),
          -diff.translation.abs() * std::tan(17.0f * M_PI / 180.0f), 0.0);
      Vector3<> pS = theSpecifications->distanceSensorPoses[0].invert() * pT;
      dataOfstream << theSensorData->distanceValues[0] << " " << pS.x << " " << pS.y << std::endl; // Apprx
      dataOfstream.flush();
    }
    else
    {
      std::cerr << "!is_open()" << std::endl;
    }
  }
  else
  {
    theGenericUnicycleRequestOutput.v = theGenericUnicycleRequestOutput.w = 0.0f;
  }
}

void SensorCalibration::update(CalibratedSensorData& theCalibratedSensorData)
{
  if (coef.size())
  {
    for (int i = 0; i < Specifications::SENSOR_SIZE; i++)
    {
      double x = (theSensorData->distanceValues[i] - mean) / stddev;
      double value = coef[0];
      for (unsigned int j = 1; j < coef.size(); j++)
      {
        value += coef[j] * std::pow(x, j);
      }
      theCalibratedSensorData.distanceValues[i] = value;

      // Calculate the distance vectors
      Vector3<> vec = theSpecifications->distanceSensorPoses[i] * Vector3<>(value, 0.0f, 0.0f);
      theCalibratedSensorData.distanceVectors[i] = Vector2<>(vec.x, vec.y);
      std::cout << i << " # ";
      std::cout << theCalibratedSensorData.distanceValues[i] << " | ";
      std::cout << "[x=" << theCalibratedSensorData.distanceVectors[i].x << " y="
          << theCalibratedSensorData.distanceVectors[i].y << "] " << std::endl;
    }
  }
}

MAKE_MODULE(SensorCalibration)
