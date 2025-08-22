#include <SystemHelpers.hpp>

#include <cstdlib>


String SystemHelpers::Env (const char* variableName)
{
    const char* variableValue = std::getenv (variableName);
    return String (variableValue);
}


String SystemHelpers::Env (String variableName)
{
    return Env (variableName.c_str());
}


bool SystemHelpers::InLinux ()
{
    #ifdef __linux__
        return true;
    #else
        return false;
    #endif
}


bool SystemHelpers::InWindows ()
{
    #ifdef _WIN32
        return true;
    #else
        return false;
    #endif
}