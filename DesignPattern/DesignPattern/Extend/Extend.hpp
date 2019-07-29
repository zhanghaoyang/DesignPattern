#ifndef _EXTEND_HPP_
#define _EXTEND_HPP_

#include <string>

// 此处为C语言的扩展性
// 继承性
typedef struct _parent
{
    int data_parent;
}Parent;

typedef struct _Child
{
    struct _parent parent;
    int data_child;
}Child;

// 封装性
struct _Data;
typedef void(*process)(struct _Data* pData);

typedef struct _Data
{
    int value;
    process pProcess;
}Data;

// 多态
typedef struct _Play
{
    void* pData;
    void(*start_play)(struct _Play* pPlay);
}Play;

class ClassLevel00
{
public:
    ClassLevel00()
    {
        name_ = "ClassLevel01";
    };

    ~ClassLevel00() {};

public:
    virtual void method() = 0;

protected:
    std::string name_;
};

class ClassLevel01 : public ClassLevel00
{
public:
    ClassLevel01()
    {
        name_ = "ClassLevel01";
    };

    ~ClassLevel01() {};

public:
    virtual void method()
    {
        printf("\tClassLevel01::method: %s\n", name_.c_str());
    }
};

class ClassLevel02 : public ClassLevel01
{
public:
    ClassLevel02()
    {
        name_ = "ClassLevel02";
    };

    ~ClassLevel02() {};

public:
    virtual void method() override
    {
        printf("\tClassLevel02::method: %s --------------- %s \n", name_.c_str(), text_.c_str());
    }

public:
    std::string text_;
};

void ProcData(Data* pData)
{
    for (int index = 0; index < 100; index++)
    {
        printf("\tDataProc: %03d - fuck you - %d\n", index, pData->value);
    }
}

void ProcPlay01(Play* pData)
{
    // dynamic_cast
    Parent* data = static_cast<Parent*>(pData->pData);
    for (int index = 0; index < 100; index++)
    {
        printf("\tProcPlay01: %03d - fuck you - %d\n", index, data->data_parent);
    }
}

void ProcPlay02(Play* pData)
{
    // dynamic_cast
    Child* data = static_cast<Child*>(pData->pData);
    for (int index = 0; index < 100; index++)
    {
        printf("\tProcPlay01: %03d - fuck you - %d - %d\n",
            index, data->parent.data_parent, data->data_child);
    }
}

int output(int p)
{
    printf("\touput: %d\n", p);
    return 0;
}

typedef int(*test_func)(int); // 定义函数指针test_func

class ClassA {
public:
    int m_a;
};

class ClassB {
public:
    int m_b;
};

class ClassC : public ClassA, public ClassB {};

#endif // _EXTEND_HPP_
