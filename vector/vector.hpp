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
	typedef	T									value_type;
	typedef	Allocator							allocator_type;
	typedef	std::size_t							size_type;
	typedef	std::ptrdiff_t						difference_type;
	typedef	value_type&							reference;
	typedef	const value_type&					const_reference;
	typedef	typename Allocator::pointer			pointer;
	typedef	typename Allocator::const_pointer	const_pointer;
	//iterator
	//const_iterator
	//reverse_iterator
	//const_reverse_iterator
private:
	T*				arr;
	size_type		sz;
	size_type		cap;
	Allocator		alloc;
public:
	/*		Constructors, copy, destroy		*/
	explicit vector(const Allocator& alloc = Allocator()) : sz(0), cap(0), alloc(alloc) {};

	explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : sz(count), cap(count), alloc(alloc) {
		arr = this->alloc.allocate(count);
		for (size_type i = 0; i < count; ++i)
			this->alloc.construct((arr + i), value);
	};
	// template< class InputIt > vector( InputIt first, InputIt last, const Allocator& alloc = Allocator());//5
	// vector( const vector& other );//6

	~vector() {};

	vector<T,Allocator>& operator=(const vector<T,Allocator>& x);

	template <class InputIterator>
		void assign(InputIterator first, InputIterator last);

	void assign(size_type n, const T& u);

	allocator_type get_allocator() const;

	// /*		Iterators		*/
	// iterator begin();
	// const_iterator begin() const;
	// iterator end();
	// const_iterator end() const;
	// reverse_iterator rbegin();
	// const_reverse_iterator rbegin() const;
	// reverse_iterator rend();
	// const_reverse_iterator rend() const;

	// /*		Capacity		*/
	// size_type size() const;
	// size_type max_size() const;
	// void resize(size_type sz, T c = T());
	// size_type capacity() const;
	// bool empty() const;
	// void reserve(size_type n);

	/*		Element access		*/
	reference operator[](size_type n) {
		return *(arr + n);
	};
	const_reference operator[](size_type n) const {
		return *(arr + n);
	};
	reference at(size_type n) {
		if (n >= sz || n < 0)
			throw std::out_of_range();
		return *(arr + n);
	};
	const_reference at(size_type n) const {
		if (n >= sz || n < 0)
			throw std::out_of_range();
		return *(arr + n);
	};
	// reference front();
	// const_reference front() const;
	// reference back();
	// const_reference back() const;

	// /*		Modifiers		*/
	// void push_back(const T& x);
	// void pop_back();
	// iterator insert(iterator position, const T& x);
	// void insert(iterator position, size_type n, const T& x);
	// template <class InputIterator>
	// void insert(iterator position,
	// InputIterator first, InputIterator last);
	// iterator erase(iterator position);
	// iterator erase(iterator first, iterator last);
	// void swap(vector<T,Allocator>&);
	// void clear();
};

		/*		Operators		*/
template <class T, class Allocator>
	bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
	bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
	bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
	bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);


		/*		Specialized algorighms		*/
template <class T, class Allocator>
	void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);

}

#endif