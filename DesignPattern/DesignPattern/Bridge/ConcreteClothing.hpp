#ifndef _CONCRETE_CLOTHING_HPP_
#define _CONCRETE_CLOTHING_HPP_

#include <string>
#include "Abstraction.hpp"

class Jacket : public IClothing
{
public:
    Jacket() {};
    virtual ~Jacket() {};

public:
    void personDressCloth(IPersonBridge* person)
    {
        printf("\t%s´©Âí¼×\n",person->getType().c_str());
    }
};

class Trouser : public IClothing
{
public:
    Trouser() {};
    virtual ~Trouser() {};

public:
    void personDressCloth(IPersonBridge* person)
    {
        printf("\t%s´©¿ã×Ó\n", person->getType().c_str());
    }
};


#endif // _CONCRETE_CLOTHING_HPP_