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
        printf("\t这是高级解析器, 解释： %s.\n", ctx->getContent().c_str());
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
        printf("\t这是普通解析器, 解释： %s.\n", ctx->getContent().c_str());
    }
};

#endif // _EXPRESSION_HPP_