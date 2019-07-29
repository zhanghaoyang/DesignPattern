#ifndef _ADAPTER_HPP_
#define _ADAPTER_HPP_

#include <string>
#include "ITarget.hpp"
#include "Adaptee.hpp"

class Adapter : public ITarget
{
public:
    Adapter(Adaptee* adaptee)
    {
        adaptee_ = adaptee;
    }
    ~Adapter() {};

public:
    void adapteeMethod()
    {
        adaptee_->adapteeMethod();
    }

    void adapterMethod()
    {
        printf("\tAdapter method!\n");
    }
private:
    Adaptee* adaptee_;
};

#endif // _ADAPTER_HPP_