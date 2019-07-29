#ifndef _VISITOR_HPP_
#define _VISITOR_HPP_

#include <string>
#include <list>
#include "Element.hpp"

class ConcreteVisitor : public Visitor
{
public:
    ConcreteVisitor() {};
    virtual ~ConcreteVisitor() {};

public:
    virtual void visitFloat(FloatElement* floatE) override
    {
        printf("\tvisitFloat: %.3f\n", floatE->getFe());
    }

    virtual void visitString(StringElement* stringE) override
    {
        printf("\tvisitString: %s\n", stringE->getSe().c_str());
    }

    virtual void visitCollection(std::list<Visitable*>& collection) override
    {
        for (auto& item : collection)
        {
            item->accept(this);
        }
    }
};

#endif // _VISITOR_HPP_
