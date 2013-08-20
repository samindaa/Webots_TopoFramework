/*
 * DifferentialDrive.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef DIFFERENTIALDRIVE_H_
#define DIFFERENTIALDRIVE_H_

#include "kernel/Template.h"
#include "representations/Specifications.h"
#include "representations/UnicycleRequest.h"
#include "representations/WheelSpeedRequest.h"

MODULE(DifferentialDrive)
  REQUIRES(Specifications)
  REQUIRES(UnicycleRequestOutput)
  PROVIDES(WheelSpeedRequest)
END_MODULE
class DifferentialDrive: public DifferentialDriveBase
{
  public:
    void update(WheelSpeedRequest& theWheelSpeedRequest);
};

#endif /* DIFFERENTIALDRIVE_H_ */
