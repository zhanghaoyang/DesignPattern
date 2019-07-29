#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>
#include <list>

class IPersonDec
{
public:
    virtual ~IPersonDec() {};

public:
    virtual void eat() = 0;
};

class ManDec : public IPersonDec
{
public:
    ManDec() {};
    virtual ~ManDec() {};

public:
    virtual void eat() override
    {
        printf("\tÄÐÈËÔÚ³Ô\n");
    }
};

#endif // _COMPONENT_HPP_