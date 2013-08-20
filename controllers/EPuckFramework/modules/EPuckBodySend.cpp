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
  EPuckFramework::getController().setSpeed(theWheelSpeed->dot.x, theWheelSpeed->dot.y);
}

MAKE_MODULE(EPuckBodySend)

