#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

#include <string>

class Template
{
public:
    virtual ~Template() {};

public:
    virtual void print() = 0;
    void update()
    {
        printf("\t��ʼ��ӡ\n");
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
        printf("\t���������ʵ��\n");
    }

    void update()
    {
        printf("\t��ʼ��ӡ\n");
        for (int i = 0; i < 10; i++)
        {
            print();
        }
    }
};

#endif // _TEMPLATE_H_
