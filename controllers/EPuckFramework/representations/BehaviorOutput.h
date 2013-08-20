/*
 * BehaviorOutput.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef BEHAVIOROUTPUT_H_
#define BEHAVIOROUTPUT_H_

#include "kernel/Template.h"

REPRESENTATION(BehaviorOutput)
class BehaviorOutput: public BehaviorOutputBase
{
  public:
    class UnicycleRequest
    {
      public:
        double v;
        double w;
        UnicycleRequest() :
            v(0), w(0)
        {
        }
    };

    UnicycleRequest unicycleRequest;
};

#endif /* BEHAVIOROUTPUT_H_ */
