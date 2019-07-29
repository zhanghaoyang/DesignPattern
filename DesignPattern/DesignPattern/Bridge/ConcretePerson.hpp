#ifndef _CONCRETE_PERSON_HPP_
#define _CONCRETE_PERSON_HPP_

#include <string>
#include "Abstraction.hpp"

class ManBridge : public IPersonBridge
{
public:
    ManBridge()
    {
        setType("����");
    }

    ~ManBridge() {};

public:
    virtual void dress() override
    {
        IClothing* clothing = getClothing();
        clothing->personDressCloth(this);
    }
};

class LadyBridge : public IPersonBridge
{
public:
    LadyBridge()
    {
        setType("Ů��");
    }

    ~LadyBridge() {};

public:
    virtual void dress() override
    {
        IClothing* clothing = getClothing();
        clothing->personDressCloth(this);
    }
};

#endif // _CONCRETE_PERSON_HPP_