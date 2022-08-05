#pragma once

#include "reverseIterator.hpp"
#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "compare.hpp"
#include "redBlackTree.hpp"

namespace ft {

	template<class T>
	class redBlackTreeIter {

		public:
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef value_type *pointer;
			typedef value_type &reference;
			typedef std::bidirectional_iterator_tag iterator_category;

		private:
			typedef ft::node<T> *_node_ptr;
			_node_ptr _node;

			redBlackTreeIter(void): _node(NULL) {}

			redBlackTreeIter(_node_ptr ptr): _node(ptr) {}

			redBlackTreeIter(const redBlackTreeIter &copy) {
				*this = copy;
			}

			~redBlackTreeIter(void) {}

			redBlackTreeIter &operator=(const redBlackTreeIter &copy) {
				_node = copy._node;
				return (*this);
			}

			bool	operator==(const redBlackTreeIter &rhs) const {
				return (_node == rhs._node);
			}

			bool operator!=(const redBlackTreeIter &rhs) const {
				return (_node != rhs._node);
			}

			reference operator*(void) const {
				return (_node->value);
			}

			pointer operator->(void) const {
				return (&_node->value);
			}
	};
}