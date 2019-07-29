#ifndef _IEMPLOYER_HPP_
#define _IEMPLOYER_HPP_

#include <string>
#include <list>

class IEmployer
{
public:
    virtual ~IEmployer() {};

public:
    void setName(std::string name)
    {
        name_ = name;
    }

    std::string getName()
    {
        return name_;
    }

    virtual void Add(IEmployer* employer) = 0;

    virtual void Del(IEmployer* employer) = 0;

    void printInfo()
    {
        printf("\t%s\n", name_.c_str());
    }

    std::list<IEmployer*> getEmployers()
    {
        return employers_;
    }

public:
    std::list<IEmployer*> employers_;

private:
    std::string name_;
};

#endif // _IEMPLOYER_HPP_