/*
 * GoToGoal.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef GOTOGOAL_H_
#define GOTOGOAL_H_

#include "kernel/Template.h"
#include "representations/Specifications.h"
#include "representations/Odometry.h"
#include "representations/UnicycleRequest.h"

MODULE(GoToGoal)
  REQUIRES(Specifications)
  REQUIRES(Odometry)
  PROVIDES(UnicycleRequest)
END_MODULE
class GoToGoal: public GoToGoalBase
{
  private:
    double kp, ki, kd;
    double E_k, e_k_1;
  public:
    void init();
    void update(UnicycleRequest& theUnicycleRequest);
};


#endif /* GOTOGOAL_H_ */
