#ifndef _SINGLETON_HPP_
#define _SINGLETON_HPP_

#include <string>

class Singleton
{
public:
    Singleton();
    ~Singleton();

public:
    static Singleton* getInstance();

public:
    void Process(std::string text);
};
#endif // _SINGLETON_HPP_
