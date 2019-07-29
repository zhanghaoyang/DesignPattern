#ifndef _ADAPTEE_HPP_
#define _ADAPTEE_HPP_

#include <string>

class Adaptee
{
public:
    virtual ~Adaptee() {};

public:
    void adapteeMethod()
    {
        printf("\tAdaptee method!\n");
    }
};
#endif // _ADAPTEE_HPP_