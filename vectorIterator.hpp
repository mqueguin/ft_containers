#pragma once

#include <fstream>

namespace ft {

	template<class T> class vectorIterator {

		public:
			typedef T*	pointer;
			typedef T&	reference;
			typedef T	value_type;
		
		protected:
			pointer		_ptr;
		
		public:
		/* constructor destructor*/
			vectorIterator(void) {};
			vectorIterator(pointer ptr): _ptr(ptr) {};
			vectorIterator(const vectorIterator &copy) { *this = copy; }
			~vectorIterator(void) {};

			vectorIterator &operator=(const vectorIterator &copy) {
				_ptr = copy._ptr;
				return (*this);
			}

			/* Prefix incrementation pointer */
			vectorIterator &operator++(void) {
				++_ptr;
				return (*this);
			}

			/* Postfix incrementation pointer */
			vectorIterator operator++(int) {
				vectorIterator tmp(*this);
				++_ptr;
				return (tmp);
			}

			/* Prefix decrementation pointer */
			vectorIterator &operator--(void) {
				--_ptr;
				return (*this);
			}

			/* Postfix decrementation pointer */
			vectorIterator operator--(int) {
				vectorIterator tmp(*this);
				--_ptr;
				return (tmp);
			}

			/* Overload operator */
			bool	operator==(const vectorIterator &rhs) const {
				return (_ptr == rhs._ptr);
			}

			bool operator<(const vectorIterator &rhs) const {
				return (_ptr < rhs._ptr);
			}

			bool operator>(const vectorIterator &rhs) const {
				return (_ptr > rhs._ptr);
			}

			bool operator<=(const vectorIterator &rhs) const {
				return (_ptr <= rhs._ptr);
			}

			bool operator>=(const vectorIterator &rhs) const {
				return (_ptr >= rhs._ptr);
			}

			bool operator!=(const vectorIterator &rhs) const {
				return (_ptr != rhs._ptr);
			}

			value_type &operator*(void) {
				return (*_ptr);
			}
	};
}
