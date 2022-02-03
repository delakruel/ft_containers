#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include <exception>
#include <limits>
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
		try {
			arr = this->alloc.allocate(cap);
			for (size_type i = 0; i < cap; ++i)
				this->alloc.construct((arr + i), value);
		} catch (std::bad_alloc &e) {
			std::cerr << e.what() << std::endl;
		}
	};
	// template< class InputIt > vector( InputIt first, InputIt last, const Allocator& alloc = Allocator());//5
	// vector( const vector& other );//6

	~vector() {

	};

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

	/*		Capacity		*/
	size_type size() const {
		return (sz);
	};
	size_type max_size() const {
		return (std::numeric_limits<difference_type>::max() / sizeof(value_type));
	};
	// void resize(size_type sz, T c = T()) {

	// };
	size_type capacity() const {
		return (cap);
	};
	bool empty() const {
		return (cap == 0);
	};
	void reserve(size_type new_cap) {
		if (new_cap <= cap)
			return ;
		if (new_cap > this->max_size())
			throw std::length_error("ft::vector lenght_error_exception");
		try {
			value_type* newArr = alloc.allocate(new_cap);
			for (size_type i = 0; i < sz; ++i) {
				alloc.construct(newArr + i, *(arr + i));
				alloc.destroy(arr + i);
			}
			alloc.deallocate(arr, cap);
			arr = newArr;
			cap = new_cap;
		} catch (std::bad_alloc &e) {
			std::cerr << e.what() << std::endl;
		}
	};

	/*		Element access		*/
	reference at(size_type pos) {
		if (pos >= sz || pos < 0)
			throw std::out_of_range("ft::vector out_of_range_exception");
		return *(arr + pos);
	};
	const_reference at(size_type pos) const {
		if (pos >= sz || pos < 0)
			throw std::out_of_range("ft::vector out_of_range_exception");
		return *(arr + pos);
	};
	//sega - eto norm, like a std::vector
	reference operator[](size_type pos) {
		return *(arr + pos);
	};
	const_reference operator[](size_type pos) const {
		return *(arr + pos);
	};

	reference front() {
		return *arr;
	};
	const_reference front() const {
		return *arr;
	};
	reference back() {
		return *(arr + sz - 1);
	};
	const_reference back() const {
		return *(arr + sz - 1);
	};

	/*		Modifiers		*/
	void push_back(const value_type& val) {
		try {
			if (cap == 0) {
				arr = alloc.allocate(1);
				alloc.construct(arr, val);
				++sz;
				++cap;
				return ;
			}
			if (sz < cap) {
				alloc.construct(arr + sz, val);
				++sz;
				return ;
			}
			value_type* newArr = alloc.allocate(cap * 2);
			for (size_type i = 0; i < sz; ++i) {
				alloc.construct(newArr + i, *(arr + i));
				alloc.destroy(arr + i);
			}
			alloc.construct(newArr + sz, val);
			alloc.deallocate(arr, cap);
			arr = newArr;
			++sz;
			cap *= 2;
		} catch (std::bad_alloc &e) {
			std::cerr << e.what() << std::endl;
		}
	};
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
	bool operator==(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);
template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);
template <class T, class Allocator>
	bool operator!=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);
template <class T, class Allocator>
	bool operator> (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);
template <class T, class Allocator>
	bool operator>=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);
template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);


		/*		Specialized algorighms		*/
template <class T, class Allocator>
	void swap(vector<T,Allocator>& lhs, vector<T,Allocator>& rhs);

}

#endif