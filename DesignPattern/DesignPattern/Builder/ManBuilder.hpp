#ifndef _MAN_BUILDER_HPP_
#define _MAN_BUILDER_HPP_

#include <string>
#include "IPersonBuilder.hpp"

class Man : public IPerson
{
public:
    Man() {};
    ~Man() {};
};

class ManBuilder : public IPersonBuilder
{
public:
    ManBuilder()
    {
        person_ = new Man();
    };

    virtual ~ManBuilder() {};

public:
    virtual void buildBody() override
    {
        person_->setBody("建造男人的身体");
    }

    virtual void buildFoot() override
    {
        person_->setFoot("建造男人的脚");
    }

    virtual void buildHead() override
    {
        person_->setHead("建造男人的头");
    }

    virtual IPerson* buildPerson() override
    {
        return person_;
    }

private:
    IPerson* person_;
};


#endif // _MAN_BUILDER_HPP_