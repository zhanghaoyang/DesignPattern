#ifndef _STATE_HPP_
#define _STATE_HPP_

#include <string>

class Weather
{
public:
    virtual ~Weather() {};

public:
    virtual std::string getWeather() = 0;
};

class Rain : public Weather
{
public:
    Rain() {};
    virtual ~Rain() {};

public:
    virtual std::string getWeather() override
    {
        return "����";
    }
};

class Sunshine : public Weather
{
public:
    Sunshine() {};
    virtual ~Sunshine() {};

public:
    virtual std::string getWeather() override
    {
        return "����";
    }
};

#endif // _STATE_HPP_