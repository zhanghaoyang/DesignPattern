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
        person_->setBody("�������˵�����");
    }

    virtual void buildFoot() override
    {
        person_->setFoot("�������˵Ľ�");
    }

    virtual void buildHead() override
    {
        person_->setHead("�������˵�ͷ");
    }

    virtual IPerson* buildPerson() override
    {
        return person_;
    }

private:
    IPerson* person_;
};


#endif // _MAN_BUILDER_HPP_