#pragma once

#include <fstream>
#include <iterator>

namespace ft {

	template<class Category, class T, class Distance = std::ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	class iterator {

		public:
			typedef T								value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef T*								pointer;
			typedef T&								reference;
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
			iterator &operator+=(difference_type n) {
				for (; n > 0; n--)
					(*this)++;
				for (; n < 0; n++)
					(*this)--;
			}

			iterator &operator-=(difference_type n) {
				for (; n > 0; n--)
					(*this)--;
				for (; n < 0; n++)
					(*this)++;
			}

			iterator operator+(difference_type n) {
				iterator(_ptr + n);
			}

			iterator operator-(difference_type n) {
				iterator(_ptr - n);
			}

			difference_type operator-(const iterator &rhs) {
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
			friend iterator operator+(difference_type n, const iterator& it)
			{
				return iterator(it._ptr + n);
			}
	};
}
