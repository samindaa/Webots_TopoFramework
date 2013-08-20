/*
 * Specifications.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef SPECIFICATIONS_H_
#define SPECIFICATIONS_H_

#include "kernel/Template.h"

REPRESENTATION(Specifications)
class Specifications: public SpecificationsBase
{
  public:
    double encoderResolution;
    double wheelRadius;
    double wheelBaseLength;
    double timeStep;
    bool initialized;

    Specifications() :
        encoderResolution(0), wheelRadius(0), wheelBaseLength(0), timeStep(0), initialized(false)
    {
    }
};

#endif /* SPECIFICATIONS_H_ */
