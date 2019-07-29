#ifndef _STRATEGY_HPP_
#define _STRATEGY_HPP_

#include <string>

class Strategy
{
public:
    virtual ~Strategy() {};

public:
    virtual void method() = 0;
}; 

class StrategyImplA : public Strategy
{
public:
    StrategyImplA() {};
    virtual ~StrategyImplA() {};

public:
    virtual void method() override
    {
        printf("\t这是第一个实现\n");
    }
};

class StrategyImplB : public Strategy
{
public:
    StrategyImplB() {};
    virtual ~StrategyImplB() {};

public:
    virtual void method() override
    {
        printf("\t这是第二个实现\n");
    }
};

class StrategyImplC : public Strategy
{
public:
    StrategyImplC() {};
    virtual ~StrategyImplC() {};

public:
    virtual void method() override
    {
        printf("\t这是第三个实现\n");
    }
};

#endif // _STRATEGY_HPP_