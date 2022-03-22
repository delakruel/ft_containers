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
    vecIter() : p(NULL) {};

    vecIter(const vecIter& copy) : p(copy.p) {};

    vecIter(const pointer poin) : p(poin) {};

    vecIter& operator =(const vecIter& other) {
        if (this != &other)
            p = other.p;
        return *this;
    };

    virtual ~vecIter() {};

            /* Can be compared for equivalence using the equality/inequality operators */
    bool operator ==(const vecIter& other) {
        return (p == other.p);
    }

    bool operator !=(const vecIter& other) {
        return (p != other.p);
    }

            /* Can be dereferenced as an rvalue (if in a dereferenceable state). */
    reference operator*() const {
        return (*p);
    }

    pointer operator->() const {
        return (p);
    }

            /* Can be incremented (if in a dereferenceable state). */
    vecIter& operator++() {
        ++p;
        return (*this);
    }

    vecIter operator++(int) {
        vecIter tmp = *this;
        ++p;
        return (tmp);
    }

            /* Can be decremented (if a dereferenceable iterator value precedes it). */
    vecIter& operator--() {
        --p;
        return (*this);
    }

    vecIter operator--(int) {
        vecIter tmp = *this;
        --p;
        return (tmp);
    }

            /* Supports the arithmetic operators + and - between an iterator and an integer value, or subtracting an iterator from another. */
    vecIter operator-(difference_type n) const {
        return vecIter(p - n);
    }

    vecIter operator+(difference_type n) const {
        return vecIter(p + n);
    }

    difference_type operator-(const vecIter& other) const {
        return (p - other.p);
    }

            /* Can be compared with inequality relational operators (<, >, <= and >=). */
    bool operator<(const vecIter& other) const {
        return (p < other.p);
    }

    bool operator>(const vecIter& other) const {
        return (p > other.p);
    }

    bool operator<=(const vecIter& other) const {
        return (p <= other.p);
    }

    bool operator>=(const vecIter& other) const {
        return (p >= other.p);
    }
            /* Supports compound assignment operations += and -= */
    vecIter& operator+=(difference_type n) {
        p += n;
        return (*this);
    }

    vecIter& operator-=(difference_type n) {
        p -= n;
        return (*this);
    }
            /* Supports the offset dereference operator ([]) */
    reference operator[](difference_type n) const {
        return (p[n]);
    }
};

}
#endif