#ifndef __CLOCK__
#define __CLOCK__

#ifndef __TYPES__
    #include <iostream>
    using String = std::string;
#endif


class Timer;


class Clock
{
    private:
        int seconds = 0;
        int minutes = 0;
        int hours = 0;

        Timer* timer = nullptr;

    public:
        Clock ();
        ~Clock ();

        void Set (int hours, int minutes, int seconds);
        String Time ();
        void TurnOn ();
        void TurnOff ();

    private:
        void tick ();
};

#endif