#ifndef __EVENT_LISTENER__
#define __EVENT_LISTENER__

/**
 * The Listener classes suffixes refers to the parameters
 * that can be received:
 * 
 * - Listener cannot receive nothing.
 * - Listener1P can receive one parameter.
 * - Listener2P can receive two.
 * ...
 * - ListenerXP can receive X parameters.
 */

/**
 * Base class for listening events.
 * 
 * _Notify function is for internal use only (needs to be public
 * for being called by events).
 */
class Listener
{
    public:
        virtual void _Notify () {}
};


/**
 * Base class for listening events.
 * 
 * _Notify function is for internal use only (needs to be public
 * for being called by events).
 */
template <typename P1>
class Listener1P
{
    public:
        virtual void _Notify (P1 p1) {}
};


/**
 * Base class for listening events.
 * 
 * _Notify function is for internal use only (needs to be public
 * for being called by events).
 */
template <typename P1, typename P2>
class Listener2P
{
    public:
        virtual void _Notify (P1 p1, P2 p2) {}
};


/**
 * Base class for listening events.
 * 
 * _Notify function is for internal use only (needs to be public
 * for being called by events).
 */
template <typename P1, typename P2, typename P3>
class Listener3P
{
    public:
        virtual void _Notify (P1 p1, P2 p2, P3 p3) {}
};


/**
 * Base class for listening events.
 * 
 * _Notify function is for internal use only (needs to be public
 * for being called by events).
 */
template <typename P1, typename P2, typename P3, typename P4>
class Listener4P
{
    public:
        virtual void _Notify (P1 p1, P2 p2, P3 p3, P4 p4) {}
};


#endif