/*#pragma once

#include "reverseIterator.hpp"
#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "compare.hpp"
#include "redBlackTree.hpp"
#include "iterator_tag.hpp"

namespace ft {

	template<class T>
	class redBlackTreeIter {

		public:
			//friend struct tree;
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef value_type *pointer;
			typedef value_type &reference;
			typedef ft::bidirectional_iterator_tag iterator_category;

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

			_node_ptr base(void) const {
				return (_node);
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

			redBlackTreeIter &operator++(void) {
				if (_node->right != NULL) {
					_node = _node->right;
					for (; _node->left != NULL; _node = _node->left)
						;
				} else {
					_node = _node->parent;
					for (_node->right == _node;) {
						_node = _node->parent;
						if (_node == NULL)
							break;
					}
				}
				return (*this);
			}

			redBlackTreeIter operator++(int) {
				redBlackTreeIter tmp(*this);
				++(*this);
				return (tmp);
			}

			redBlackTreeIter &operator--(void) {
				if (_node->color == RED && _node->parent->parent == _node)
					_node = _node->right;
				else if (_node->left != NULL) {
					_node = _node->left;
					for (; _node->right != NULL; _node = _node->right)
						;
				} else {
					_node = _node->parent;
					for (_node->left == _node;) {
						_node = _node->parent;
						if (_node == NULL)
							break;
					}
				}
				return (*this);
			}

			redBlackTreeIter operator--(int) {
				redBlackTreeIter tmp(*this);
				--(*this);
				return (tmp);
			}
	};

	template<class T>
	class const_redBlackTreeIter {

		public:
			//friend struct tree;
			typedef const T	value_type;
			typedef std::ptrdiff_t difference_type;
			typedef const value_type *pointer;
			typedef const value_type &reference;
			typedef ft::bidirectional_iterator_tag iterator_category;

		private:
			typedef ft::node<T> *_node_ptr;

		public:
			const_redBlackTreeIter(void): _node(NULL) {}

			const_redBlackTreeIter(_node_ptr ptr): _node(ptr) {}

			const_redBlackTreeIter(const const_redBlackTreeIter &copy) {
				*this = copy;
			}

			~const_redBlackTreeIter(void) {}

			_node_ptr base(void) const {
				return (_node);
			}

			const_redBlackTreeIter &operator=(const redBlackTreeIter<T> &copy) {
				_node = copy.base();
				return (*this);
			}

			const_redBlackTreeIter &operator=(const const_redBlackTreeIter &copy) {
				_node = copy._node;
				return (*this);
			}

			bool operator==(const const_redBlackTreeIter &rhs) const {
				return (_node == rhs._node);
			}

			bool operator!=(const const_redBlackTreeIter &rhs) const {
				return (_node != rhs._node);
			}

			reference operator*(void) const {
				return (_node->value);
			}

			pointer operator->(void) const {
				return (&_node->value);
			}


	};
}*/