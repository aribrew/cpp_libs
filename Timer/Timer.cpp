#include <Timer.hpp>


Timer::Timer ()
{

}


Timer::Timer (int laps)
{
    this->totalLaps = laps;
}


Timer::Timer (float timeout)
{
    this->timeout = timeout;
}


Timer::Timer (float timeout, int laps)
{
    this->timeout = timeout;
    this->totalLaps = laps;
}


Timer::~Timer ()
{

}


int Timer::CurrentLaps ()
{
    return currentLaps;
}


void Timer::OnStop (TimerListener* listener)
{
    onStop.Subscribe (listener);
}


void Timer::OnTimeout (TimerListener* listener)
{
    onTimeout.Subscribe (listener);
}


void Timer::Reset ()
{
    accumulator = 0.0f;
    currentLaps = 0;
}


bool Timer::Running ()
{
    return running;
}


void Timer::SetTimeout (float timeout)
{
    this->timeout = timeout;
}


void Timer::SetTotalLaps (int totalLaps)
{
    this->totalLaps = totalLaps;
}


void Timer::Start ()
{
    Reset ();

    running = true;
    lastTime = stopWatch::now();
}


void Timer::Stop ()
{
    running = false;
    onStop.Fire ();
}


int Timer::TotalLaps ()
{
    return totalLaps;
}


void Timer::Update ()
{
    if (running)
    {
        now = stopWatch::now ();
        duration deltaTime = (now - lastTime);
        lastTime = now;
        
        accumulator += deltaTime.count ();
        
        if (accumulator >= timeout)
        {
            accumulator = 0;
            onTimeout.Fire ();

            if (totalLaps == 0)
            {
                Stop ();
            }
            else if (totalLaps > 0)
            {
                currentLaps ++;
            
                if (currentLaps == totalLaps)
                {
                    Stop ();
                }
            }            
        }
    }
}