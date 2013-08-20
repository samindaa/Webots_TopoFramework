/*
 * Odometry.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef ODOMETRY_H_
#define ODOMETRY_H_

#include "kernel/Template.h"
#include "math/Pose2D.h"
#include "math/Pose3D.h"

REPRESENTATION(Odometry)

class Odometry: public OdometryBase
{
  public:

    Odometry() :
        pose(0, 0, 0)
    {
    }

    Pose2D pose;

    /** Draws the 2d pose. */
    void draw() const
    {
      drawing.pose("Odometry", pose, 0.18, 1, 0,0,0);
    }

};


#endif /* ODOMETRY_H_ */
