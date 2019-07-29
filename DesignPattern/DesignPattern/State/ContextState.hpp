#ifndef _CONTEXT_STATE_HPP_
#define _CONTEXT_STATE_HPP_

#include <string>
#include "State.hpp"

class ContextState
{
public:
    ContextState() {};
    virtual ~ContextState() {};

public:
    void setWeather(Weather* weather)
    {
        weather_ = weather;
    }

    Weather* getWeather()
    {
        return weather_;
    }

    std::string weatherMessage()
    {
        return weather_->getWeather();
    }

private:
    Weather* weather_;
};

#endif // _CONTEXT_STATE_HPP_
