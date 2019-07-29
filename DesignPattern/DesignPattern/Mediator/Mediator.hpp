#ifndef _MEDIATOR_HPP_
#define _MEDIATOR_HPP_

#include <string>
#include "Colleague.hpp"

class Mediator
{
public:
    virtual ~Mediator() {};

public:
    virtual void notice(std::string content) = 0;
};

class ConcreteMediator : public Mediator
{
public:
    ConcreteMediator()
    {
        ca = new ColleagueA();
        cb = new ColleagueB();
    };

    virtual ~ConcreteMediator() {};

public:
    virtual void notice(std::string content) override
    {
        if (content == "boss")
        {
            // 老板来了, 通知员工A
            ca->action();
        }

        if (content == "client")
        {
            // 客户来了, 通知前台B
            cb->action();
        }
    }

private:
    ColleagueA* ca;
    ColleagueB* cb;
};

#endif // _MEDIATOR_HPP_
