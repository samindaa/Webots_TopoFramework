/*
 * AvoidObstacles.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef AVOIDOBSTACLES_H_
#define AVOIDOBSTACLES_H_

class AvoidObstacles
{
    /**
     * const static double constantThetaDot(config.getValue("constantThetaDot", 300.0f));
     Vector2<> thetaDot(constantThetaDot, constantThetaDot); // (left, right)

     // Simple avoid obstacle behavior
     // detect obsctacles
     bool leftObstacle = theSensorData->distanceValues[0] > 100.0
     || theSensorData->distanceValues[1] > 100.0 || theSensorData->distanceValues[2] > 100.0;
     bool rightObstacle = theSensorData->distanceValues[5] > 100.0
     || theSensorData->distanceValues[6] > 100.0 || theSensorData->distanceValues[7] > 100.0;

     if (leftObstacle)
     {
     // turn right
     thetaDot += Vector2<>(-constantThetaDot, constantThetaDot);
     }
     else if (rightObstacle)
     {
     // turn left
     thetaDot += Vector2<>(constantThetaDot, -constantThetaDot);
     }

     theMotionRequest.wheelSpeedRequest.left = thetaDot.x;
     theMotionRequest.wheelSpeedRequest.right = thetaDot.y;
     */
};

#endif /* AVOIDOBSTACLES_H_ */
