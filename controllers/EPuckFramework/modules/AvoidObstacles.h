/*
 * AvoidObstacles.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef AVOIDOBSTACLES_H_
#define AVOIDOBSTACLES_H_

#include "kernel/Template.h"
#include "representations/Specifications.h"
#include "representations/RobotPose.h"
#include "representations/SensorData.h"
#include "representations/UnicycleRequest.h"

MODULE(AvoidObstacles)
  REQUIRES(Specifications)
  REQUIRES(RobotPose)
  REQUIRES(CalibratedSensorData)
  PROVIDES(AvoidObstaclesUnicycleRequestOutput)
END_MODULE
class AvoidObstacles: public AvoidObstaclesBase
{
  private:
    double kp, ki, kd;
    double E_k, e_k_1;
    Vector2<> obstacleAvoidanceVector;
  public:
    void init();
    void update(AvoidObstaclesUnicycleRequestOutput& theAvoidObstaclesUnicycleRequestOutput);
};

#endif /* AVOIDOBSTACLES_H_ */
