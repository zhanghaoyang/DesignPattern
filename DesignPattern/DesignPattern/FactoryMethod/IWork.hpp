#ifndef _IWORK_HPP_
#define _IWORK_HPP_

#include <string>

class IWork
{
public:
    virtual ~IWork() {};

public:
    virtual void doWork() = 0;
};

class IWorkFactory
{
public:
    virtual ~IWorkFactory() {};

public:
    virtual IWork* getWork() = 0;
};


#endif // _IWORK_HPP_