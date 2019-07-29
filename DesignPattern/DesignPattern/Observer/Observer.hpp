#ifndef _OBSERVER_HPP_
#define _OBSERVER_HPP_

#include <string>
#include "Subject.hpp"

class HuangPuPoliceman : public Policeman
{
public:
    HuangPuPoliceman() {};
    virtual ~HuangPuPoliceman() {};

public:
    virtual void action(Citizen* ci) override
    {
        std::string help = ci->getHelp();
        printf("\t%s�������: %s\n", ci->getName().c_str(), help.c_str());
        if (help == "normal")
        {
           printf("\tһ������, ���ó���\n");
        }

        if (help == "unnormal")
        {
            printf("\t�з�����Ϊ, ���Ҿ������!\n");
        }
    }
};

class TianHePoliceman : public Policeman
{
public:
    TianHePoliceman() {};
    virtual ~TianHePoliceman() {};

public:
    virtual void action(Citizen* ci) override
    {
        std::string help = ci->getHelp();
        printf("\t%s�������: %s\n", ci->getName().c_str(), help.c_str());
        if (help == "normal")
        {
            printf("\tһ������, ���ó���\n");
        }

        if (help == "unnormal")
        {
            printf("\t�з�����Ϊ, ��Ӿ������!\n");
        }
    }
};

#endif // _CARETAKER_HPP_
