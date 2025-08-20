#ifndef __LOG__
#define __LOG__

#include <String.hpp>
#include <LangHelpers.hpp>


class Log
{
    private:
        static const char* DEFAULT_DEBUG_TAG;
        static const char* DEFAULT_ERROR_TAG;
        static const char* DEFAULT_INFO_TAG;
        static const char* DEFAULT_WARNING_TAG;

        static String replacePlaceholders (const char* message, 
                                           Args<const char*> params);

    public:
        static void d (const char* message);
        static void d (const char* message, Args<const char*> params);

        static void e (const char* error);
        static void e (const char* error, Args<const char*> params);
        static void ec (const char* error, const char* cause);
        static void ec (const char* error, Args<const char*> params, 
                                           const char* cause);


        static void i (const char* message);
        static void i (const char* message, Args<const char*> params);

        static void w (const char* message);
        static void w (const char* message, Args<const char*> params);

};

#endif
