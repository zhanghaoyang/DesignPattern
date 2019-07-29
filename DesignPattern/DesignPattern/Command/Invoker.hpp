#ifndef _INVOKER_HPP_
#define _INVOKER_HPP_

#include <string>
#include "Command.hpp"

class Invoker
{
public:
    Invoker() {};
    virtual ~Invoker() {};

public:
    void setCommand(Command* command)
    {
        command_ = command;
    }

    void execute()
    {
        command_->execute();
    }
protected:
    Command* command_;
};

#endif // _INVOKER_HPP_