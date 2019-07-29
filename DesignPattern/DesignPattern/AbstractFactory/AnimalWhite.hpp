#ifndef _ANIMAL_WHITE_HPP_
#define _ANIMAL_WHITE_HPP_

#include <string>
#include "IAnimalFactory.hpp"

class CatWhite : public ICat
{
public:
    CatWhite(std::string name)
    {
        name_ = name;
    }

    ~CatWhite() {}

public:
    virtual void eat() override
    {
        printf("\tCatWhite [%s] eating...\n", name_.c_str());
    }
};

class DogWhite : public IDog
{
public:
    DogWhite(std::string name)
    {
        name_ = name;
    }

    ~DogWhite() {};

public:
    virtual void eat()
    {
        printf("\tDogWhite [%s] eating...\n", name_.c_str());
    }
};

class AnimalFactoryWhite : public IAnimalFactory
{
public:
    AnimalFactoryWhite()
    {
        cat_ = nullptr;
        dog_ = nullptr;
    }

    ~AnimalFactoryWhite() {}

public:
    ICat* CreateCat(std::string name)
    {
        cat_ = new CatWhite(name);
        return cat_;
    }

    IDog* CreateDog(std::string name)
    {
        dog_ = new DogWhite(name);
        return dog_;
    }
};

#endif // _ANIMAL_WHITE_HPP_