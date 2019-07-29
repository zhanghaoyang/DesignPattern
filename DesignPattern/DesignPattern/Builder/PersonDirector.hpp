#ifndef _PERSON_DIRECTOR_HPP_
#define _PERSON_DIRECTOR_HPP_

#include <string>
#include "IPersonBuilder.hpp"

class PersonDirector
{
public:
    PersonDirector() {};
    virtual ~PersonDirector() {};

public:
    IPerson* constructPerson(IPersonBuilder* pb)
    {
        pb->buildHead();
        pb->buildBody();
        pb->buildFoot();
        return pb->buildPerson();
    }
};


#endif // _PERSON_DIRECTOR_HPP_