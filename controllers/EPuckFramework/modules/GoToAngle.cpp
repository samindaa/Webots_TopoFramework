/*
 * GoToAngle.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "GoToAngle.h"
#include "math/Vector2.h"

void GoToAngle::init()
{
  kp = 30.0f;
  ki = 0.0f;
  kd = 0.0f;
  E_k = 0.0f;
  e_k_1 = 0.0f;
}

void GoToAngle::update(BehaviorOutput& theBehaviorOutput)
{
  // fixME
  static const double v = 2.0f; //
  static const double theta_d = M_PI;

  // Heading error
  double e_k = theta_d - theOdometry->pose.rotation;
  e_k = atan2(sin(e_k), cos(e_k));

  double e_p = e_k;
  double e_i = E_k + e_k * theSpecifications->timeStep;
  double e_d = (e_k - e_k_1) / theSpecifications->timeStep;

  // PID heading
  theBehaviorOutput.unicycleRequest.w = kp * e_k + ki * e_i + kd * e_d;
  theBehaviorOutput.unicycleRequest.v = v;

  E_k = e_i;
  e_k_1 = e_k;

  std::cout << e_k << " " << e_d << " " << theBehaviorOutput.unicycleRequest.v << " "
      << theBehaviorOutput.unicycleRequest.w << std::endl;

}

MAKE_MODULE(GoToAngle)
