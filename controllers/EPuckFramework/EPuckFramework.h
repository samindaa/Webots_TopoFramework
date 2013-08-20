/*
 * EPuckFramework.h
 *
 *  Created on: Aug 19, 2013
 *      Author: sam
 */

#ifndef EPUCKFRAMEWORK_H_
#define EPUCKFRAMEWORK_H_

#include <webots/DifferentialWheels.hpp>
#include "kernel/Framework.h"

class EPuckController: public webots::DifferentialWheels
{
  private:
    ime::Graph& graph;
  public:
    EPuckController();
    virtual ~EPuckController();

  public:
    void run();
};

class EPuckFramework
{
  private:
    EPuckFramework();
    ~EPuckFramework();

    EPuckFramework(EPuckFramework const& that);
    EPuckFramework& operator=(EPuckFramework const& that);

  public:
    static EPuckController& getConroller();

};

#endif /* EPUCKFRAMEWORK_H_ */
