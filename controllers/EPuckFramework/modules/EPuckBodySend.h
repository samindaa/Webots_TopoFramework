/*
 * EPuckBodySend.h
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#ifndef EPUCKBODYSEND_H_
#define EPUCKBODYSEND_H_

#include "kernel/Template.h"
#include "EPuckFramework.h"
#include "representations/WheelSpeedRequest.h"

MODULE(EPuckBodySend)
  REQUIRES(WheelSpeedRequest)
END_MODULE

class EPuckBodySend: public EPuckBodySendBase
{
  public:
    void execute();
};

#endif /* EPUCKBODYSEND_H_ */
