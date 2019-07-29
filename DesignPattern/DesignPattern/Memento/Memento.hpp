#ifndef _MEMENTO_HPP_
#define _MEMENTO_HPP_

#include <string>

class Memento
{
public:
    Memento(std::string state)
    {
        state_ = state;
    }

    virtual ~Memento() {};

public:
    std::string getState()
    {
        return state_;
    }

    void setState(std::string state)
    {
        state_ = state;
    }

protected:
    std::string state_;
};

#endif // _MEMENTO_HPP_