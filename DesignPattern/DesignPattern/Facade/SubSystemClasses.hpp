#ifndef _SUB_SYSTEM_CLASSES_HPP_
#define _SUB_SYSTEM_CLASSES_HPP_

#include <string>

class ServiceA
{
public:
    virtual ~ServiceA() {};

public:
    virtual void methodA() = 0;
};

class ServiceB
{
public:
    virtual ~ServiceB() {};

public:
    virtual void methodB() = 0;
};

class ServiceC
{
public:
    virtual ~ServiceC() {};

public:
    virtual void methodC() = 0;
};

class ServiceAImpl : public ServiceA
{

public:
    virtual void methodA() override
    {
        printf("\t这是服务A\n");
    }
};


class ServiceBImpl : public ServiceB
{

public:
    virtual void methodB() override
    {
        printf("\t这是服务B\n");
    }
};


class ServiceCImpl : public ServiceC
{

public:
    virtual void methodC() override
    {
        printf("\t这是服务C\n");
    }
};

#endif // _SUB_SYSTEM_CLASSES_HPP_