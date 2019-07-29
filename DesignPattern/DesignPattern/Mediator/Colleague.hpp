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
        printf("\t��ͨԱ��Ŭ������\n");
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
        printf("\tǰ̨ע����\n");
    }
};

#endif // _COLLEAGUE_HPP_