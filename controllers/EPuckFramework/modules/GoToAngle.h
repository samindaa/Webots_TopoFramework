/*
 * GoToAngle.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef GOTOANGLE_H_
#define GOTOANGLE_H_

#include "kernel/Template.h"
#include "representations/Specifications.h"
#include "representations/Odometry.h"
#include "representations/BehaviorOutput.h"

MODULE(GoToAngle)
  REQUIRES(Specifications)
  REQUIRES(Odometry)
  PROVIDES(BehaviorOutput)
END_MODULE
class GoToAngle: public GoToAngleBase
{
  private:
    double kp, ki, kd;
    double E_k, e_k_1;
  public:
    void init();
    void update(BehaviorOutput& theBehaviorOutput);
};

#endif /* GOTOANGLE_H_ */
