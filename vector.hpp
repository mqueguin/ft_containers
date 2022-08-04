#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include "iterator.hpp"
#include "reverseIterator.hpp"
#include "type_traits.hpp"
#include "compare.hpp"

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
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
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
				for (size_type i = 0; i < n; i++)
					_default_allocator_type.construct(&_base[i], val);
			}

			template <class InputIterator>
				vector(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator(), const allocator_type &alloc = allocator_type()): _default_allocator_type(alloc) {
					_size = 0;
					size_type n = 0;
					for (InputIterator it = first; it != last; it++)
						n++;
					_capacity = n;
					_base = _default_allocator_type.allocate(_capacity);
					for (; first != last;)
						_default_allocator_type.construct(&_base[_size++], *(first++));
				}

			vector (vector const &x) {
				_capacity = x._capacity;
				_size = x._size;
				if (x._size)
				{
					_base = _default_allocator_type.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_default_allocator_type.construct(&_base[i], x._base[i]);
				}
			}

			~vector(void) {
				for (size_type i = 0; i < _size; i++)
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
				for (size_type i = 0; i < _size; i++)
					_default_allocator_type.construct(&_base[i], x._base[i]);
				return (*this);
			}

			iterator begin(void) {
				return iterator(&front());
			}

			const_iterator begin(void) const {
				return const_iterator(&front());
			}

			iterator end(void) {
				return iterator(&back() + 1);
			}

			const_iterator end(void) const {
				return const_iterator(&back() + 1);
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
				return ((*this)[0]);
			}

			const_reference front(void) const {
				return ((*this)[0]);
			}

			reference back(void) {
				return ((*this)[_size - 1]);
			}

			const_reference back(void) const {
				return ((*this)[_size - 1]);
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
					for (size_type i = 0; i < _size; i++)
						_default_allocator_type.construct(&tmp[i], _base[i]);
					for (size_type i = 0; i < _size; i++)
						_default_allocator_type.destroy(&_base[i]);
					_default_allocator_type.deallocate(_base, _capacity);
					_base = tmp;
					_capacity = n;
				}
			}

			template<class InputIterator>
				void assign(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = InputIterator()) {
					T* tmp;
					size_t	n = 0;
					for (InputIterator it = first; it != last; it++)
						n++;
					if (n > capacity())
						tmp = _default_allocator_type.allocate(n);
					else
						tmp = _default_allocator_type.allocate(capacity());
					size_t	i = 0;
					for (InputIterator it = first; it != last; ++it)
						_default_allocator_type.construct(&tmp[i++], *it);
					for (iterator it = begin(); it != end(); ++it)
						_default_allocator_type.destroy(&(*it));
					_default_allocator_type.deallocate(_base, capacity());
					if (n > capacity())
						_capacity = n;
					_base = tmp;
					_size = n;
				}
			
			void assign(size_type n, const value_type &val) {
				this->clear();
				if (n == 0)
					return ;
				if ((size_type)(_capacity) >= n) {
					for (size_type i = 0; i < n; i++)
						_default_allocator_type.construct(&_base[_size++], val);
				} else {
					_default_allocator_type.deallocate(_base, _capacity);
					_capacity = n;
					_base = _default_allocator_type.allocate(_capacity);
					for (size_type i = 0; i < n; i++)
						_default_allocator_type.construct(&_base[_size++], val);
				}
			}

			iterator erase(iterator position) {
				iterator index = std::copy(position + 1, end(), position);
				_default_allocator_type.destroy(&*index);
				_size--;
				return (position);
			}

			iterator erase(iterator first, iterator last) {
				iterator position = std::copy(last, end(), first);
				for (iterator it = position; it != end(); ++it)
					_default_allocator_type.destroy(&*it);
				_size -= last - first;
				return (first);
			}

			void push_back(const value_type &val) {
				if (_size == _capacity) {
					reserve(size() == 0 ? 1 : size() * 2);
					_default_allocator_type.construct(&_base[_size++], val);
				}
				else
					_default_allocator_type.construct(&_base[_size++], val);
			}

			void pop_back(void) {
				_default_allocator_type.destroy(&_base[_size - 1]);
				_size--;
			}

			void resize(size_type n, value_type val = value_type()) {
				if (_size > n) {
					for (; n < _size; _size--)
						_default_allocator_type.destroy(&_base[_size - 1]);
				} else {
					if (n > _capacity)
						reserve(capacity() * 2 > n ? capacity() * 2 : n);
					for (size_type i = size(); i < n; i++)
						_default_allocator_type.construct(&_base[i], val);
					_size = n;
				}
			}

			iterator insert(iterator position, const value_type &val) {
				if (position == end()) {
					push_back(val);
					return (end() - 1);
				}
				if (size() >= capacity()) {
					T* tmp;
					size_type newCapacity = capacity() * 2;
					if (newCapacity == 0)
						newCapacity = size() + 1;
					tmp = _default_allocator_type.allocate(newCapacity);
					size_type i = 0;
					for (iterator it = begin(); it != end(); ++it) {
						if (it == position) {
							_default_allocator_type.construct(&tmp[i], val);
							position = &tmp[i];
							it--;
						} else if (it != end())
							_default_allocator_type.construct(&tmp[i], *it);
						i++;
					}
					for (iterator it = begin(); it != end(); ++it)
						_default_allocator_type.destroy(&(*it));
					_default_allocator_type.deallocate(_base, capacity());
					_capacity = newCapacity;
					_base = tmp;
				} else {
					if (!empty()) {
						_default_allocator_type.construct(&(*end()), *(end() - 1));
						std::copy_backward(position, end(), end() + 1);
					}
					_default_allocator_type.construct(&(*position), val);
				}
				_size++;
				return (position);
			}

			void insert(iterator position, size_type n, const value_type &val) {
				if (n == 1)
					insert(position, val);
				else if (size() + n >= capacity()) {
					T *tmp;
					size_type newCapacity = capacity() * 2;
					if (capacity() + n > capacity())
						newCapacity = capacity() + n;
					tmp = _default_allocator_type.allocate(newCapacity);
					size_type i = 0;
					for (iterator it = begin(); it != end() + 1; ++it) {
						if (it == position) {
							for (size_type j = 0; j < n; j++)
								_default_allocator_type.construct(&tmp[i++], val);
							position = &tmp[i];
							it--;
						} else if (it != end())
							_default_allocator_type.construct(&tmp[i++], *it);
					}
					for (iterator it = begin(); it != end(); ++it)
						_default_allocator_type.destroy(&(*it));
					_default_allocator_type.deallocate(_base, capacity());
					_capacity = newCapacity;
					_base = tmp;
				} else {
					if (!empty()) {
						for (iterator it = end(); it != end() + n; ++it)
							_default_allocator_type.construct(&(*it), *(end() - 1));
						std::copy_backward(position, end(), end() + n);
					}
					for (size_type i = 0; i < n; i++)
						_default_allocator_type.construct(&position[i], val);
				}
				_size += n;
			}

			template<class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = InputIterator()) {
					size_type n = 0;
					for (InputIterator it = first; it != last; ++it)
						n++;
					if (n == 1)
						return (static_cast<void>(insert(position, *first)));
					if (size() + n > capacity()) {
						T *tmp;
						size_type newCapacity = size() * 2;
						if (newCapacity < size() + n)
							newCapacity = size() + n;
						tmp = _default_allocator_type.allocate(newCapacity);
						size_type i = 0;
						for (iterator it = begin(); it != end() + 1; ++it) {
							if (it == position) {
								for (InputIterator it2 = first; it2 != last; ++it2)
									_default_allocator_type.construct(&tmp[i++], *it2);
								position = &tmp[i];
								it--;
							} else if (it != end())
								_default_allocator_type.construct(&tmp[i++], *it);	
						}
						for (iterator it = begin(); it != end(); ++it)
							_default_allocator_type.destroy(&(*it));
						_default_allocator_type.deallocate(_base, _capacity);
						_capacity = newCapacity;
						_base = tmp;
					} else {
						if (!empty()) {
							for (iterator it = end(); it != end() + n; ++it)
								_default_allocator_type.construct(&(*it), *(end() - 1));
							std::copy_backward(position, end(), end() + n);
						}
						size_type i = 0;
						for (InputIterator it = first; it != last; ++it)
							_default_allocator_type.construct(&position[i++], *it);
					}
					_size += n;
				}
	};

	/* OVERLOAD OPERATOR out vector class */
	template<class T, class Alloc>
		bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			if (lhs.size() != rhs.size())
				return (false);
			typename vector<T, Alloc>::const_iterator it1 = lhs.begin();
			typename vector<T, Alloc>::const_iterator it2 = rhs.begin();
			for (; it1 != lhs.end(); ++it1, ++it2) {
				if (*it1 != *it2)
					return (false);
			}
			return (true);
		}

	template<class T, class Alloc>
		bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return (!(lhs == rhs));
		}

	template<class T, class Alloc>
		bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

	template<class T, class Alloc>
		bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return (rhs < lhs);
		}

	template<class T, class Alloc>
		bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return (!(rhs < lhs));
		}

	template<class T, class Alloc>
		bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
			return (!(lhs < rhs));
		}

	template<class T, class Alloc>
		void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) {
			x.swap(y);
		}
}