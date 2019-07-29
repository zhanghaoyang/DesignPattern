#ifndef _IPERSON_BUILDER_HPP_
#define _IPERSON_BUILDER_HPP_

#include <string>

class IPerson
{
public:
    virtual ~IPerson() {};

private:
    std::string head_;
    std::string body_;
    std::string foot_;

public:
    std::string getHead()
    {
        return head_;
    }

    void setHead(std::string head)
    {
        head_ = head;
    }

    std::string getBody()
    {
        return body_;
    }

    void setBody(std::string body)
    {
        body_ = body;
    }

    std::string getFoot()
    {
        return foot_;
    }

    void setFoot(std::string foot)
    {
        foot_ = foot;
    }
};

class IPersonBuilder
{
public:
    virtual ~IPersonBuilder() {};

public:
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildFoot() = 0;
    virtual IPerson* buildPerson() = 0;
};

#endif // _IPERSON_BUILDER_HPP_