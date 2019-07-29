#ifndef _ANIMAL_BLACK_HPP_
#define _ANIMAL_BLACK_HPP_

#include <string>
#include "IAnimalFactory.hpp"

class CatBlack : public ICat
{
public:
    CatBlack(std::string name)
    {
        name_ = name;
    }

    ~CatBlack() {};

public:
    virtual void eat() override
    {
        printf("\tCatBlack [%s] eating...\n", name_.c_str());
    }
};

class DogBlack : public IDog
{
public:
    DogBlack(std::string name)
    {
        name_ = name;
    }

    ~DogBlack() {};

public:
    virtual void eat() override
    {
        printf("\tDogBlack [%s] eating...\n", name_.c_str());
    }
};


class AnimalFactoryBlack : public IAnimalFactory
{
public:
    AnimalFactoryBlack()
    {
        cat_ = nullptr;
        dog_ = nullptr;
    }

    ~AnimalFactoryBlack() {}

public:
    ICat* CreateCat(std::string name)
    {
        cat_ = new CatBlack(name);
        return cat_;
    }

    IDog* CreateDog(std::string name)
    {
        dog_ = new DogBlack(name);
        return dog_;
    }
};

#endif // _ANIMAL_BLACK_HPP_