#ifndef _EXPRESSION_HPP_
#define _EXPRESSION_HPP_

#include <string>
#include "Context.hpp"

class AdvanceExpression : public Expression
{
public:
    AdvanceExpression() {};
    virtual ~AdvanceExpression() {};

public:
    virtual void interpret(Context* ctx) override
    {
        printf("\t���Ǹ߼�������, ���ͣ� %s.\n", ctx->getContent().c_str());
    }
};

class SimpleExpression : public Expression
{
public:
    SimpleExpression() {};
    virtual ~SimpleExpression() {};

public:
    virtual void interpret(Context* ctx) override
    {
        printf("\t������ͨ������, ���ͣ� %s.\n", ctx->getContent().c_str());
    }
};

#endif // _EXPRESSION_HPP_