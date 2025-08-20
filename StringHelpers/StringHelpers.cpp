#include <StringHelpers.hpp>

#include <VectorHelpers.hpp>


bool StringHelpers::CStrEqualsTocStr (const char* cStr1, const char* cStr2)
{
    int result = strcmp (cStr1, cStr2);
    return (result == 0);
}


String StringHelpers::CStrToStr (char* c_string)
{
    return String (c_string);
}


String StringHelpers::Concat (Args<const char*> chunks)
{
    List<const char*> _chunks = ListFromArgs<const char*> (chunks);

    return Concat (_chunks, String (" "));
}


String StringHelpers::Concat (Args<const char*> chunks, const char* separator)
{
    List<const char*> _chunks = ListFromArgs<const char*> (chunks);
    
    return Concat (_chunks, String (separator));
}


String StringHelpers::Concat (List<const char*> chunks, const char* separator)
{
    return Concat (chunks, String (separator));
}


String StringHelpers::Concat (Args<const char*> chunks, String separator)
{
    List<const char*> _chunks = ListFromArgs<const char*> (chunks);

    return Concat (_chunks, separator);
}


String StringHelpers::Concat (List<const char*> chunks, String separator)
{
    List<String> _chunks;

    for (size_t c = 0; c < chunks.size(); c ++)
    {
        String _chunk (chunks[c]);

        _chunks.push_back (_chunk);
    }

    return Concat (_chunks, separator);
}


String StringHelpers::Concat (Args<String> chunks)
{
    List<String> _chunks = ListFromArgs<String> (chunks);

    return Concat (_chunks, String (" "));
}


String StringHelpers::Concat (Args<String> chunks, const char* separator)
{
    List<String> _chunks = ListFromArgs<String> (chunks);

    return Concat (_chunks, String (separator));
}


String StringHelpers::Concat (List<String> chunks, const char* separator)
{    
    return Concat (chunks, String (separator));
}


String StringHelpers::Concat (Args<String> chunks, String separator)
{    
    List<String> _chunks = ListFromArgs<String> (chunks);
    String _string = "";

    for (size_t c = 0; c < _chunks.size(); c ++)
    {
        _string += _chunks[c];

        if (c < (_chunks.size() - 1))
        {
            _string += separator;
        }
    }

    return _string;
}


String StringHelpers::Concat (List<String> chunks, String separator)
{
    //return Concat (chunks, separator.c_str());
    String str;
    std::stringstream sStream;

    for (size_t c = 0; c < chunks.size(); c ++)
    {
        String chunk = chunks[c];

        sStream << chunk;

        if (c < (chunks.size() - 1))
        {
            sStream << separator;
        }
    }

    str = sStream.str ();

    return str;
}


String StringHelpers::ConstCStrToStr (const char* c_string)
{
    return String (c_string);
}


String StringHelpers::BoolToStr (bool value)
{
    return std::to_string (value);
}


String StringHelpers::IntToStr (int value)
{
    return std::to_string (value);
}


String StringHelpers::FloatToStr (float value)
{
    return std::to_string (value);
}


bool StringHelpers::Has (const char* text, const char* chunk)
{
    return Has (String (text), String (chunk));
}


bool StringHelpers::Has (const char* text, String chunk)
{    
    return Has (String (text), chunk);
}


bool StringHelpers::Has (String text, String chunk)
{
    return (text.find (chunk) != String::npos);
}


bool StringHelpers::Has (String text, const char* chunk)
{
    return (text.find (chunk) != String::npos);
}


String StringHelpers::Replace (const char* text, 
                               const char* chunk, 
                               const char* newChunk)
{
    return Replace (String (text), String (chunk), String (newChunk));
}


String StringHelpers::Replace (String text, 
                               const char* chunk, 
                               const char* newChunk)
{
    return Replace (text, String (chunk), String (newChunk));
}


// Replaces the given chunk with the provided newChunk in text
String StringHelpers::Replace (String text,
                               String chunk,
                               String newChunk)
{
    String _text (text);

    int chunkPos = _text.find (chunk);

    if (chunkPos >= 0)
    {
        _text = _text.replace (chunkPos, chunk.size(), newChunk);
    }

    return _text;
}


String StringHelpers::ReplaceAll (const char* text,
                                  const char* chunk,
                                  const char* newChunk)
{
    String _text = String (text);

    while (Has (text, chunk))
    {
        _text = Replace (_text.c_str(), chunk, newChunk);
    }

    return _text;
}



String StringHelpers::ReplaceAll (const char* text,
                                  Args<const char *> chunks,
                                  Args<const char *> newChunks)
{
    List<const char*> _chunks = ListFromArgs (chunks);
    List<const char*> _newChunks = ListFromArgs (newChunks);

    return ReplaceAll (text, _chunks, _newChunks);
}


String StringHelpers::ReplaceAll (const char* text,
                                  List<const char *> chunks,
                                  List<const char *> newChunks)
{
    String _text = String (text);

    if (chunks.size() == newChunks.size())
    {
        for (size_t c = 0; c < chunks.size(); c ++)
        {
            if (Has (_text.c_str(), chunks[c]))
            {
                _text = Replace (_text.c_str(), chunks[c], newChunks[c]);
            }
        }
    }    

    return String (text);
}


List<const char*> StringHelpers::Split (const char* text)
{
    return Split (text, ' ');
}
    

List<const char*> StringHelpers::Split (const char* text, char delim)
{
    List<const char*> splittedStr;
    String _text = String (text);

    std::stringstream stream (_text);

    String buffer;

    while (std::getline (stream, buffer, delim))
    {
        splittedStr.push_back (buffer.c_str());
    }

    return splittedStr;
}


List<String> StringHelpers::Split (String text)
{
    return Split (text, ' ');
}


List<String> StringHelpers::Split (String text, char delim)
{
    List<String> splittedStr;

    std::stringstream stream (text);

    String buffer;

    while (std::getline (stream, buffer, delim))
    {
        splittedStr.push_back (buffer);
    }

    return splittedStr;
}






