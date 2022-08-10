#pragma once

#include "iterator.hpp"
#include "iterator_traits.hpp"

namespace ft {

    template <class iterator>
        class reverse_iterator {
		
		public:
			typedef iterator					iterator_type;
			typedef typename iterator_traits<iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator>::value_type			value_type;
			typedef typename iterator_traits<iterator>::difference_type		difference_type;
			typedef typename iterator_traits<iterator>::pointer				pointer;
			typedef typename iterator_traits<iterator>::reference			reference;

		private:
			iterator _ptr;

		public:
			reverse_iterator(void): _ptr(NULL) {};
			explicit reverse_iterator(iterator it) {
				_ptr = it;
			};
			template <class Iter>
				reverse_iterator(reverse_iterator<Iter> const &rev_it) {
					_ptr = rev_it.base();
				};
			~reverse_iterator(void) {};

			iterator_type base(void) const {
				return (_ptr);
			}

			template<class Iter>
				reverse_iterator &operator=(reverse_iterator<Iter> const &rev_it) {
					_ptr = rev_it.base();
					return (*this);
				};

			reference operator*(void) const {
				iterator_type tmp = _ptr;
				return (*--tmp);
			}

			/* Prefix incrementation pointer */
			reverse_iterator &operator++(void) {
				this->_ptr--;
				return (*this);
			}

			reverse_iterator operator++(int) {
				reverse_iterator tmp(*this);
				this->_ptr--;
				return (tmp);
			}

			reverse_iterator &operator--(void) {
				this->_ptr++;
				return (*this);
			}

			reverse_iterator operator--(int) {
				reverse_iterator tmp(*this);
				this->_ptr++;
				return (tmp);
			}
			/* END INCREMENTATION DECREMENTATION OVERLOAD OPERATOR */

			reverse_iterator operator+=(difference_type n) {
				_ptr -= n;
				return (*this);
			}

			reverse_iterator operator-=(difference_type n) {
				_ptr += n;
				return (*this);
			}

			value_type *operator->(void) const {
				return (&(operator*()));
			}

			template<class U>
			difference_type operator-(const reverse_iterator<U> &u) {
				return (u.base() - this->_ptr);
			}
			reverse_iterator operator-(difference_type n) const {
				return (reverse_iterator(this->_ptr.operator+(n)));
			}

			reverse_iterator operator+(difference_type n) {
				return (reverse_iterator(_ptr - n));
			}


			value_type &operator[](difference_type n) const {
				return (base()[-n-1]);
			}

            friend reverse_iterator operator+(difference_type n, const reverse_iterator& it) { 
				return (reverse_iterator(it._ptr - n));
			}
	};

	template<class itr, class itr2>
		bool operator==(reverse_iterator<itr> const &lhs, reverse_iterator<itr2> const &rhs) {
			return (lhs.base() == rhs.base());
		}
	template<class itr, class itr2>
		bool operator!=(reverse_iterator<itr> const &lhs, reverse_iterator<itr2> const &rhs) {
			return (lhs.base() != rhs.base());
		}
	template<class itr, class itr2>
		bool operator<(reverse_iterator<itr> const &lhs, reverse_iterator<itr2> const &rhs) {
			return (lhs.base() > rhs.base());
		}
	template<class itr, class itr2>
		bool operator>(reverse_iterator<itr> const &lhs, reverse_iterator<itr2> const &rhs) {
			return (lhs.base() < rhs.base());
		}
	template<class itr, class itr2>
		bool operator<=(reverse_iterator<itr> const &lhs, reverse_iterator<itr2> const &rhs) {
			return (lhs.base() >= rhs.base());
		}
	template<class itr, class itr2>
		bool operator>=(reverse_iterator<itr> const &lhs, reverse_iterator<itr2> const &rhs) {
			return (lhs.base() <= rhs.base());
		}
	template <class itr>
		reverse_iterator<itr> operator+(typename reverse_iterator<itr>::difference_type n, const reverse_iterator<itr>& rev_it) { 
			return rev_it.base() - n;
		}
}