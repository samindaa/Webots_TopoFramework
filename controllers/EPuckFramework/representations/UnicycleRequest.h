/*
 * UnicycleRequest.h
 *
 *  Created on: Aug 20, 2013
 *      Author: sam
 */

#ifndef UNICYCLEREQUEST_H_
#define UNICYCLEREQUEST_H_

#include "kernel/Template.h"

REPRESENTATION(UnicycleRequest)
class UnicycleRequest : public UnicycleRequestBase
{
  public:
    double v;
    double w;
    UnicycleRequest() :
        v(0), w(0)
    {
    }
};

#endif /* UNICYCLEREQUEST_H_ */
