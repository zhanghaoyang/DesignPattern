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
        person_->setBody("����Ů�˵�����");
    }

    virtual void buildFoot() override
    {
        person_->setFoot("����Ů�˵Ľ�");
    }

    virtual void buildHead() override
    {
        person_->setHead("����Ů�˵�ͷ");
    }

    virtual IPerson* buildPerson() override
    {
        return person_;
    }

private:
    IPerson* person_;
};


#endif // _WOMAN_BUILDER_HPP_