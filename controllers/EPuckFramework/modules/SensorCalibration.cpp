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
    mean = 368.1375;
    stddev = 552.4087;
    double pCoff[8] =
    { -0.000027347411026, 0.000584060458849, -0.004594040224285, 0.017425061555212,
        -0.033996936781986, 0.033624431690156, -0.019658687417516, 0.033776620646035 };
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
      const double sensorReading = diff.translation.abs() / std::cos(0.3)
          - theSpecifications->wheelRadius;
      dataOfstream << theSensorData->distanceValues[0] << " " << sensorReading << std::endl; // Apprx
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
      std::cout << theCalibratedSensorData.distanceValues[i] << " ";
    }
    std::cout << std::endl;
  }
}

MAKE_MODULE(SensorCalibration)
