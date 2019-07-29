#ifndef _CONTEXT_HPP_
#define _CONTEXT_HPP_

#include <string>
#include <list>

class Context;
class Expression
{
public:
    virtual ~Expression() {};

public:
    virtual void interpret(Context* ctx) = 0;
};

class Context
{
public:
    Context(std::string content)
    {
        setContent(content);
    };

    virtual ~Context() {};

public:
    void setContent(std::string content)
    {
        content_ = content;
    }

    std::string getContent()
    {
        return content_;
    }

    void add(Expression* eps)
    {
        list_.push_back(eps);
    }

    std::list<Expression*> getList()
    {
        return list_;
    }

private:
    std::string content_;
    std::list<Expression*> list_;
};

#endif // _CONTEXT_HPP_