/*
 * AccEvaluator.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef ACCEVALUATOR_H_
#define ACCEVALUATOR_H_

#include "kernel/Template.h"
#include "representations/Specifications.h"
#include "representations/SensorData.h"
#include "representations/Odometry.h"
#include <cmath>

MODULE(AccEvaluator)
  REQUIRES(Specifications)
  REQUIRES(SensorData)
  PROVIDES(Odometry)
END_MODULE

class AccEvaluator : public AccEvaluatorBase
{
  private:
    Pose2D pose;

  public:
    void update(Odometry& theOdometry);

};

#endif /* ACCEVALUATOR_H_ */
