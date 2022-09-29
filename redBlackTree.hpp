#pragma once

#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "compare.hpp"
#include "reverseIterator.hpp"
#include "iterator_tag.hpp"

namespace ft
{
	typedef enum 	e_color {
		RED,
		BLACK
	}				t_color;

	template <typename T>
	struct	node {
		T				value;
		t_color			color;
		node	*parent;
		node	*left;
		node	*right;

		node(void) : color(BLACK), parent(NULL), left(NULL), right(NULL) {}

		node(const T &val) : value(val), color(RED), parent(NULL), left(NULL), right(NULL) {}

		node(const node &obj) : value(obj.value), color(RED), parent(obj.parent), left(obj.left), right(obj.right) {}
		
		~node(void) {}

		node	&operator=(const node &rhs) {
			value = rhs.value;
			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			return (*this);
		}
	};

	template <class T>
	class _tree_iterator {
		private:
			typedef ft::node<T> 		*_base_ptr;
			_base_ptr					_node;

		public:
			template <class, class, class>
			friend struct rb_tree;
			typedef T							value_type; //Type of elements pointed by the iterator
			typedef ptrdiff_t					difference_type; //Type represent the difference between two iterators
			typedef value_type *				pointer; // Type to represent a pointer to an element pointed by the iterator
			typedef value_type &				reference; // Type to represent a reference to an element pointed by the iterator
			typedef bidirectional_iterator_tag	iterator_category; // Category of iterator

			_tree_iterator(void) {}

			_tree_iterator(_base_ptr ptr) : _node(ptr) {}

			_tree_iterator(const _tree_iterator& obj) {
				*this = obj;
			}

			~_tree_iterator(void) {}

			_tree_iterator	&operator=(const _tree_iterator &obj) {
				_node = obj._node;
				return (*this);
			}

			bool		operator==(const _tree_iterator &rhs) const {
				return (_node == rhs._node);
			}

			bool		operator!=(const _tree_iterator &rhs) const {
				return !(*this == rhs);
			}

			reference	operator*() {
				return (_node->value);
			}

			pointer	operator->(void) const {
				return (&_node->value);
			}

			/* Pre incrementation */
			_tree_iterator	&operator++() {
				std::cout << "Valeur de _node->parent->value.first: " << _node->parent->value.first << " et valeur de second: " << _node->parent->value.second << std::endl;
				std::cout << "Valeur de _node->parent->left->value.first: " << _node->parent->left->value.first << " et valeur de second: " << _node->parent->left->value.second << std::endl;
				std::cout << "Valeur de _node->parent->left->value.first: " << _node->parent->right->value.first << " et valeur de second: " << _node->parent->right->value.second << std::endl;
				if (_node->right != NULL)
				{
					_node = _node->right;
					while (_node->left != NULL)
						_node = _node->left;
				}
				else
				{
					_base_ptr	y = _node->parent;
					while (_node == y->right) {
						_node = y;
						y = y->parent;
					}
					if (_node->right != y)
						_node = y;
				}
				return (*this);
			}

			/* Post incrementation */
			_tree_iterator	operator++(int) {
				_tree_iterator	tmp(*this);
				++(*this);
				return (tmp);
			}

			/* Pre decrementation */
			_tree_iterator& operator--() {
				if (_node->color == RED && _node->parent->parent == _node)  
					_node = _node->right;
				else if (_node->left != NULL) {
					_base_ptr y = _node->left;
					while (y->right != NULL)
						y = y->right;
					_node = y;
				} else {
					_base_ptr y = _node->parent;
					while (_node == y->left) {
						_node = y;
						y = y->parent;
					}
					_node = y;
				}
				return (*this);
			}

			/* Post decrementation */
			_tree_iterator	operator--(int) {
				_tree_iterator	tmp(*this);
				--(*this);
				return (tmp);
			}

			_base_ptr	base(void) const {
				return (_node);
			}
	};

	template <class T>
	class _const_tree_iterator
	{
		private:
			typedef ft::node<T> *		_base_ptr;
			_base_ptr					_node;

		public:
			template <class, class, class>
			friend struct rb_tree;
			typedef const T						value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef const value_type *			pointer;
			typedef const value_type &			reference;
			typedef bidirectional_iterator_tag	iterator_category;

			_const_tree_iterator(void) {}

			_const_tree_iterator(_base_ptr ptr) : _node(ptr) {}

			_const_tree_iterator(const _tree_iterator<T>& obj) {
				*this = obj;
			}

			_const_tree_iterator(const _const_tree_iterator& obj) {
				*this = obj;
			}

			~_const_tree_iterator(void) {}

			_const_tree_iterator	&operator=(const _tree_iterator<T> &obj) {
				_node = obj.base();
				return (*this);
			}

			_const_tree_iterator	&operator=(const _const_tree_iterator &obj) {
				_node = obj._node;
				return (*this);
			}

			bool		operator==(const _const_tree_iterator &rhs) const {
				return (_node == rhs._node);
			}

