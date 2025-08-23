#include <iostream>

#include <ANSI.hpp>


int main ()
{
    std::string ansiTest = ANSI::Format ("Hello world!");

    std::cout << ansiTest << std::endl;
    
    return 0;
}
