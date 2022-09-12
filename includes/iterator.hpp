#pragma once

#include <fstream>
#include "iterator_traits.hpp"

namespace ft {

	template<class Category, class T, class Distance = std::ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	class iterator {

		public:
			typedef T								value_type;
			typedef Distance						difference_type;
			typedef Pointer							pointer;
			typedef Reference						reference;
			typedef Category						iterator_category;
		
		private:
			pointer		_ptr;
		
		public:
		/* constructor destructor*/
			iterator(void): _ptr(NULL) {};
			iterator(pointer ptr): _ptr(ptr) {};
			iterator(const iterator &copy) { *this = copy; }
			virtual ~iterator(void) {};

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
			template <class U>
			bool operator==(const U& lhs) const {
				return (_ptr == lhs.base());
			}
			template <class U>
			bool operator!=(const U& lhs) const {
				return _ptr != lhs.base();
			}
			template <class U>
			bool operator<(const U& lhs) const {
				return _ptr < lhs.base();
			}
			template <class U>
			bool operator>(const U& lhs) const {
				return _ptr > lhs.base();
			}
			template <class U>
			bool operator<=(const U& lhs) const {
				return _ptr <= lhs.base();
			}
			template <class U>
			bool operator>=(const U& lhs) const {
				return _ptr >= lhs.base();
			}


			iterator operator-(difference_type n) const {
				iterator tmp(*this);
				tmp._ptr -= n;
				return (tmp);
			}

			difference_type operator-(iterator const &u) const { /* AUCUUUUUUUUN PUTAIN DE SENS */
				return (base() - u.base());
			}
			template<class U>
			difference_type operator-(U &u) const {               /* CA N A PAS DE SENS PTDRRRRR */
				return (base() - u.base());
			}

			pointer operator->(void) {
				return (_ptr);
			}

			reference operator*(void) const {
				return (*_ptr);
			}

			iterator &operator+=(difference_type n) {
				_ptr += n;
				return (*this);
			}

			iterator &operator-=(difference_type n) {
				_ptr -= n;
				return (*this);
			}

			iterator operator+(difference_type n) const {
				iterator tmp(*this);
				tmp._ptr += n;
				return (tmp);
			}

			reference operator[](difference_type n) {
				return (_ptr[n]);
			}
			/* FIN OVERLOAD OPERATOR */
			operator    iterator<ft::random_access_iterator_tag, const value_type>() const
			{
				return iterator<ft::random_access_iterator_tag, const value_type>(_ptr);
			}
			friend iterator operator+(int n, const iterator& it)
			{
				return iterator(it._ptr + n);
			}
	};
}
