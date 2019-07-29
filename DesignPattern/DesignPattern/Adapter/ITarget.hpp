#ifndef _ITARGET_HPP_
#define _ITARGET_HPP_

#include <string>

class ITarget
{
public:
    virtual ~ITarget() {};

public:
    virtual void adapteeMethod() = 0;
    virtual void adapterMethod() = 0;
};

#endif // _ITARGET_HPP_