#include <ANSI.hpp>

const char* ANSI::Color::DEFAULT = "39";
const char* ANSI::Color::DEFAULT_BG = "49";

const char* ANSI::Color::BLACK = "30";
const char* ANSI::Color::BLACK_BG = "40";
const char* ANSI::Color::BRIGHT_BLACK = "90";
const char* ANSI::Color::BRIGHT_BLACK_BG = "100";

const char* ANSI::Color::RED = "31";
const char* ANSI::Color::RED_BG = "41";
const char* ANSI::Color::BRIGHT_RED = "91";
const char* ANSI::Color::BRIGHT_RED_BG = "101";

const char* ANSI::Color::GREEN = "32";
const char* ANSI::Color::GREEN_BG = "42";
const char* ANSI::Color::BRIGHT_GREEN = "92";
const char* ANSI::Color::BRIGHT_GREEN_BG = "102";

const char* ANSI::Color::YELLOW = "33";
const char* ANSI::Color::YELLOW_BG = "43";
const char* ANSI::Color::BRIGHT_YELLOW = "93";
const char* ANSI::Color::BRIGHT_YELLOW_BG = "103";

const char* ANSI::Color::BLUE = "34";
const char* ANSI::Color::BLUE_BG = "44";
const char* ANSI::Color::BRIGHT_BLUE = "94";
const char* ANSI::Color::BRIGHT_BLUE_BG = "104";

const char* ANSI::Color::MAGENTA = "35";
const char* ANSI::Color::MAGENTA_BG = "45";
const char* ANSI::Color::BRIGHT_MAGENTA = "95";
const char* ANSI::Color::BRIGHT_MAGENTA_BG = "105";

const char* ANSI::Color::CYAN = "36";
const char* ANSI::Color::CYAN_BG = "46";
const char* ANSI::Color::BRIGHT_CYAN = "96";
const char* ANSI::Color::BRIGHT_CYAN_BG = "106";

const char* ANSI::Color::WHITE = "37";
const char* ANSI::Color::WHITE_BG = "47";
const char* ANSI::Color::BRIGHT_WHITE = "97";
const char* ANSI::Color::BRIGHT_WHITE_BG = "107";

const char* ANSI::Style::DEFAULT = "0";
const char* ANSI::Style::BOLD = "1";
const char* ANSI::Style::UNDERLINE = "4";
const char* ANSI::Style::INVERTED = "7";


String ANSI::Format (const char* text, const char* fgcolor, 
                     const char* bgcolor, const char* style)
{
    String formattedString = "";

    formattedString += "\033[";
    formattedString += style;
    formattedString += ";";
    formattedString += bgcolor;
    formattedString += ";";
    formattedString += fgcolor;
    formattedString += "m";
    formattedString += text;
    formattedString += "\033[0m";

    return formattedString;
}













