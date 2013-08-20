/*
 * EPuckBodySend.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#include "EPuckBodySend.h"

void EPuckBodySend::execute()
{
  // Set new speeds
  EPuckFramework::getController().setSpeed(theWheelSpeedRequest->left, theWheelSpeedRequest->right);
}

MAKE_MODULE(EPuckBodySend)

