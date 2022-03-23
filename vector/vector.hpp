#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include <exception>
#include <limits>
#include "iterator.hpp"

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
	typedef	vecIter<std::random_access_iterator_tag, T>			iterator;
	typedef	vecIter<std::random_access_iterator_tag, const T>	const_iterator;
	// typedef	rVecIter<std::random_access_iterator_tag, T>		reverse_iterator;
	// typedef	rVecIter<std::random_access_iterator_tag, const T>	const_reverse_iterator;
private:
	T*				arr;
	size_type		sz;
	size_type		cap;
	Allocator		alloc;
public:
	/*		Constructors, copy, destroy		*/
	explicit vector(const Allocator& alloc = Allocator()) : sz(0), cap(0), alloc(alloc), arr(NULL) {
	};

	explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : sz(count), cap(count), alloc(alloc) {
		try {
			arr = this->alloc.allocate(cap);
			for (size_type i = 0; i < cap; ++i)
				this->alloc.construct((arr + i), value);
		} catch (std::bad_alloc &e) {
			std::cerr << e.what() << std::endl;
		}
	};

	template< class InputIt > 
	vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) {
		difference_type n = last - first;
		arr = this->alloc.allocate(n);
		sz = n;
		cap = n;
		for (size_type i = 0; i < n; ++i)
			this->alloc.construct((arr + i), *(first + i));
	};

	vector(const vector& copy) : alloc(copy.alloc), sz(copy.sz), cap(copy.cap) {
		try {
			arr = alloc.allocate(cap);
			for (size_type i = 0; i < sz; ++i)
				alloc.construct((arr + i), *(copy.arr + i));
		} catch (std::bad_alloc &e) {
			std::cerr << e.what() << std::endl;
		}
	};

	~vector() {
		if (sz)
			for (size_type i = 0; i < sz; ++i)
				alloc.destroy(arr + i);
		if (cap)
			alloc.deallocate(arr, cap);
	};

	vector<T,Allocator>& operator=(const vector<T,Allocator>& other) {
		if (this == &other)
			return (*this);
		try {
			if (sz)
				for (size_type i = 0; i < sz; ++i)
					alloc.destroy(arr + i);
			sz = other.sz;
			if (cap < other.cap) {
				if (cap)
					alloc.deallocate(arr, cap);
				cap = other.cap;
				if (cap)
					arr = alloc.allocate(cap);
			}
			for (size_type i = 0; i < sz; ++i)
				alloc.construct(arr + i, *(other.arr + i));
		} catch (std::bad_alloc &e) {
			std::cerr << e.what() << std::endl;
		}
		return (*this);
	};

	template <class InputIterator>
	void assign(InputIterator first, InputIterator last) {
		//////////////////////////////////
	};

	void assign(size_type count, const value_type& value) {
		if (sz)
			for (size_type i = 0; i < sz; ++i)
				alloc.destroy(arr + i);
		sz = count;
		if (cap >= count) {
			for (size_type i = 0; i < sz; ++i)
				alloc.construct(arr + i, value);
			return ;
		}
		try {
			if (cap)
				alloc.deallocate(arr, cap);
			cap = count;
			if (cap)
				arr = alloc.allocate(cap);
			for (size_type i = 0; i < sz; ++i)
				alloc.construct(arr + i, value);
		} catch (std::bad_alloc &e) {
			std::cout << e.what() << std::endl;
		}
	};

	allocator_type get_allocator() const {
		return (alloc);
	};

	// /*		Iterators		*/
	iterator begin() {
		return iterator(arr);
	};
	const_iterator begin() const {
		return const_iterator(arr);
	};
	iterator end() {
		return iterator (arr + sz);
	};
	const_iterator end() const {
		return const_iterator (arr + sz);
	};
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

	size_type capacity() const {
		return (cap);
	};

	bool empty() const {
		return (cap == 0);
	};

	void resize(size_type count, value_type value = value_type()) {
		if (sz == count)
			return ;
		if (sz > count) {
			for (size_type i = count; i < sz; ++i)
				alloc.destroy(arr + i);
			sz =- count;
			return ;
		}
		if (cap >= count) {
			for (size_type i = sz; i < count; ++i)
				alloc.construct(arr + i, value);
			sz = count;
			return ;
		}
		try {
			value_type* newArr = alloc.allocate(count);
			for (size_type i = 0; i < sz; ++i) {
				alloc.construct(newArr + i, *(arr + i));
				alloc.destroy(arr + i);
			}
			for (size_type i = sz; i < count; ++i)
				alloc.construct(newArr + i, value);
			if (cap)
				alloc.deallocate(arr, cap);
			arr = newArr;
		} catch (std::bad_alloc &e) {
			std::cerr << e.what() << std::endl;
		}
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
			if (cap)
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
		if (sz < cap) {
			alloc.construct(arr + sz, val);
			++sz;
			return ;
		}
		try {
			if (cap == 0) {
				arr = alloc.allocate(1);
				alloc.construct(arr, val);
				++sz;
				++cap;
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

	void pop_back() {
		alloc.destroy(--sz + arr);
	};

	iterator insert(iterator position, const T& value) {
		if (sz < cap) {
			alloc.construct(arr + sz, value);
			for (iterator it = position; it < end(); ++it)
				*it = *(end());
			++sz;
			return position;
		}
		try {
			if (cap == 0) {
				arr = alloc.allocate(1);
				alloc.construct(arr, value);
				++sz;
				++cap;
				return arr;
			}
			size_type	n = position - arr;
			value_type* newArr = alloc.allocate(cap * 2);
			for (size_type i = 0; i <= sz; ++i) {
				if (i < n) {
					alloc.construct(newArr + i, *(arr + i));
					alloc.destroy(arr + i);
				}
				if (i == n)
					alloc.construct(newArr + i, value);
				if (i > n) {
					alloc.construct(newArr + i, *(arr + i - 1))
					alloc.destroy(arr + i - 1);
				}
			}
			alloc.deallocate(arr, cap);
			arr = newArr;
			++sz;
			cap *= 2;
			return (arr + n);
		} catch (std::bad_alloc &e) {
			std::cerr << e.what() << std::endl;
		}
	};
	void insert(iterator position, size_type n, const T& x) {
		
	};
	// template <class InputIterator>
	// void insert(iterator position, InputIterator first, InputIterator last);

	iterator erase(iterator position) {
		alloc.destroy(position);
		if (position - arr < sz) {
			alloc.construct(position, *(position + 1));
			for (iterator it = position + 1; it != (end() - 1); ++it)
				*it = *(it + 1);
		}
		--sz;
		return position;
	};
	iterator erase(iterator first, iterator last) {
		for (iterator it = first; it != last; ++it) 
			alloc.destroy(it);
		for (iterator it = first, it2 = last; it != last, it2 != end(); ++it, ++it2)
			alloc.construct(it, *it2);
		for (iterator it = last; (it + (last - first)) < end(); ++it)
			*it = *(it + (last - first));
		sz-= (last - first);
		return (first);
	};
	
	void swap(vector<value_type, allocator_type>& other) {
		value_type	*tmp_p;
		size_type	tmp_cap;
		size_type	tmp_sz;
		tmp_p = arr;
		tmp_cap = cap;
		tmp_sz = sz;
		arr = other.arr;
		cap = other.cap;
		sz = other.sz;
		other.arr = tmp_p;
		other.cap = tmp_cap;
		other.sz = tmp_sz;
	};

	void clear() {
		for (size_type i = 0; i < sz; ++i)
			alloc.destroy(arr + i);
		sz = 0;
	};
};

		/*		Operators		*/
// template <class T, class Allocator>
// 	bool operator==(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);
// template <class T, class Allocator>
// 	bool operator< (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);
// template <class T, class Allocator>
// 	bool operator!=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);
// template <class T, class Allocator>
// 	bool operator> (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);
// template <class T, class Allocator>
// 	bool operator>=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);
// template <class T, class Allocator>
// 	bool operator<=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs);


		/*		Specialized algorighms		*/
template <class T, class Allocator>
	void swap(vector<T,Allocator>& lhs, vector<T,Allocator>& rhs) {
		lhs.swap(rhs);
	};

}

#endif