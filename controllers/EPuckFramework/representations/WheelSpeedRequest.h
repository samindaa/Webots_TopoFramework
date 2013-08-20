/*
 * WheelSpeedRequest.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef WHEELSPEEDREQUEST_H_
#define WHEELSPEEDREQUEST_H_

#include "kernel/Template.h"

REPRESENTATION(WheelSpeedRequest)
class WheelSpeedRequest: public WheelSpeedRequestBase
{
  public:
    double left;
    double right;

    WheelSpeedRequest() :
        left(0), right(0)
    {
    }
};

#endif /* WHEELSPEEDREQUEST_H_ */
