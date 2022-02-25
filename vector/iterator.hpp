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
struct vecIter
{
    typedef T           value_type;
    typedef Distance    difference_type;
    typedef Pointer     pointer;
    typedef Reference   reference;
    typedef Category    iterator_category;
private:
    pointer p;
public:
            /* Is default-constructible, copy-constructible, copy-assignable and destructible */
    vecIter() : p(nullptr) {};    

    vecIter(const vecIter& copy) : p(copy.p) {};

    vecIter &operator=(const vecIter& other) {
        if (this != &other)
            p = other.p;
        return *this;
    };

    virtual ~vecIter() {};

    
};

}
#endif