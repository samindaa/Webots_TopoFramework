/*
 * GoToGoal.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "GoToGoal.h"
#include "math/Vector2.h"
#include <cmath>

void GoToGoal::init()
{
  kp = 50.0f;
  ki = 0.0f;
  kd = 10.0f;
  E_k = 0.0f;
  e_k_1 = 0.0f;
}

void GoToGoal::update(GoToGoalUnicycleRequestOutput& theGoToGoalUnicycleRequestOutput)
{
  const Vector2<> diff = theBehaviorOutput->target.translation - theRobotPose->pose.translation;
  theGoToGoalUnicycleRequestOutput.active = true;
  theGoToGoalUnicycleRequestOutput.w = theGoToGoalUnicycleRequestOutput.v = 0.0f;

  // Heading error
  double e_k = diff.angle() - theRobotPose->pose.rotation;
  e_k = normalize(e_k);

  double e_p = e_k;
  double e_i = E_k + e_k * theSpecifications->simulationStep;
  double e_d = (e_k - e_k_1) / theSpecifications->simulationStep;

  // PID heading
  theGoToGoalUnicycleRequestOutput.w = kp * e_p + ki * e_i + kd * e_d;
  theGoToGoalUnicycleRequestOutput.v = 6.28
      / (std::log(abs(theGoToGoalUnicycleRequestOutput.w) + 2.0f) + 1.0f);

  E_k = e_i;
  e_k_1 = e_k;

  std::cout << "GoToGoal=" << theGoToGoalUnicycleRequestOutput.v << " "
      << theGoToGoalUnicycleRequestOutput.w << " | " << e_k << " " << e_d << " " << diff.abs()
      << std::endl;

}

MAKE_MODULE(GoToGoal)

