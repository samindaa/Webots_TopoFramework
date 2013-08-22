/*
 * Supervisor.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef SUPERVISOR_H_
#define SUPERVISOR_H_

#include "kernel/Template.h"
#include "representations/BehaviorOutput.h"

MODULE(Supervisor)
  PROVIDES(BehaviorOutput)
END_MODULE

class Supervisor: public SupervisorBase
{
  public:
    void update(BehaviorOutput& theBehaviorOutput);
};

#endif /* SUPERVISOR_H_ */
