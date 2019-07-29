#ifndef _STUDENT_WORK_HPP_
#define _STUDENT_WORK_HPP_

#include <string>
#include "IWork.hpp"

class StudentWork : public IWork
{
public:
    StudentWork() {};
    ~StudentWork() {};

public:
    virtual void doWork() override
    {
        printf("\tStudentWork is working...\n");
    }
};

class StudentWorkFactory : public IWorkFactory
{
public:
    StudentWorkFactory() {};
    virtual ~StudentWorkFactory() {};

public:
    virtual IWork* getWork() override
    {
        return new StudentWork();
    }
};


#endif // _STUDENT_WORK_HPP_