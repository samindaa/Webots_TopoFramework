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
#include "representations/MotionRequest.h"

MODULE(DifferentialDrive)
  REQUIRES(Specifications)
  REQUIRES(UnicycleRequest)
  PROVIDES(MotionRequest)
END_MODULE
class DifferentialDrive: public DifferentialDriveBase
{
  public:
    void update(MotionRequest& theMotionRequest);
};

#endif /* DIFFERENTIALDRIVE_H_ */
