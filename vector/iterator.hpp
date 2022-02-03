#ifndef FT_VECTOR_ITERATOR_HPP
# define FT_VECTOR_ITERATOR_HPP

#include <cstddef>
#include "vector.hpp"

namespace ft
{

template<
	class Category,
    class T,
    class Distance = std::ptrdiff_t,
    class Pointer = T*,
    class Reference = T&>
struct iterator
{
    //typedef Category    std::random_access_iterator_tag;

};

}
#endif