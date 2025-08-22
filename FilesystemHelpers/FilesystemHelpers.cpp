#include <FilesystemHelpers.hpp>

#include <StringHelpers.hpp>
#include <SystemHelpers.hpp>


bool FilesystemHelpers::IsFile (const char * path)
{
    return IsFile (String (path));
}


bool FilesystemHelpers::IsFile (String path)
{
    std::ifstream file;
    
    file.open (path);

    if (file.is_open())
    {
        file.close ();
        return true;
    }

    return false;
}


String FilesystemHelpers::MakePath (Args<String> pathParts)
{
    String sep = "";

    if (SysHelpers::InLinux ())
    {
        sep = "/";
    }
    else
    {
        sep = "\\";
    }

    String path = StringHelpers::Concat (pathParts, sep);
    return path;
}