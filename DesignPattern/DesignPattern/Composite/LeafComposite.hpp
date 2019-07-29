#ifndef _LEAF_COMPOSITE_HPP_
#define _LEAF_COMPOSITE_HPP_

#include <string>
#include "IEmployer.hpp"
#include "DataDefine.h"

class Programmer : public IEmployer
{
public:
    Programmer(std::string name)
    {
        setName(name);
        employers_.clear(); // 程序员, 表示没有下属了
    }

    ~Programmer()
    {
        printf("\t~Programmer\n");
    };

public:
    virtual void Add(IEmployer* employer) override
    {

    }

    virtual void Del(IEmployer* employer) override
    {

    }
};

class ProjectAssistant : public IEmployer
{
public:
    ProjectAssistant(std::string name)
    {
        setName(name);
        employers_.clear(); // 项目助理, 表示没有下属了
    }

    ~ProjectAssistant() {};

public:
    virtual void Add(IEmployer* employer) override
    {

    }

    virtual void Del(IEmployer* employer) override
    {

    }
};

class ProjectManager : public IEmployer
{
public:
    ProjectManager(std::string name)
    {
        setName(name);
        employers_.clear(); // 项目经理, 表示没有下属了
    }

    ~ProjectManager() {};

public:
    virtual void Add(IEmployer* employer) override
    {
        employers_.push_back(employer);
    }

    virtual void Del(IEmployer* employer) override
    {
        std::list<IEmployer *>::iterator iter;
        for (auto it = employers_.begin(); it != employers_.end();)
        {
            if ((*it)->getName() == employer->getName())
            {
                IEmployer* data = *it;
                SafeDelete(data);
                it = employers_.erase(it);
            }
            it++;
        }
    }
};

#endif // _LEAF_COMPOSITE_HPP_