#ifndef __TIMER__
#define __TIMER__

#include <chrono>

using stopWatch = std::chrono::steady_clock;
using duration = std::chrono::duration<float>;
using moment = stopWatch::time_point;

#include <Event.hpp>
#include <EventListener.hpp>


class TimerListener : public Listener
{
    protected:
        virtual void onTimeout () = 0;
        
    public:
        void _Notify () override
        {
            onTimeout ();
        }
};


class TimerEvent : public Event
{

};


/**
 * A simple timer.
 * 
 * To be notified of when it reached timeout, you need to inherit from
 * TimerListener and implement 'onTimeout' function. You can then subscribe
 * to events.
 * 
 * Because the timer do not make use of threads, the way to make it advance
 * is using a infinite loop and calling its Update function/method there.
 */
class Timer
{
    private:
        float accumulator = 0.0f;
        float timeout = 1.0f;
        int currentLaps = 0;
        int totalLaps = 0;
        
        bool running = false;

        moment lastTime;
        moment now;

        TimerEvent onStop;
        TimerEvent onTimeout;

    public:
        Timer ();


        /**
         * Creates a new timer that will stop after X laps.
         * 
         * If laps == 0, it will last only one.
         * If laps == -1, it will last until stopped.
         */
        Timer (int laps);


        /**
         * Creates a new timer that will stop after the given timeout
         */
        Timer (float timeout);


        /**
         * Creates a new timer that will stop after X laps.
         * Each lap will last until the given timeout.
         * 
         * If laps == 0, it will last only one.
         * If laps == -1, it will last until stopped.
         */
        Timer (float timeout, int laps);


        ~Timer ();


        /**
         * Returns the current done laps
         */
        int CurrentLaps ();

        
        /**
         * Subscribe to the OnStop event
         */
        void OnStop (TimerListener* listener);


        /**
         * Subscribe to the OnTimeout event
         */
        void OnTimeout (TimerListener* listener);


        /**
         * Resets the timer accumulator and lap counter
         */
        void Reset ();


        /**
         * Check if the timer is running
         */
        bool Running ();


        /**
         * The timer will stop after the given timeout
         */
        void SetTimeout (float timeout);


        /**
         * Set the total laps to perform.
         * 
         * Each lap will last until the setted timeout (1 second by default).
         * 
         * If laps == 0, it will last only one.
         * If laps == -1, it will last until stopped.
         */
        void SetTotalLaps (int totalLaps);


        /**
         * Starts the timer
         */
        void Start ();


        /**
         * Stops the timer also resetting it
         */
        void Stop ();


        /**
         * Returns the total laps that the timer will perform
         */
        int TotalLaps ();


        /**
         * You must call this in your loop for the timer to advance
         */
        void Update ();
};

#endif