#ifndef _ABSTRACTION_HPP_
#define _ABSTRACTION_HPP_

#include <string>

class IClothing;
class IPersonBridge
{
public:
    virtual ~IPersonBridge() {};

public:
    IClothing* getClothing()
    {
        return clothing_;
    }

    void setClothing(IClothing* clothing)
    {
        clothing_ = clothing;
    }
    // void setClothing()
    // {
    //     clothing_ = ClothingFactory.getClothing();
    // }

    void setType(std::string type)
    {
        type_ = type;
    }

    std::string getType()
    {
        return type_;
    }

    virtual void dress() = 0;

private:
    IClothing* clothing_;
    std::string type_;
};

class IClothing
{
public:
    virtual ~IClothing() {};

public:
    virtual void personDressCloth(IPersonBridge* person) = 0;
};
#endif // _ABSTRACTION_HPP_