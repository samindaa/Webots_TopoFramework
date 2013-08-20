/*
 * MotionRequest.h
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#ifndef MOTIONREQUEST_H_
#define MOTIONREQUEST_H_

#include "kernel/Template.h"

REPRESENTATION(MotionRequest)
class MotionRequest: public MotionRequestBase
{
  public:
    class WheelSpeedRequest
    {
      public:
        double left;
        double right;

        WheelSpeedRequest() :
            left(0), right(0)
        {
        }
    };
    WheelSpeedRequest wheelSpeedRequest;
};

#endif /* MOTIONREQUEST_H_ */
