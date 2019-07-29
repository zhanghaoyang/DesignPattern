#ifndef _HANDLER_HPP_
#define _HANDLER_HPP_

#include <string>
#include "Request.hpp"
#include <typeinfo>

class RequestHandle
{
public:
    virtual ~RequestHandle() {};

public:
    virtual void handleRequest(Request* request) = 0;
    bool IsDimissionRequest(Request* request)
    {
        DimissionRequest* req = dynamic_cast<DimissionRequest*>(request);
        return (nullptr != req);
    }

    bool IsAddMoneyRequest(Request* request)
    {
        AddMoneyRequest* req = dynamic_cast<AddMoneyRequest*>(request);
        return (nullptr != req);
    }

    bool IsLeaveRequest(Request* request)
    {
        LeaveRequest* req = dynamic_cast<LeaveRequest*>(request);
        return (nullptr != req);
    }

    bool IsDimissionRequestType(Request* request)
    {
        return (typeid(DimissionRequest) == typeid(*request));
    }

    bool IsAddMoneyRequestType(Request* request)
    {
        return (typeid(AddMoneyRequest) == typeid(*request));
    }

    bool IsLeaveRequestType(Request* request)
    {
        return (typeid(LeaveRequest) == typeid(*request));
    }
};

class HRRequestHandle : public RequestHandle
{
public:
    HRRequestHandle() {};
    virtual ~HRRequestHandle() {};

public:
    virtual void handleRequest(Request* request) override
    {
        printf("\t人事处理\n");
        if (IsDimissionRequestType(request))
        {
            printf("\t要离职, 人事审批!\n");
        }

        
        DimissionRequest req1;
        Request& req2 = req1;
        DimissionRequest& req3 = req1;
        const type_info& ti0 = typeid(DimissionRequest);
        const type_info& ti1 = typeid(req1);
        const type_info& ti2 = typeid(req2);
        const type_info& ti3 = typeid(req3);
        
        printf("\t请求完毕\n");
    }
};

class PMRequestHandle : public RequestHandle
{
public:
    PMRequestHandle(RequestHandle* rh)
    {
        rh_ = rh;
    }

    virtual ~PMRequestHandle() {};

public:
    virtual void handleRequest(Request* request) override
    {
        printf("\t项目经理处理\n");
        if (IsAddMoneyRequestType(request))
        {
            printf("\t要加薪, 项目经理审批!\n");
        }
        else
        {
            rh_->handleRequest(request);
        }
    }

private:
    RequestHandle* rh_;
};

class TLRequestHandle : public RequestHandle
{
public:
    TLRequestHandle(RequestHandle* rh)
    {
        rh_ = rh;
    }

    virtual ~TLRequestHandle() {};

public:
    virtual void handleRequest(Request* request) override
    {
        printf("\t项目组长处理\n");
        if (IsLeaveRequestType(request))
        {
            printf("\t要请假, 项目组长审批!\n");
        }
        else
        {
            rh_->handleRequest(request);
        }
    }

private:
    RequestHandle* rh_;
};

#endif // _HANDLER_HPP_