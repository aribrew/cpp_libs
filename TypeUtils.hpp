#ifndef __TYPE_UTILS__
#define __TYPE_UTILS__

#include <type_traits>


// Special class for testing types
template <typename This>
class Type
{
    public:
        // Returns if Other inherits from This type
        template <typename Base>
        static bool InheritsFrom ()
        {
            return std::is_base_of<Base,This>::value;
        }

        // Returns if This type is a pointer.
        // Intended for use with templated types.
        static bool IsPtr ()
        {
            return std::is_pointer<This>::value;
        }
};

#endif