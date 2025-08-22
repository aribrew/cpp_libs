#ifndef __SYSTEM_HELPERS__
#define __SYSTEM_HELPERS__

#ifndef __TYPES__
    #include <iostream>
    using String = std::string;
#endif


class SystemHelpers
{
    public:
        static String Env (const char* variableName);
        static String Env (String variableName);
        static bool InLinux ();
        static bool InWindows ();
};


using SysHelpers = SystemHelpers;

#endif