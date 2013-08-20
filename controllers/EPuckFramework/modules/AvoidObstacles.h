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
#include "representations/Odometry.h"
#include "representations/SensorData.h"
#include "representations/UnicycleRequest.h"

MODULE(AvoidObstacles)
  REQUIRES(Specifications)
  REQUIRES(Odometry)
  REQUIRES(SensorData)
  PROVIDES(AvoidObstaclesUnicycleRequest)
END_MODULE
class AvoidObstacles: public AvoidObstaclesBase
{
  public:
    void update(AvoidObstaclesUnicycleRequest& theUnicycleRequest);
};

#endif /* AVOIDOBSTACLES_H_ */
