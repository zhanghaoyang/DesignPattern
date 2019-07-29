#ifndef _IANIMAL_FACTORY_HPP_
#define _IANIMAL_FACTORY_HPP_

#include <string>

class ICat
{
public:
    virtual ~ICat() {};

public:
    virtual void eat() = 0;

protected:
    std::string name_;
};

class IDog
{
public:
    virtual ~IDog() {}

public:
    virtual void eat() = 0;

protected:
    std::string name_;
};

class IAnimalFactory {
public:
    virtual ~IAnimalFactory() {};

public:
    virtual ICat* CreateCat(std::string name) = 0;
    virtual IDog* CreateDog(std::string name) = 0;

protected:
    ICat* cat_;
    IDog* dog_;
};

#endif // _IANIMAL_FACTORY_HPP_