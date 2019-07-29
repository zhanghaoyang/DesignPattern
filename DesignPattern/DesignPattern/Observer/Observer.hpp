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
        printf("\t%s反馈情况: %s\n", ci->getName().c_str(), help.c_str());
        if (help == "normal")
        {
           printf("\t一切正常, 不用出动\n");
        }

        if (help == "unnormal")
        {
            printf("\t有犯罪行为, 黄埔警察出动!\n");
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
        printf("\t%s反馈情况: %s\n", ci->getName().c_str(), help.c_str());
        if (help == "normal")
        {
            printf("\t一切正常, 不用出动\n");
        }

        if (help == "unnormal")
        {
            printf("\t有犯罪行为, 天河警察出动!\n");
        }
    }
};

#endif // _CARETAKER_HPP_
