#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
//#include "iterator.hpp"

namespace ft
{

template <typename T, typename Allocator = std::allocator<T> >
class vector
{
public:
	typedef	T							value_type;
	typedef	Allocator					allocator_type;
	typedef	std::size_t					size_type;
	typedef	std::ptrdiff_t				difference_type;
	typedef	value_type&					reference;
	typedef	const value_type&			const_reference;
	//typedef	Allocator::pointer			pointer;
	//typedef	Allocator::const_pointer	const_pointer;
	//iterator
	//const_iterator
	//reverse_iterator
	//const_reverse_iterator
private:
	T*			arr;
	size_t		sz;
	size_t		cap;
	Allocator 	alloc;
public:
	/*		Constructors		*/
	vector() : sz(0), cap(0) {};

	// explicit vector( const Allocator& alloc ) : sz(0) {

	// };
	// explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator());
	// template< class InputIt > vector( InputIt first, InputIt last, const Allocator& alloc = Allocator());
	// vector( const vector& other );
	
	/*		Destructors			*/
	~vector() {};


};

}

#endif