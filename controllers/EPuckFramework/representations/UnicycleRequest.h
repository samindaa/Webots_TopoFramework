/*
 * UnicycleRequest.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef UNICYCLEREQUEST_H_
#define UNICYCLEREQUEST_H_

#include "kernel/Template.h"

class UnicycleRequest
{
  public:
    double v;
    double w;
    bool active;
    UnicycleRequest() :
        v(0), w(0), active(false)
    {
    }
};

REPRESENTATION(GenericUnicycleRequestOutput)
class GenericUnicycleRequestOutput: public GenericUnicycleRequestOutputBase, public UnicycleRequest
{
};

REPRESENTATION(GoToGoalUnicycleRequestOutput)
class GoToGoalUnicycleRequestOutput: public GoToGoalUnicycleRequestOutputBase,
    public UnicycleRequest
{
};

REPRESENTATION(AvoidObstaclesUnicycleRequestOutput)
class AvoidObstaclesUnicycleRequestOutput: public AvoidObstaclesUnicycleRequestOutputBase,
    public UnicycleRequest
{
};

REPRESENTATION(UnicycleRequestOutput)
class UnicycleRequestOutput: public UnicycleRequestOutputBase, public UnicycleRequest
{
};

#endif /* UNICYCLEREQUEST_H_ */
