#ifndef __STRING_HELPERS__
#define __STRING_HELPERS__

#include <cstring>
#include <istream>
#include <iomanip>
#include <sstream>

#include <LangHelpers.hpp>
#include <List.hpp>
#include <String.hpp>


class StringHelpers
{
    public:
        // Compare 2 C strings
        static bool CStrEqualsTocStr (const char* cStr1, const char* cStr2);

        // Shortcut for crating a string from a C string (char*)
        static String CStrToStr (char* c_string);

        // Concatenates the given C strings using a space as separator
        static String Concat (Args<const char*> chunks);

        // Concatenates the given C strings using the given separator
        static String Concat (Args<const char*> chunks, const char* separator);

        // Concatenates the given C strings using the given separator
        static String Concat (List<const char*> chunks, const char* separator);

        // Concatenates the given C strings using the given separator
        static String Concat (Args<const char*> chunks, String separator);

        // Concatenates the given C strings using the given separator
        static String Concat (List<const char*> chunks, String separator);

        // Concatenates the given strings using a space as separator
        static String Concat (Args<String> chunks);

        // Concatenates the given strings using the given separator
        static String Concat (Args<String> chunks, const char* separator);

        // Concatenates the given strings using the given separator
        static String Concat (List<String> chunks, const char* separator);

        // Concatenates the given strings using the given separator
        static String Concat (Args<String> chunks, String separator);

        // Concatenates the given strings using the given separator
        static String Concat (List<String> chunks, String separator);

        // Shortcut for crating a string from a const C string (const char*)
        static String ConstCStrToStr (const char* c_string);

        // Shortcut for obtaining the string representation of an boolean value
        static String BoolToStr (bool value);

        // Shortcut for obtaining the string representation of an integer value
        static String IntToStr (int value);

        // Shortcut for obtaining the string representation of a float value
        static String FloatToStr (float value);

        // Returns if the given text has 'chunk' in it
        static bool Has (const char* text, const char* chunk);

        // Returns if the given text has 'chunk' in it
        static bool Has (const char* text, String chunk);

        // Returns if the given text has 'chunk' in it
        static bool Has (String text, String chunk);

        // Returns if the given text has 'chunk' in it
        static bool Has (String text, const char* chunk);

        // Replaces the given chunk with the provided newChunk in text
        static String Replace (const char* text, 
                               const char* chunk, 
                               const char* newChunk);

        // Replaces the given chunk with the provided newChunk in text
        static String Replace (String text, 
                               const char* chunk, 
                               const char* newChunk);

        // Replaces the given chunk with the provided newChunk in text
        static String Replace (String text,
                               String chunk,
                               String newChunk);

        // Replace all ocurrences of 'chunk' with the provided 'newChunk'
        static String ReplaceAll (const char* text,
                                  const char* chunk,
                                  const char* newChunk);        

        // Replaces the given chunks with the provided new chunks
        static String ReplaceAll (const char* text,
                                  Args<const char *> chunks,
                                  Args<const char *> newChunks);

        // Replaces the given chunks with the provided new chunks
        static String ReplaceAll (const char* text,
                                  List<const char *> chunks,
                                  List<const char *> newChunks);

        // Splits the given text (using a space as the delimiter)
        static List<const char*> Split (const char* text);
                                  
        // Splits the given text
        static List<const char*> Split (const char* text, char delim);

        // Splits the given text (using a space as the delimiter)
        static List<String> Split (String s);

        // Splits the given text
        static List<String> Split (String s, char delim);
};

#endif
