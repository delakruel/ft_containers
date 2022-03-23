#ifndef UTILS_HPP
# define UTILS_HPP

#include <type_traits>

namespace ft
{
    template <class Iter>
    struct iterator_traits
    {
        typedef Iter::difference_type   difference_type;
        typedef Iter::value_type        value_type;
        typedef Iter::pointer           pointer;
        typedef Iter::reference         reference;
        typedef Iter::iterator_category iterator_category;
    };

    template <class T>
    struct iterator_traits<T*>
    {
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <bool B, class T = void>
    struct enable_if {};

    template <typename T>
    struct enable_if <true, T>
    {
        typedef T  type;
    };
    

    template <class T>  struct is_integral { static const bool value = false; };
    template <>         struct is_integral<bool> { static const bool value = true; };
}

#endif