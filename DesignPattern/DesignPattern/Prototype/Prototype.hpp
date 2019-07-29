#ifndef _PROTOTYPE_HPP_
#define _PROTOTYPE_HPP_

#include <string>

class Prototype
{
public:
    Prototype()
    {
        printf("\tname_: %s\n", name_.c_str());
    };

    virtual ~Prototype() {};

public:
    void setName(std::string name)
    {
        name_ = name;
    }

    std::string getName()
    {
        return name_;
    }

    Prototype* clone()
    {
        return new Prototype(*this);
    }

private:
    std::string name_;
};

class ConcretePrototype : public Prototype
{
public:
    ConcretePrototype(std::string name)
    {
        setName(name);
    }

    ~ConcretePrototype() {};
};

#endif // _PROTOTYPE_HPP_