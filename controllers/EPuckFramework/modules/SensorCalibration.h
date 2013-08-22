/*
 * SensorCalibration.h
 *
 *  Created on: Aug 21, 2013
 *      Author: sam
 */

#ifndef SENSORCALIBRATION_H_
#define SENSORCALIBRATION_H_

#include "kernel/Template.h"
#include "representations/Odometry.h"
#include "representations/SensorData.h"
#include "representations/Specifications.h"
#include "representations/UnicycleRequest.h"
#include <fstream>
#include <vector>

MODULE(SensorCalibration)
  REQUIRES(Odometry)
  REQUIRES(Specifications)
  REQUIRES(SensorData)
  PROVIDES(GenericUnicycleRequestOutput)
  PROVIDES(CalibratedSensorData)
END_MODULE

class SensorCalibration : public SensorCalibrationBase
{
  private:
    Pose2D objectPose;
    std::ofstream dataOfstream;
    bool sensorCalibrationActive;
    std::vector<double> coef;
    double stddev;
    double mean;
  public:
    SensorCalibration();
    ~SensorCalibration();
    void init();
    void update(GenericUnicycleRequestOutput& theGenericUnicycleRequestOutput);
    void update(CalibratedSensorData& theCalibratedSensorData);
};

#endif /* SENSORCALIBRATION_H_ */
