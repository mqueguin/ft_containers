#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include "iterator.hpp"
#include "reverseIterator.hpp"

namespace ft {

	template<class T, class Allocator = std::allocator<T> >
	class vector {

		public:
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::iterator<std::random_access_iterator_tag, value_type> iterator;
			typedef ft::iterator<std::random_access_iterator_tag, const value_type> const_iterator;
			typedef typename ft::reverseIterator<iterator> reverse_iterator;
			typedef typename ft::reverseIterator<const_iterator> const_reverse_iterator;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;

		private:
			T *_base;
			allocator_type _default_allocator_type;
			size_type _size;
			size_type _capacity;
		
		public:
			explicit vector(const allocator_type &alloc = allocator_type()): _base(NULL), _default_allocator_type(alloc), _size(0), _capacity(0) {}

			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()): _default_allocator_type(alloc), _size(n), _capacity(n) {
				_base = _default_allocator_type.allocate(_capacity);
				for (int i = 0; i < n; i++)
					_default_allocator_type.construct(&_base[i], val);
			}

			template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()): _default_allocator_type(alloc), _size(last - first), _capacity(last - first) {
					_base = _default_allocator_type.allocate(_capacity);
					for (int i = 0; first != last; first++)
						_default_allocator_type.construct(&_base[i++], first);
				}

			vector (vector const &x) {
				_capacity = x._capacity;
				_size = x._size;
				if (x._size)
				{
					_base = _default_allocator_type.allocate(_capacity);
					for (int i = 0; i < _size; i++)
						_default_allocator_type.construct(&_base[i], x._base[i]);
				}
			}

			~vector(void) {
				for (int i = 0; i < _size; i++)
					_default_allocator_type.destroy(&_base[i]);
				_default_allocator_type.deallocate(_base, _capacity);
			}

			/* OVERLOAD OPERATOR + */
			vector &operator=(const vector &x) {
				for (iterator it = begin(); _size && it != end(); it++)
					_default_allocator_type.destroy(&*it);
				if (_capacity < x._capacity)
				{
					if (_capacity)
						_default_allocator_type.deallocate(_base, _capacity);
					_capacity = x._capacity;
					_base = _default_allocator_type.allocate(x._capacity);
				}
				_size = x._size;
				for (int i = 0; i < _size; i++)
					_default_allocator_type.construct(&_base[i], x._base[i]);
				return (*this);
			}

			iterator begin(void) {
				return iterator(_base);
			}

			const_iterator begin(void) const {
				return const_iterator(_base);
			}

			iterator end(void) {
				return iterator(_base + _size);
			}

			const_iterator end(void) const {
				return const_iterator(_base + _size);
			}

			reverse_iterator rbegin(void) {
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin(void) const {
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend(void) {
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend(void) const {
				return (const_reverse_iterator(begin()));
			}

			size_type size(void) const {
				return (_size);
			}

			size_type capacity(void) const {
				return (_capacity);
			}

			allocator_type get_allocator(void) const {
				return (_default_allocator_type);
			}

			bool empty(void) const {
				return (_size == 0);
			}

			reference front(void) {
				return (_base[0]);
			}

			const_reference front(void) const {
				return (_base[0]);
			}

			reference back(void) {
				return (_base[--_size]);
			}

			const_reference back(void) const {
				return (_base[--_size]);
			}

			void swap(vector &x) {
				size_type tmp = x._size;
				x._size = _size;
				_size = tmp;
				tmp = x._capacity;
				x._capacity = _capacity;
				_capacity = tmp;
				T *tmp2 = x._base;
				x._base = _base;
				_base = tmp2;
			}

			void clear(void) {
				for (iterator it = begin(); it != end(); it++)
					_default_allocator_type.destroy(&*it);
				_size = 0;
			}

			reference at(size_type n) {
				if (n >= _size)
					throw std::out_of_range("out of range");
				return (_base[n]);
			}

			const_reference at(size_type n) const {
				if (n >= _size)
					throw std::out_of_range("out of range");
				return (_base[n]);
			}

			reference operator[](size_type n) {
				return (_base[n]);
			}

			const_reference operator[](size_type n) const {
				return (_base[n]);
			}

			size_type max_size(void) const {
				return (_default_allocator_type.max_size());
			}

			value_type *data(void) {
				return (_base);
			}

			const value_type *data(void) const {
				return (_base);
			}
			
			void reserve(size_type n) {
				if ( n > this->max_size())
					throw std::length_error("vector::reserve is too big");
				if (n > _capacity) {
					T *tmp = _default_allocator_type.allocate(n);
					for (int i = 0; i < _size; i++)
						_default_allocator_type.construct(&tmp[i], _base[i]);
					for (int i = 0; i < _size; i++)
						_default_allocator_type.destroy(&_base[i]);
					_default_allocator_type.deallocate(_base, _capacity);
					_base = tmp;
					_capacity = n;
				}
			}

			template<class InputIterator>
				void assign(InputIterator first, InputIterator last) {
					if (_capacity < (size_type)(last - first))
					{
						if (_capacity)
							_default_allocator_type.deallocate(_base, _capacity);
						for (int i = 0; i < _size; i++)
							_default_allocator_type.destroy(&_base[i]);
						_capacity = (size_type)(last - first);
						_base = _default_allocator_type.allocate(_capacity);
					}
					for (; first != last; first++)
						_default_allocator_type.construct(&_base[i++], *first);
					_size = 0;
				}
			
			void assign(size_type n, const value_type &val) {
				if (_capacity < n)
				{
					if (_capacity)
						_default_allocator_type.deallocate(_base, _capacity);
					for (int i = 0; i < _size; i++)
						_default_allocator_type.destroy(&_base[i]);
					_capacity = n;
					_base = _default_allocator_type.allocate(_capacity);
				}
				for (int i = 0; i < n; i++)
					_default_allocator_type.construct(&_base[i], val);
				_size = n;
			}
	};

	/* OVERLOAD OPERATOR out vector class */
	template<class T, class Alloc>
		bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			if (lhs.size() != rhs.size())
				return (false);
			for (int i = 0; i < lhs.size(); i++)
				if (lhs[i] != rhs[i])
					return (false);
			return (true);
		}

	template<class T, class Alloc>
		bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return (!(lhs == rhs));
		}

	template<class T, class Alloc>
		bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			if (lhs.size() < rhs.size())
				return (true);
			else if (lhs.size() > rhs.size())
				return (false);
			for (int i = 0; i < lhs.size(); i++)
			{
				if (lhs[i] < rhs[i])
					return (true);
				else if (lhs[i] > rhs[i])
					return (false);
			}
			return (false);
		}

	template<class T, class Alloc>
		bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return (rhs < lhs);
		}

	template<class T, class Alloc>
		bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return (!(lhs > rhs));
		}

	template<class T, class Alloc>
		bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return (!(lhs , rhs));
		}

	template<class T, class Alloc>
		void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) {
			x.swap(y);
		}
}