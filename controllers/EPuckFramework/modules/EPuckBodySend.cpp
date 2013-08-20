/*
 * EPuckBodySend.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#include "EPuckBodySend.h"

void EPuckBodySend::execute()
{
  // Set new speed
  EPuckFramework::getController().setSpeed(theMotionRequest->wheelSpeedRequest.left,
      theMotionRequest->wheelSpeedRequest.right);
}

MAKE_MODULE(EPuckBodySend)

