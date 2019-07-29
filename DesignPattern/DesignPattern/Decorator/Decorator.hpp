#ifndef _DECORATOR_HPP_
#define _DECORATOR_HPP_

#include <string>
#include "Component.hpp"

class Decorator : public IPersonDec
{
public:
    Decorator()
    {
        person_ = nullptr;
    };

    ~Decorator() {};

public:
    virtual void eat() override
    {
        person_->eat();
    }

    void setPerson(IPersonDec* person)
    {
        person_ = person;
    }

protected:
    IPersonDec* person_;
};

class ManDecoratorA : public Decorator
{
public:
    ManDecoratorA() {};
    ~ManDecoratorA() {};

public:
    virtual void eat() override
    {
        __super::eat();
        reEat();
        printf("\tManDecoratorA类\n");
    }

    void reEat()
    {
        printf("\t再吃一顿饭\n");
    }

protected:
    IPersonDec* person_;
};

class ManDecoratorB : public Decorator
{
public:
    ManDecoratorB() {};
    ~ManDecoratorB() {};

public:
    virtual void eat() override
    {
        __super::eat();
        printf("\t===============\n");
        printf("\tManDecoratorB类\n");
    }

protected:
    IPersonDec* person_;
};

#endif // _DECORATOR_HPP_