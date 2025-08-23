#include <Log.hpp>

#include <StringHelpers.hpp>
#include <ANSI.hpp>


const char* Log::DEFAULT_DEBUG_TAG = "[DEBUG]";
const char* Log::DEFAULT_ERROR_TAG = "[ERROR]";
const char* Log::DEFAULT_INFO_TAG = "[INFO]";
const char* Log::DEFAULT_WARNING_TAG = "[WARNING]";


String Log::replacePlaceholders (const char* message, 
                                 Args<const char*> params)
{
    String _message = String (message);
    
    Args<const char*>::iterator it;
    int p = 0;

    for (it = params.begin(); it != params.end(); it ++)
    {
        String param = String (*it);
        const char* pStr = StringHelpers::IntToStr(p).c_str();

        String placeholder = StringHelpers::Concat ({
            "${", 
            pStr,
            "}"
        }, "");

        if (StringHelpers::Has (_message, placeholder))
        {
            _message = StringHelpers::Replace (_message,
                                               placeholder,
                                               param);
        }

        p ++;
    }

    return _message;
}


void Log::d (const char* message)
{
    std::cout << DEFAULT_DEBUG_TAG << " " << message << std::endl;
}


void Log::d (const char* message, Args<const char*> params)
{
    std::cout << DEFAULT_DEBUG_TAG << " ";
    std::cout << replacePlaceholders (message, params) << std::endl;
}


void Log::e (const char* error)
{
    String _tag = ANSI::Format (
        DEFAULT_ERROR_TAG,
        ANSI::Color::BRIGHT_RED
    );

    String _error = ANSI::Format (
        error,
        ANSI::Color::BRIGHT_RED
    );

    std::cerr << _tag << " " << _error << std::endl;
}


void Log::e (const char* error, Args<const char*> params)
{

    String _tag = ANSI::Format (
        DEFAULT_ERROR_TAG,
        ANSI::Color::BRIGHT_RED
    );

    String _error = ANSI::Format (
        error,
        ANSI::Color::BRIGHT_RED
    );

    std::cerr << _tag << " ";
    std::cerr << replacePlaceholders (error, params) << std::endl;
}


void Log::ec (const char* error, const char* cause)
{
    e (error);

    String _tag = ANSI::Format (
        "[CAUSE]: ",
        ANSI::Color::BRIGHT_RED
    );

    String _cause = ANSI::Format (
        cause,
        ANSI::Color::BRIGHT_RED
    );

    std::cerr << _tag << _cause << std::endl;
    std::cerr << std::endl;
}


void Log::ec (const char* error, Args<const char*> params, 
                                 const char* cause)
{
    e (error, params);

    String _tag = ANSI::Format (
        "[CAUSE]: ",
        ANSI::Color::BRIGHT_RED
    );

    String _cause = ANSI::Format (
        cause,
        ANSI::Color::BRIGHT_RED
    );

    std::cerr << _tag  << _cause << std::endl;
    std::cerr << std::endl;
}


void Log::i (const char* message)
{
    std::cout << DEFAULT_INFO_TAG << " " << message << std::endl;
}


void Log::i (const char* message, Args<const char*> params)
{
    std::cout << DEFAULT_INFO_TAG << " ";
    std::cout << replacePlaceholders (message, params) << std::endl;
}


void Log::w (const char* message)
{
    std::cout << DEFAULT_WARNING_TAG << " " << message << std::endl;
}


void Log::w (const char* message, Args<const char*> params)
{
    std::cout << DEFAULT_WARNING_TAG << " ";
    std::cout << replacePlaceholders (message, params) << std::endl;
}

