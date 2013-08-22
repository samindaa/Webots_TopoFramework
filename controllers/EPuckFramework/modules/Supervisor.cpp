/*
 * Supervisor.cpp
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */
#include "Supervisor.h"

void Supervisor::update(BehaviorOutput& theBehaviorOutput)
{
  // This is a simple supervisor behavior
  theBehaviorOutput.target.translation = Vector2<>(-0.4, 0);
  //theBehaviorOutput.target.translation = Vector2<>(0, 0);
}


MAKE_MODULE(Supervisor)
