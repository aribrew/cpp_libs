#ifndef __LIST_HELPERS__
#define __LIST_HELPERS__

#include <List.hpp>
#include <LangHelpers.hpp>

#ifndef __TYPES__
    template <typename Type>
    using List = std::vector<Type>;
#endif


class VectorHelpers
{
    public:
        /**
         * Returns a vector/list containing all the provided items.
         * The items must be provided between { and }.
         * Example: Pack<const char*> ({ "one", "two" })
         */
        template <typename ItemType>
        static List<ItemType> Pack (Args<ItemType> items)
        {
            List<ItemType> list;

            for (ItemType item : items)
            {
                list.push_back (item);
            }

            return list;
        }
};

using ListHelpers = VectorHelpers;

#endif
