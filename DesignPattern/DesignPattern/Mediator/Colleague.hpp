#ifndef _COLLEAGUE_HPP_
#define _COLLEAGUE_HPP_

#include <string>

class Colleague
{
public:
    virtual ~Colleague() {};

public:
    virtual void action() = 0;

protected:
    std::string name_;
};

class ColleagueA : public Colleague
{
public:
    ColleagueA() {};
    virtual ~ColleagueA() {};

public:
    virtual void action() override
    {
        printf("\t普通员工努力工作\n");
    }
};

class ColleagueB : public Colleague
{
public:
    ColleagueB() {};
    virtual ~ColleagueB() {};

public:
    virtual void action() override
    {
        printf("\t前台注意了\n");
    }
};

#endif // _COLLEAGUE_HPP_