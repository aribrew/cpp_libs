#include <Terminal.hpp>
#include <Timer.hpp>


Timer timer;


class Test : public TimerListener
{
    private:
        bool running = false;

        void onTimeout () override
        {
            cout << "Timer finished.\n";
            running = false;
        }

    public:
        Test ()
        {
            timer.OnTimeout (this);
        }

        void Run ()
        {
            running = true;
            timer.Start ();

            while (running)
            {
                timer.Update ();
            }
        }
};


int main ()
{
    Test test;
    test.Run ();   

    return 0;
}
