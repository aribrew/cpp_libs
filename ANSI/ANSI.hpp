#ifndef __ANSI_HELPERS__
#define __ANSI_HELPERS__

#ifndef __TYPES__
    #include <iostream>

    using String = std::string;
#endif


class ANSI
{
    public:
        class Color
        {
            public:
                static const char* DEFAULT;
                static const char* BLACK;
                static const char* RED;
                static const char* GREEN;
                static const char* YELLOW;
                static const char* BLUE;
                static const char* MAGENTA;
                static const char* CYAN;
                static const char* WHITE;

                static const char* BRIGHT_BLACK;
                static const char* BRIGHT_RED;
                static const char* BRIGHT_GREEN;
                static const char* BRIGHT_YELLOW;
                static const char* BRIGHT_BLUE;
                static const char* BRIGHT_MAGENTA;
                static const char* BRIGHT_CYAN;
                static const char* BRIGHT_WHITE;

                static const char* DEFAULT_BG;
                static const char* BLACK_BG;
                static const char* RED_BG;
                static const char* GREEN_BG;
                static const char* YELLOW_BG;
                static const char* BLUE_BG;
                static const char* MAGENTA_BG;
                static const char* CYAN_BG;
                static const char* WHITE_BG;

                static const char* BRIGHT_BLACK_BG;
                static const char* BRIGHT_RED_BG;
                static const char* BRIGHT_GREEN_BG;
                static const char* BRIGHT_YELLOW_BG;
                static const char* BRIGHT_BLUE_BG;
                static const char* BRIGHT_MAGENTA_BG;
                static const char* BRIGHT_CYAN_BG;
                static const char* BRIGHT_WHITE_BG;
        };

        class Style
        {
            public:
                static const char* DEFAULT;
                static const char* BOLD;
                static const char* UNDERLINE;
                static const char* INVERTED;
        };

        static String Format (const char* text, 
                              const char* fgcolor = Color::DEFAULT, 
                              const char* bgcolor = Color::DEFAULT_BG,
                              const char* style = Style::DEFAULT);

};

#endif