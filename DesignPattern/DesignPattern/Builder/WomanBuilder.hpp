#ifndef _WOMAN_BUILDER_HPP_
#define _WOMAN_BUILDER_HPP_

#include <string>
#include "IPersonBuilder.hpp"

class Woman : public IPerson
{
public:
    Woman() {};
    ~Woman() {};
};

class WomanBuilder : public IPersonBuilder
{
public:
    WomanBuilder()
    {
        person_ = new Woman();
    };

    virtual ~WomanBuilder() {};

public:
    virtual void buildBody() override
    {
        person_->setBody("建造女人的身体");
    }

    virtual void buildFoot() override
    {
        person_->setFoot("建造女人的脚");
    }

    virtual void buildHead() override
    {
        person_->setHead("建造女人的头");
    }

    virtual IPerson* buildPerson() override
    {
        return person_;
    }

private:
    IPerson* person_;
};


#endif // _WOMAN_BUILDER_HPP_