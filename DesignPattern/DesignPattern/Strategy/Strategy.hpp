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
        printf("\t���ǵ�һ��ʵ��\n");
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
        printf("\t���ǵڶ���ʵ��\n");
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
        printf("\t���ǵ�����ʵ��\n");
    }
};

#endif // _STRATEGY_HPP_