			bool		operator!=(const _const_tree_iterator &rhs) const{
				return !(*this == rhs);
			}

			pointer	operator->(void) const {
				return (&_node->value);
			}

			reference	operator*() const {
				return (_node->value);
			}

			/* Pre incrementation */
			_const_tree_iterator	&operator++() {
				if (_node->right != NULL) {
					_node = _node->right;
					while (_node->left != NULL)
						_node = _node->left;
				} else {
					_base_ptr	y = _node->parent;
					while (_node == y->right) {
						_node = y;
						y = y->parent;
					}
					if (_node->right != y)
						_node = y;
				}
				return (*this);
			}

			/* Post incrementation */
			_const_tree_iterator	operator++(int) {
				_const_tree_iterator	tmp(*this);
				++(*this);
				return (tmp);
			}

			/* Pre decrementation */
			_const_tree_iterator& operator--() {
				if (_node->color == RED && _node->parent->parent == _node)  
					_node = _node->right;
				else if (_node->left != NULL) {
					_base_ptr y = _node->left;
					while (y->right != NULL)
						y = y->right;
					_node = y;
				} else {
					_base_ptr y = _node->parent;
					while (_node == y->left) {
						_node = y;
						y = y->parent;
					}
					_node = y;
				}
				return (*this);
			}

			/* Post decrementation */
			_const_tree_iterator	operator--(int) {
				_const_tree_iterator	tmp(*this);
				--(*this);
				return (tmp);
			}

			_base_ptr	base(void) const {
				return (_node);
			}
	};

	template < class T, class Compare, class Allocator = std::allocator< node<T> > >
	struct rb_tree
	{
		typedef node<T>							value_type;
		typedef	std::allocator<value_type>				allocator;
		typedef value_type 								&reference;
		typedef const value_type						&const_reference;
		typedef node<T>							*node_type;
		typedef node<T>					*const_node_type;
		typedef	_tree_iterator<T>						iterator;
		typedef	_const_tree_iterator<T>					const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef std::size_t								size_type;

		allocator			alloc;
		Compare				key_compare;
		node_type			root;
		node_type			header;
		size_type			node_count;

		rb_tree(void): alloc(), key_compare(), root(NULL), header(alloc.allocate(1)), node_count(0) {
			alloc.construct(header, value_type());
			header->color = RED;
			header->parent = root;
			header->left = header;
			header->right = header;
		}

		rb_tree(const Compare &comp): alloc(), key_compare(comp), root(NULL), header(alloc.allocate(1)), node_count(0) {
			alloc.construct(header, value_type());
			header->color = RED;
			header->parent = root;
			header->left = header;
			header->right = header;
		}

		rb_tree(const rb_tree &obj): alloc(), key_compare(), root(), header(), node_count(0) {
			*this = obj;
		}

		~rb_tree(void) {}

		rb_tree	&operator=(const rb_tree &rhs) {
			key_compare = rhs.key_compare;
			root = rhs.root;
			header = rhs.header;
			node_count = rhs.node_count;
			return (*this);
		}

		iterator	begin(void) {
			return (iterator(leftmost()));
		}

		const_iterator	begin(void) const {
			return (const_iterator(leftmost()));
		}

		iterator	end(void) {
			return (iterator(header));
		}

		const_iterator	end(void) const {
			return (const_iterator(header));
		}

		node_type	left_rotate_tree(node_type node, node_type parent) {
			node_type	old_root = node;
			node = node->right;
			node->parent = old_root->parent;
			node_type	y = node->left;
			node->left = old_root;
			old_root->right = y;
			if (old_root->right)
				old_root->right->parent = old_root;
			old_root->parent = node;
			if (parent != header)
			{
				if (parent->left == old_root)
					parent->left = node;
				else
					parent->right = node;
			}
			return (node);
		}

		node_type	right_rotate_tree(node_type node, node_type parent) {
			node_type	old_root = node;
			node = node->left;
			node->parent = old_root->parent;
			node_type	y = node->right;
			node->right = old_root;
			old_root->left = y;
			if (old_root->left)
				old_root->left->parent = old_root;
			old_root->parent = node;
			if (parent != header)
			{
				if (parent->left == old_root)
					parent->left = node;
				else
					parent->right = node;
			}
			return (node);
		}

		/* Check if the tree is balancing */
		void	balance_tree(node_type node) {
			while (node != root && node->parent != root && node->parent->color == RED) {
				if (node->parent == node->parent->parent->left) {
					node_type	y = node->parent->parent->right;
					if (y != NULL && y->color == RED) {
						node->parent->color = BLACK;
						y->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					} else {
						if (node == node->parent->right) {
							node = node->parent;
							node = left_rotate_tree(node, node->parent);
						} else {
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = right_rotate_tree(node->parent->parent, node->parent->parent->parent);
						}
						if (node->parent == header) {
							root = node;
							header->parent = node;
						}
					}
				}
				else {
					node_type	y = node->parent->parent->left;
					if (y != NULL && y->color == RED) {
						node->parent->color = BLACK;
						y->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					} else {
						if (node == node->parent->left) {
							node = node->parent;
							node = right_rotate_tree(node, node->parent);
						} else {
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = left_rotate_tree(node->parent->parent, node->parent->parent->parent);
						}
						if (node->parent == header) {
							root = node;
							header->parent = node;
						}
					}
				}
			}
			root->color = BLACK;
		}

