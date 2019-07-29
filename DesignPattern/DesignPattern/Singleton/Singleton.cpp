#include "stdafx.h"
#include "Singleton.hpp"

Singleton::Singleton()
{
}


Singleton::~Singleton()
{
}

Singleton* Singleton::getInstance()
{
    static Singleton helper;
    return &helper;
}

void Singleton::Process(std::string text)
{
    printf("\tProcess: %s\n", text.c_str());
}
