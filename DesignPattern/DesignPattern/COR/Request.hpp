#ifndef _REQUEST_HPP_
#define _REQUEST_HPP_

#include <string>

class Request
{
public:
    virtual ~Request() {};

protected:
    int request_;
};

class DimissionRequest : public Request
{
public:
    DimissionRequest() {};
    virtual ~DimissionRequest() {};
};

class AddMoneyRequest : public Request
{
public:
    AddMoneyRequest() {};
    virtual ~AddMoneyRequest() {};
};

class LeaveRequest : public Request
{
public:
    LeaveRequest() {};
    virtual ~LeaveRequest() {};
};

#endif // _REQUEST_HPP_