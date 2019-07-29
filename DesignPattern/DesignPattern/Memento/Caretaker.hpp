#ifndef _CARETAKER_HPP_
#define _CARETAKER_HPP_

#include <string>
#include "Memento.hpp"

class Caretaker
{
public:
    Caretaker() {};
    virtual ~Caretaker() {};

public:
    Memento* getMemento()
    {
        return memento_;
    }

    void setMemento(Memento* memento)
    {
        memento_ = memento;
    }

protected:
    Memento* memento_;
};

#endif // _CARETAKER_HPP_
