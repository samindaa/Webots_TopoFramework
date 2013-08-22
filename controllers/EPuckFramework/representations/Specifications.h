/*
 * Specifications.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef SPECIFICATIONS_H_
#define SPECIFICATIONS_H_

#include "kernel/Template.h"
#include "math/Pose3D.h"

REPRESENTATION(Specifications)
class Specifications: public SpecificationsBase
{
  public:
    enum
    {
      SENSOR_SIZE = 8
    };

    double encoderResolution;
    double wheelRadius;
    double wheelBaseLength;
    double simulationStep;
    double maxSpeed;
    double speedUnit;
    double maxDistanceSensorResolution;
    bool initialized;

    Pose3D distanceSensorPoses[SENSOR_SIZE];

    Specifications() :
        encoderResolution(0), wheelRadius(0), wheelBaseLength(0), simulationStep(0), maxSpeed(0), speedUnit(
            0), maxDistanceSensorResolution(0), initialized(false)
    {
    }
};

#endif /* SPECIFICATIONS_H_ */
