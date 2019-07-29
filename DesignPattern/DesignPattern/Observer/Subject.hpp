#ifndef _SUBJECT_HPP_
#define _SUBJECT_HPP_

#include <string>
#include <list>

class Citizen;
class Policeman
{
public:
    virtual ~Policeman() {};

public:
    virtual void action(Citizen* ci) = 0;
    std::string Name()
    {
        return name_;
    }

private:
    std::string name_;
};

class Citizen
{
public:
    virtual ~Citizen() {};

public:
    void setHelp(std::string help)
    {
        help_ = help;
    }

    std::string getHelp()
    {
        return help_;
    }

    virtual void sendMessage(std::string help) = 0;

    void setPolicemen()
    {
        pols_.clear();
    }

    void RegisterPolice(Policeman* pol)
    {
        pols_.push_back(pol);
    }

    void UnRegisterPolice(Policeman* pol)
    {
        pols_.remove(pol);
    }

    std::string getName()
    {
        return name_;
    }

protected:
    std::list<Policeman*> pols_;
    std::string help_ = "normal";
    std::string name_;
};

class HuangPuCitizen : public Citizen
{
public:
    HuangPuCitizen()
    {
        setPolicemen();
        name_ = "HuangPuCitizen";
    }

    HuangPuCitizen(Policeman* pol)
    {
        setPolicemen();
        RegisterPolice(pol);
        name_ = "HuangPuCitizen";
    }

    virtual ~HuangPuCitizen() {};

public:
    virtual void sendMessage(std::string  help) override
    {
        setHelp(help);
        for (auto item : pols_)
        {
            // 通知警察行动
            item->action(this);
        }
    }
};

class TianHeCitizen : public Citizen
{
public:
    TianHeCitizen()
    {
        setPolicemen();
        name_ = "TianHeCitizen";
    }

    TianHeCitizen(Policeman* pol)
    {
        setPolicemen();
        RegisterPolice(pol);
        name_ = "TianHeCitizen";
    }

    virtual ~TianHeCitizen() {};

public:
    virtual void sendMessage(std::string  help) override
    {
        setHelp(help);
        for (auto item : pols_)
        {
            // 通知警察行动
            item->action(this);
        }
    }
};

#endif // _MEMENTO_HPP_