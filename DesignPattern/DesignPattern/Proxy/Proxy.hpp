#ifndef _PROXY_HPP_
#define _PROXY_HPP_

#include <string>
#include <map>

class Object
{
public:
    virtual ~Object() {};

public:
    virtual void action() = 0;
};

class ObjectImpl : public Object
{
public:
    ObjectImpl() {};
    virtual ~ObjectImpl() {};

public:
    virtual void action() override
    {
        printf("\tObjectImpl::action\n");
    }
};

class ProxyObject : public Object
{
public:
    ProxyObject()
    {
       printf("\t���Ǵ�����\n");
        obj_ = new ObjectImpl();
    }
    virtual ~ProxyObject() {};

public:
    void action() {
        printf("\t����ʼ\n");
        obj_->action();
        printf("\t�������\n");
    }

private:
    Object* obj_;
};

#endif // _PROXY_HPP_