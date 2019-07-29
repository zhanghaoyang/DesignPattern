#ifndef _RECEIVER_HPP_
#define _RECEIVER_HPP_

#include <string>

class Receiver
{
public:
    virtual ~Receiver() {};

public:
    void receive()
    {
        printf("\tThis is Receive class!\n");
    }

    void request()
    {
        printf("\tRequest command!\n");
    }
};

#endif // _RECEIVER_HPP_