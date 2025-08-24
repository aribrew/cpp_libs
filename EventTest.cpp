#include <Terminal.hpp>
#include <Event.hpp>
#include <EventListener.hpp>


class CatMeowEvent : public Event
{
    
};


class CatListener : public Listener
{
    protected:
        virtual void onCatMeow () = 0;
        
    public:
        void _Notify () override
        {
            onCatMeow ();
        }
};


CatMeowEvent meowEvent;

class Cat
{
    public:
        void Meow ()
        {
            cout << "Meooow!\n";
            meowEvent.Fire ();
        }
};


class Dog : public CatListener
{
    protected:
        void onCatMeow () override
        {
            cout << "Warf!\n";
        }
        
    public:
        Dog ()
        {
            meowEvent.Subscribe (this);
        }
};




int main()
{
    Cat cat;
    Dog dog;
    
    cat.Meow ();
    
    return 0;
}

