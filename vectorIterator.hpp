#pragma once

#include <fstream>

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

			pointer Base(void) const {
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

			reference &operator*(void) {
				return (*_ptr);
			}

			pointer *operator->(void) {
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
				iterator tmp(*this);

				tmp += n;
				return (tmp);
			}

			iterator operator-(difference_type n) {
				iterator tmp(*this);

				tmp -= n;
				return (tmp);
			}

			reference operator[](difference_type n) {
				return (_ptr[n]);
			}
			/* FIN OVERLOAD OPERATOR */
	};

	template <class iterator> class reverseIterator {
		
		public:
			typedef iterator					iterator_type;
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename iterator::value_type		value_type;
			typedef typename iterator::difference_type	difference_type;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::reference			reference;

		private:
			pointer _ptr;

		public:
			reverseIterator(void): _ptr(NULL) {};
			explicit reverseIterator(iterator const &it) {
				_ptr = it;
			};
			template <class Iter>
				reverseIterator(reverseIterator<Iter> const &rev_it) {
					_ptr = rev_it.base();
				};
			~reverseIterator(void) {};

			iterator_type base(void) const {
				return (_ptr);
			}

			template<class Iter>
				reverseIterator &operator=(reverseIterator<Iter> const &rev_it) {
					_ptr = rev_it.base();
					return (*this);
				};

			reference operator*(void) const {
				iterator_type tmp = _ptr;
				return (*--tmp);
			}

			/* Prefix incrementation pointer */
			reverseIterator &operator++(void) {
				this->_ptr--;
				return (*this);
			}

			reverseIterator operator++(int) {
				reverseIterator tmp(*this);
				this->_ptr--;
				return (tmp);
			}

			reverseIterator &operator--(void) {
				this->_ptr++;
				return (*this);
			}

			reverseIterator operator--(int) {
				reverseIterator tmp(*this);
				this->_ptr++;
				return (tmp);
			}
			/* END INCREMENTATION DECREMENTATION OVERLOAD OPERATOR */

			reverseIterator operator+=(difference_type n) {
				_ptr -= n;
				return (*this);
			}

			reverseIterator operator-=(difference_type n) {
				_ptr += n;
				return (*this);
			}

			value_type *operator->(void) {
				return (this->_ptr);
			}

			reverseIterator operator+(difference_type n) {
				return (_ptr - n);
			}

			reverseIterator operator-(int n) {
				return (_ptr + n);
			}

			value_type &operator[](difference_type n) const {
				return (base()[-n-1]);
			}
	};

	template<class itr, class itr2>
		bool operator==(reverseIterator<itr> const &lhs, reverseIterator<itr2> const &rhs) {
			return (lhs.base() == rhs.base());
		}
	template<class itr, class itr2>
		bool operator!=(reverseIterator<itr> const &lhs, reverseIterator<itr2> const &rhs) {
			return (lhs.base() != rhs.base());
		}
	template<class itr, class itr2>
		bool operator<(reverseIterator<itr> const &lhs, reverseIterator<itr2> const &rhs) {
			return (lhs.base() < rhs.base());
		}
	template<class itr, class itr2>
		bool operator>(reverseIterator<itr> const &lhs, reverseIterator<itr2> const &rhs) {
			return (lhs.base() > rhs.base());
		}
	template<class itr, class itr2>
		bool operator<=(reverseIterator<itr> const &lhs, reverseIterator<itr2> const &rhs) {
			return (lhs.base() <= rhs.base());
		}
	template<class itr, class itr2>
		bool operator>=(reverseIterator<itr> const &lhs, reverseIterator<itr2> const &rhs) {
			return (lhs.base() >= rhs.base());
		}
	template<class itr>
		typename reverseIterator<itr>::difference_type operator-(reverseIterator<itr> const &lhs, reverseIterator<itr> const &rhs) {
			return (rhs.base() - lhs.base());
		}
	template<class itr>
		reverseIterator<itr> operator+(typename reverseIterator<itr>::difference_type n, reverseIterator<itr> const &rev_it) {
			return (rev_it.base() - n);
		}
}
