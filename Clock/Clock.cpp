#include <Clock.hpp>

#include <Timer.hpp>


Clock::Clock ()
{
    timer = new Timer (tick, 1.0f, -1);
}


Clock::~Clock ()
{
    if (timer != nullptr)
    {
        delete timer;
    }
}


void Clock::Set (int hours, int minutes, int seconds)
{
    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
}


String Clock::Time ()
{
    String sHours = "";
    String sMinutes = "";
    String sSeconds = "";

    if (hours < 10)
    {
        sHours = "0";
    }

    if (minutes < 10)
    {
        sMinutes = "0";
    }

    if (seconds < 10)
    {
        sSeconds = "0";        
    }

    sHours += std::to_string (hours);
    sMinutes += std::to_string (minutes);
    sSeconds += std::to_string (seconds);

    return String (sHours + ":" + sMinutes + ":" + sSeconds);
}


void Clock::TurnOn ()
{

}


void Clock::TurnOff ()
{

}


void Clock::tick ()
{
    seconds ++;

    if (seconds == 60)
    {
        seconds = 0;
        minutes ++;
        
        if (minutes == 60)
        {
            minutes = 0;
            hours ++;

            if (hours == 24)
            {
                hours = 0;
            }
        }        
    }
}