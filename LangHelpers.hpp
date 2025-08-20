#ifndef __LANG_HELPERS__
#define __LANG_HELPERS__

#include <initializer_list>

#include <List.hpp>


// A variable list of args of the given type
template <typename ArgsType>
using Args = std::initializer_list<ArgsType>;


// Obtain a List (vector) from the params
template <typename Type>
List<Type> ListFromArgs (Args<Type> params)
{
    List<Type> list;

    typename Args<Type>::iterator it;

    for (it = params.begin(); it != params.end(); it ++)
    {
        list.push_back (*it);
    }

    return list;
}


#endif