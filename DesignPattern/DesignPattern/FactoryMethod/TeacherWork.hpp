#ifndef _TEACHER_WORK_HPP_
#define _TEACHER_WORK_HPP_

#include <string>
#include "IWork.hpp"

class TeacherWork : public IWork
{
public:
    TeacherWork() {};
    ~TeacherWork() {};

public:
    virtual void doWork() override
    {
        printf("\tTeacherWork is working...\n");
    }
};

class TeacherWorkFactory : public IWorkFactory
{
public:
    TeacherWorkFactory() {};
    virtual ~TeacherWorkFactory() {};

public:
    virtual IWork* getWork() override
    {
        return new TeacherWork();
    }
};

#endif // _TEACHER_WORK_HPP_