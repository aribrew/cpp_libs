#ifndef __FILESYSTEM_HELPERS__
#define __FILESYSTEM_HELPERS__

#include <fstream>

#include <String.hpp>
#include <LangHelpers.hpp>


class FilesystemHelpers
{
    public:
        static bool IsFile (const char * path);
        static bool IsFile (String path);
        static String MakePath (Args<String> pathParts);
};

using FSHelpers = FilesystemHelpers;

#endif












