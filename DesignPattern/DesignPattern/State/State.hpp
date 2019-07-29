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
        return "ÏÂÓê";
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
        return "Ñô¹â";
    }
};

#endif // _STATE_HPP_