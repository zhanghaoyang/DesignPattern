#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include <string>
#include "Receiver.hpp"

class Command
{
public:
    Command(Receiver* receiver)
    {
        receiver_ = receiver;
    }

    virtual ~Command() {};

public:
    virtual void execute() = 0;

protected:
    Receiver* receiver_;
};

class CommandImpl : public Command
{
public:
    CommandImpl(Receiver* receiver) : Command(receiver)
    {
    }

    virtual ~CommandImpl() {};

public:
    virtual void execute() override
    {
        receiver_->request();
    }
};

#endif // _COMMAND_HPP_