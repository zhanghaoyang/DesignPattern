#ifndef _ORIGINATOR_HPP_
#define _ORIGINATOR_HPP_

#include <string>
#include "Memento.hpp"

class Originator
{
public:
    Originator() {};
    virtual ~Originator() {};

public:
    std::string getState()
    {
        return state_;
    }

    void setState(std::string state)
    {
        state_ = state;
    }

    Memento* createMemento()
    {
        return new Memento(state_);
    }

    void setMemento(Memento* memento)
    {
        state_ = memento->getState();
    }

    void showState()
    {
        printf("\tshowState: %s\n", state_.c_str());
    }

protected:
    std::string state_;
};

#endif // _ORIGINATOR_HPP_
