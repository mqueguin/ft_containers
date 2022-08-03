#pragma once

#include <fstream>
#include <iterator>

namespace ft {

	template<class Category, class T, class Distance = std::ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	class iterator {

		public:
			typedef T								value_type;
			typedef Distance					difference_type;
			typedef Pointer							pointer;
			typedef Reference						reference;
			typedef std::random_access_iterator_tag	iterator_category;
		
		private:
			pointer		_ptr;
		
		public:
		/* constructor destructor*/
			iterator(void): _ptr(NULL) {};
			iterator(pointer ptr): _ptr(ptr) {};
			iterator(const iterator &copy) { *this = copy; }
			~iterator(void) {};

			pointer base(void) const {
				return (_ptr);
			}

			iterator &operator=(const iterator &copy) {
				_ptr = copy._ptr;
				return (*this);
			}

			/* Prefix incrementation pointer */
			iterator &operator++(void) {
				++_ptr;
				return (*this);
			}

			/* Postfix incrementation pointer */
			iterator operator++(int) {
				iterator tmp(*this);
				++_ptr;
				return (tmp);
			}

			/* Prefix decrementation pointer */
			iterator &operator--(void) {
				--_ptr;
				return (*this);
			}

			/* Postfix decrementation pointer */
			iterator operator--(int) {
				iterator tmp(*this);
				--_ptr;
				return (tmp);
			}

			/* Overload operator */
			bool	operator==(const iterator &rhs) const {
				return (_ptr == rhs.base());
			}

			bool operator<(const iterator &rhs) const {
				return (_ptr < rhs.base());
			}

			bool operator>(const iterator &rhs) const {
				return (_ptr > rhs.base());
			}

			bool operator<=(const iterator &rhs) const {
				return (_ptr <= rhs.base());
			}

			bool operator>=(const iterator &rhs) const {
				return (_ptr >= rhs.base());
			}

			bool operator!=(const iterator &rhs) const {
				return (_ptr != rhs.base());
			}

			reference operator*(void) {
				return (*_ptr);
			}

			pointer operator->(void) {
				return (_ptr);
			}
			iterator &operator+=(int n) {
				_ptr += n;
				return (*this);
			}

			iterator &operator-=(int n) {
				_ptr -= n;
				return (*this);
			}

			iterator operator+(int n) const {
				iterator tmp(*this);
				tmp._ptr += n;
				return (tmp);
			}

			iterator operator-(int n) const{
				iterator tmp(*this);
				tmp._ptr -= n;
				return (tmp);
			}

			int operator-(const iterator &rhs) const {
				return (_ptr - rhs._ptr);
			}

			reference operator[](difference_type n) {
				return (_ptr[n]);
			}
			/* FIN OVERLOAD OPERATOR */
			operator    iterator<std::random_access_iterator_tag, const value_type>() const
			{
				return iterator<std::random_access_iterator_tag, const value_type>(_ptr);
			}
			friend iterator operator+(int n, const iterator& it)
			{
				return iterator(it._ptr + n);
			}
	};
}
