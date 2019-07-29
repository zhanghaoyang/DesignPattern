#ifndef _FACADE_HPP_
#define _FACADE_HPP_

#include <string>
#include "SubSystemClasses.hpp"

class Facade
{
public:
    Facade()
    {
        sa = new ServiceAImpl();
        sb = new ServiceBImpl();
        sc = new ServiceCImpl();
    };
    virtual ~Facade() {};

public:
    void methodA()
    {
        sa->methodA();
        sb->methodB();
    }

    void methodB()
    {
        sb->methodB();
        sc->methodC();
    }

    void methodC()
    {
        sc->methodC();
        sa->methodA();
    }

private:
    ServiceA* sa;
    ServiceB* sb;
    ServiceC* sc;
};

#endif // _FACADE_HPP_