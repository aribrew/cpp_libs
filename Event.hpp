#ifndef __EVENT__
#define __EVENT__

#include <List.hpp>

#include <EventListener.hpp>


/**
 * Base class for events.
 * Only listeners requiring no parameters can subscribe.
 */
class Event
{
    protected:
        List<Listener*> listeners;
        
    public:
        void Fire ()
        {
            for (Listener* listener : listeners)
            {
                listener->_Notify ();
            }
        }

        void Subscribe (Listener* listener)
        {
            listeners.push_back (listener);
        }
};


/**
 * Base class for events.
 * Only listeners requiring one parameter can subscribe.
 */
template <typename P1>
class Event1P
{
    protected:
        List< Listener1P<P1>* > listeners;
        
    public:
        void Fire (P1 p1)
        {
            for (Listener1P<P1>* listener : listeners)
            {
                listener->_Notify (p1);
            }
        }

        void Subscribe (Listener1P<P1>* listener)
        {
            listeners.push_back (listener);
        }
};


/**
 * Base class for events.
 * Only listeners requiring two parameters can subscribe.
 */
template <typename P1, typename P2>
class Event2P
{
    protected:
        List< Listener2P<P1, P2>* > listeners;
        
    public:
        void Fire (P1 p1, P2 p2)
        {
            for (Listener2P<P1, P2>* listener : listeners)
            {
                listener->_Notify (p1, p2);
            }
        }

        void Subscribe (Listener2P<P1, P2>* listener)
        {
            listeners.push_back (listener);
        }
};


/**
 * Base class for events.
 * Only listeners requiring three parameters can subscribe.
 */
template <typename P1, typename P2, typename P3>
class Event3P
{
    protected:
        List< Listener3P<P1, P2, P3>* > listeners;
        
    public:
        void Fire (P1 p1, P2 p2, P3 p3)
        {
            for (Listener3P<P1, P2, P3>* listener : listeners)
            {
                listener->_Notify (p1, p2, p3);
            }
        }

        void Subscribe (Listener3P<P1, P2, P3>* listener)
        {
            listeners.push_back (listener);
        }
};


/**
 * Base class for events.
 * Only listeners requiring four parameters can subscribe.
 */
template <typename P1, typename P2, typename P3, typename P4>
class Event4P
{
    protected:
        List< Listener4P<P1, P2, P3, P4>* > listeners;
        
    public:
        void Fire (P1 p1, P2 p2, P3 p3, P4 p4)
        {
            for (Listener4P<P1, P2, P3, P4>* listener : listeners)
            {
                listener->_Notify (p1, p2, p3, p4);
            }
        }

        void Subscribe (Listener4P<P1, P2, P3, P4>* listener)
        {
            listeners.push_back (listener);
        }
};


#endif