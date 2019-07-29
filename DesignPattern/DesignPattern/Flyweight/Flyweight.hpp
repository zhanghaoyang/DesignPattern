#ifndef _FLYWEIGHT_HPP_
#define _FLYWEIGHT_HPP_

#include <string>
#include <map>

class Flyweight
{
public:
    virtual ~Flyweight() {};

public:
    virtual void action(int arg) = 0;
};

class FlyweightImpl : public Flyweight
{
public:
    FlyweightImpl() {};
    virtual ~FlyweightImpl() {};

public:
    virtual void action(int arg) override
    {
        // TODO Auto-generated method stub
        printf("\t²ÎÊýÖµ: %d\n", arg);
    }
};

class FlyweightFactory
{
public:
    FlyweightFactory() {};
    virtual ~FlyweightFactory() {};

public:
    static FlyweightFactory* Get()
    {
        static FlyweightFactory factory;
        return &factory;
    }

    Flyweight* getFlyweight(std::string key)
    {
        if (flyweights_.find(key) == flyweights_.end())
        {
            flyweights_.insert(std::make_pair(key, new FlyweightImpl()));
        }
        return flyweights_[key];
    }

    int getSize()
    {
        return flyweights_.size();
    }

private:
    std::map<std::string, Flyweight*> flyweights_;
};

#endif // _FLYWEIGHT_HPP_