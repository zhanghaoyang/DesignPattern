#ifndef _TEMPLATE_HPP_
#define _TEMPLATE_HPP_

#include <string>

class Template
{
public:
    virtual ~Template() {};

public:
    virtual void print() = 0;
    void update()
    {
        printf("\t开始打印\n");
        for (int i = 0; i < 10; i++)
        {
            printf("\tprint: %02d", i);
            print();
        }
    }
};

class TemplateConcrete : public Template
{
public:
    TemplateConcrete() {};
    virtual ~TemplateConcrete() {};

public:
    virtual void print() override
    {
        printf("\t这是子类的实现\n");
    }

    void update()
    {
        printf("\t开始打印\n");
        for (int i = 0; i < 10; i++)
        {
            print();
        }
    }
};

#endif // _TEMPLATE_HPP_
