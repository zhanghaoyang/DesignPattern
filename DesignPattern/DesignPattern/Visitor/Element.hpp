#ifndef _ELEMENT_HPP_
#define _ELEMENT_HPP_

#include <string>
#include <list>

class FloatElement;
class StringElement;
class Visitable;
class Visitor
{
public:
    virtual ~Visitor() {};

public:
    virtual void visitFloat(FloatElement* floatE) = 0;
    virtual void visitString(StringElement* stringE) = 0;
    virtual void visitCollection(std::list<Visitable*>& collection) = 0;
};

class Visitable
{
public:
    virtual ~Visitable() {};

public:
    virtual void accept(Visitor* visitor) = 0;
};

class FloatElement : public Visitable
{
public:
    FloatElement(float fe)
    {
        fe_ = fe;
    };

    virtual ~FloatElement() {};

public:
    float getFe()
    {
        return fe_;
    }

    virtual void accept(Visitor* visitor) override
    {
        visitor->visitFloat(this);
    }

private:
    float fe_;
};

class StringElement : public Visitable
{
public:
    StringElement(std::string se)
    {
        se_ = se;
    };

    virtual ~StringElement() {};

public:
    std::string getSe()
    {
        return se_;
    }

    virtual void accept(Visitor* visitor) override
    {
        visitor->visitString(this);
    }

private:
    std::string se_;
};

#endif // _ELEMENT_HPP_
