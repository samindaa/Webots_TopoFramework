/*
 * GoToGoal.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#include "GoToGoal.h"
#include "math/Vector2.h"

void GoToGoal::init()
{
  kp = 50.0f;
  ki = 0.0f;
  kd = 10.0f;
  E_k = 0.0f;
  e_k_1 = 0.0f;
}

void GoToGoal::update(GoToGoalUnicycleRequest& theUnicycleRequest)
{
  // fixME
  Vector2<> target(0.4, 0);

  const Vector2<> diff = target - theOdometry->pose.translation;
  theUnicycleRequest.active = true;
  if (diff.abs() < 0.01)
  {
    E_k = e_k_1 = 0.0f;
    theUnicycleRequest.w = theUnicycleRequest.v = 0.0f;
    theUnicycleRequest.active = false;
    return;
  }
  // Heading error
  double e_k = diff.angle() - theOdometry->pose.rotation;
  e_k = normalize(e_k);

  double e_p = e_k;
  double e_i = E_k + e_k * theSpecifications->timeStep;
  double e_d = (e_k - e_k_1) / theSpecifications->timeStep;

  // PID heading
  theUnicycleRequest.w = kp * e_p + ki * e_i + kd * e_d;
  theUnicycleRequest.v = std::max(std::min(30.0f / (abs(theUnicycleRequest.w) + 0.0001f), 6.0f),
      0.5f);

  E_k = e_i;
  e_k_1 = e_k;

  std::cout << theUnicycleRequest.v << " " << theUnicycleRequest.w << " | " << e_k << " " << e_d
      << " " << diff.abs() << std::endl;

}

MAKE_MODULE(GoToGoal)