		iterator	insert(const T& value) {
			if (root == NULL) {
				root = alloc.allocate(1);
				alloc.construct(root, value);
				root->color = BLACK;
				root->parent = header;
				header->parent = root;
				header->left = root;
				header->right = root;
				node_count++;
				return (root);
			}

			iterator it = lower_bound(value.first);
			std::cout << "VAleur de it->first: " << it->first << std::endl;
			if (it->first == value.first)
				return it;
			node_type	z = root;
			bool		direction;
			node_type	node;
			while (z != NULL) {
				direction = key_compare(value.first, z->value.first);
				node = direction ? z->left : z->right;
				if (node == NULL || node == header)
					break ;
				z = node;
			}
			(direction ? z->left : z->right) = alloc.allocate(1);
			node = (direction ? z->left : z->right);
			alloc.construct(node, value);
			node->parent = z;
			if (header->left->left != NULL)
				header->left = header->left->left;
			if (header->right->right != NULL)
				header->right = header->right->right;
			balance_tree(node);
			header->color = RED;
			node_count++;
			return (node);
		}

		void	erase(iterator _node)
		{
			node_type	node = _node._node;
			if (header->left == node)
				header->left = node->parent;
			if (header->right == node)
				header->right = node->parent;
			if (node->left == NULL && node->right == NULL)
			{
				if (root == node)
				{
					root = NULL;
					header->left = header;
					header->right = header;
				}
				else if (node->parent->left == node)
					node->parent->left = NULL;
				else
					node->parent->right = NULL;
			}
			else if (node->right == NULL)
			{
				if (root == node)
				{
					root = node->left;
					header->right = root;
				}
				else
				{
					node->left->parent = node->parent;
					if (node->parent->right == node)
						node->parent->right = node->left;
					else
						node->parent->left = node->left;
					if (root == node)
						root = node;
				}
			}
			else if (node->left == NULL)
			{
				if (root == node)
				{
					root = node->right;
					header->left = root;
				}
				else
				{
					node->right->parent = node->parent;
					if (node->parent->left == node)
						node->parent->left = node->right;
					else
						node->parent->right = node->right;
				}
			}
			// if two children
			else
			{
				node_type	smallest_right = node->right;
				while (smallest_right->left != NULL)
					smallest_right = smallest_right->left;
				if (smallest_right != node->right)
				{
					smallest_right->parent->left = NULL;
					smallest_right->right = node->right;
				}
				node->left->parent = smallest_right;
				node->right->parent = smallest_right;
				smallest_right->left = node->left;
				smallest_right->parent = node->parent;
				if (node == root)
					root = smallest_right;
				else if (node->parent->right == node)
					node->parent->right = smallest_right;
				else
					node->parent->left = smallest_right;
			}
			header->parent = root;
			if (root != NULL)
				root->parent = header;
			if (header->left->left != NULL)
				header->left = header->left->left;
			if (header->right->right != NULL)
				header->right = header->right->right;
			node_count--;
			alloc.deallocate(&(*node), 1);
		}

		iterator	lower_bound(const typename T::first_type &key)
		{
			node_type	node = root;
			node_type	greater = node->parent;
			while (node != NULL) {
				if (key_compare(node->value.first, key))
					node = node->right;
				else {
					greater = node;
					node = node->left;
				}
			}
			return (iterator(greater));
		}

		const_iterator	lower_bound(const typename T::first_type &key) const
		{
			const_node_type	node = end()._node->parent;
			const_node_type	greater = node->parent;
			while (node != NULL) {
				if (key_compare(node->value.first, key))
					node = node->right;
				else {
					greater = node;
					node = node->left;
				}
			}
			return (const_iterator(greater));
		}

		iterator	upper_bound(const typename T::first_type &key)
		{
			node_type	node = root;
			node_type	greater = node->parent;
			while (node != NULL) {
				if (key_compare(key, node->value.first)) {
					greater = node;
					node = node->left;
				} else
					node = node->right;
			}
			return (iterator(greater));
		}

		const_iterator	upper_bound(const typename T::first_type &key) const
		{
			const_node_type	node = root;
			const_node_type	greater = node->parent;
			while (node != NULL) {
				if (key_compare(key, node->value.first)) {
					greater = node;
					node = node->left;
				} else
					node = node->right;
			}
			return (const_iterator(greater));
		}

		node_type	leftmost() {
			return (header->left);
		}

		const_node_type	leftmost() const {
			return (header->left);
		}

		node_type	rightmost() {
			return (header->right);
		}

		const_node_type	rightmost() const {
			return (header->right);
		}
	};
};