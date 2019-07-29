#ifndef _CONTEXT_STRATEGY_HPP_
#define _CONTEXT_STRATEGY_HPP_

#include <string>
#include "Strategy.hpp"

class ContextStrategy
{
public:
    ContextStrategy(Strategy* stra)
    {
        stra_ = stra;
    }

    virtual ~ContextStrategy() {};

public:
    void doMethod()
    {
        stra_->method();
    }

private:
    Strategy* stra_;
};

#endif // _CONTEXT_STRATEGY_HPP_
