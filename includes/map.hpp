#pragma once

#include <stdexcept>
#include <iostream>
#include <memory>
#include "redBlackTree.hpp"
#include "reverseIterator.hpp"
#include "utilityMap.hpp"

namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< ft::pair<const Key, T> > >
	class map
	{
	
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;

		private:
			typedef ft::rb_tree<value_type, Compare> _rep_type;

		public:
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef value_type &								reference;
			typedef const value_type &							const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			typedef ft::_tree_iterator<value_type> 							iterator;
			typedef ft::_const_tree_iterator<value_type> const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private: 
			typedef typename allocator_type::template rebind< rb_tree_node< value_type > >::other node_allocator_type;

		public:
			class value_compare
			{
				friend class map<Key, T, Compare, Allocator>;
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;

					bool	operator()(const value_type& lhs, const value_type& rhs) const
					{
						return comp(lhs.first, rhs.first);
					}

				protected:
					Compare	comp;

					value_compare(Compare c) : comp(c)
					{
					}
			};
	
			map(void) : _alloc(), _tree()
			{
			}
			explicit map(const Compare &comp, const Allocator &alloc = Allocator()) : _alloc(alloc), _tree(comp)
			{
			}
			map(const map &obj)
			{
				*this = obj;
			}
			template<class InputIt>
			map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : _alloc(alloc), _tree(comp)
			{
				while (first != last)
				{
					_tree.insert(*first);
					first++;
				}
			}
			~map(void)
			{
				node_allocator_type alloc;
				typename _rep_type::node_type	z = _tree.header->left;
				while (z != _tree.header && z->right != NULL)
				{
					while (z->left != NULL)
						z = z->left;
					if (z->right == NULL)
						break ;
					z = z->right;
				}
				while (z != _tree.header)
				{
					typename _rep_type::node_type	y = z->parent;
					alloc.deallocate(z, 1);
					while (y != _tree.header && y->right != NULL && y->right != z)
					{
						y = y->right;
						while (y->left != NULL)
							y = y->left;
					}
					z = y;
				}
				alloc.deallocate(z, 1);
			}
	
			map &operator=(const map &rhs)
			{
				clear();
				for (const_iterator it = rhs.begin(); it != rhs.end(); ++it)
					_tree.insert(*it);
				return *this;
			}

			allocator_type	get_allocator(void) const
			{
				return _alloc;
			}

			T	&at(const Key& key)
			{
				iterator it = lower_bound(key);
				if (it->first != key)
					throw std::out_of_range("map::at");
				return it->second;
			}
			const T	&at(const Key& key) const
			{
				const_iterator it = lower_bound(key);
				if (it->first != key)
					throw std::out_of_range("map::at");
				return it->second;
			}

			T	&operator[](const Key& key)
			{
				return _tree.insert(ft::make_pair(key, T()))->second;
			}

			iterator	begin(void)
			{
				return _tree.begin();
			}
			const_iterator	begin(void) const
			{
				return _tree.begin();
			}

			iterator	end(void)
			{
				return _tree.end();
			}
			const_iterator	end(void) const
			{
				return _tree.end();
			}

			reverse_iterator	rbegin(void)
			{
				return reverse_iterator(end());
			}
			const_reverse_iterator	rbegin(void) const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator	rend(void)
			{
				return reverse_iterator(begin());
			}
			const_reverse_iterator	rend(void) const
			{
				return const_reverse_iterator(begin());
			}

			bool	empty() const
			{
				return size() == 0;
			}

			size_type	size() const
			{
				return _tree.node_count;
			}

			size_type	max_size() const
			{
				node_allocator_type	alloc;
				return alloc.max_size();
			}

			void	clear(void)
			{
				erase(begin(), end());
			}

			ft::pair<iterator, bool>	insert(const value_type& value)
			{
				size_type	pre_size = size();
				iterator node = _tree.insert(value);
				return ft::make_pair(node, size() - pre_size);
			}

			iterator	insert(iterator hint, const value_type& value)
			{
				(void)hint;
				return insert(value).first;
			}

			template< class InputIt >
			void	insert(InputIt first, InputIt last)
			{
				while (first != last)
					insert(*first++);
			}

			void	erase(iterator pos)
			{
				_tree.erase(pos);
			}
			void	erase(iterator first, iterator last)
			{
				node_allocator_type alloc;
				if (first == begin() && last == end())
				{
					typename _rep_type::node_type	z = _tree.header->left;
					while (z != _tree.header && z->right != NULL)
					{
						while (z->left != NULL)
							z = z->left;
						z = z->right;
					}
					while (z != _tree.header)
					{
						typename _rep_type::node_type	y = z->parent;
						alloc.deallocate(z, 1);
						if (y != _tree.header && y->right != NULL && y->right != z)
						{
							y = y->right;
							while (y->left != NULL)
								y = y->left;
						}
						z = y;
					}
					_tree.node_count = 0;
					_tree.root = NULL;
					_tree.header->parent = NULL;
					_tree.header->left = _tree.header;
					_tree.header->right = _tree.header;
					return ;
				}
				while (first != last)
					erase(first++);
			}
			size_type	erase(const Key& key)
			{
				iterator	it = lower_bound(key);
				if (it->first == key)
				{
					erase(it);
					return 1;
				}
				else
					return 0;
			}

			void	swap(map& x)
			{
				_rep_type	tmp_tree = _tree;
				_tree = x._tree;
				x._tree = tmp_tree;
			}

			size_type	count(const Key& key) const
			{
				try {
					this->at(key);
					return 1;
				} catch (std::out_of_range &error) {
					return 0;
				}
			}

			iterator	find(const Key& key)
			{
				iterator ret = lower_bound(key);
				if (ret->first == key)
					return ret;
				return end();
			}
			const_iterator	find(const Key& key) const
			{
				const_iterator ret = lower_bound(key);
				if (ret->first == key)
					return ret;
				return end();
			}

			ft::pair<iterator,iterator>	equal_range(const Key& key)
			{
				return (make_pair(lower_bound(key), upper_bound(key)));
			}
			ft::pair<const_iterator,const_iterator>	equal_range(const Key& key) const
			{
				return make_pair(lower_bound(key), upper_bound(key));
			}

			iterator	lower_bound(const Key& key)
			{
				return _tree.lower_bound(key);
			}
			const_iterator	lower_bound(const Key& key) const
			{
				return _tree.lower_bound(key);
			}

			iterator	upper_bound(const Key& key)
			{
				return _tree.upper_bound(key);
			}
			const_iterator	upper_bound(const Key& key) const
			{
				return _tree.upper_bound(key);
			}

			key_compare	key_comp(void) const
			{
				return key_compare(_tree.key_compare);
			}

			value_compare value_comp() const
			{
				return value_compare(_tree.key_compare);
			}
	
		private:
			Allocator	_alloc;
			_rep_type	_tree;
	};

	template<class T, class Alloc, class Compare, class Allocator>
	bool	operator==(const ft::map<T,Alloc,Compare,Allocator>& lhs, const ft::map<T,Alloc,Compare,Allocator>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		typename ft::map<T,Alloc,Compare,Allocator>::const_iterator	l_it = lhs.begin();
		typename ft::map<T,Alloc,Compare,Allocator>::const_iterator	r_it = rhs.begin();
		typename ft::map<T,Alloc,Compare,Allocator>::const_iterator	l_end = lhs.end();
		typename ft::map<T,Alloc,Compare,Allocator>::const_iterator	r_end = rhs.end();
		while (l_it != l_end && r_it != r_end)
		{
			if (*l_it != *r_it)
				return false;
			l_it++;
			r_it++;
		}
		return true;
	}
	template<class T, class Alloc, class Compare, class Allocator>
	bool	operator!=(const ft::map<T,Alloc,Compare,Allocator>& lhs, const ft::map<T,Alloc,Compare,Allocator>& rhs)
	{
		return !(lhs == rhs);
	}
	template<class T, class Alloc, class Compare, class Allocator>
	bool	operator<(const ft::map<T,Alloc,Compare,Allocator>& lhs, const ft::map<T,Alloc,Compare,Allocator>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template<class T, class Alloc, class Compare, class Allocator>
	bool	operator<=(const ft::map<T,Alloc,Compare,Allocator>& lhs, const ft::map<T,Alloc,Compare,Allocator>& rhs)
	{
		return !(lhs > rhs);
	}
	template<class T, class Alloc, class Compare, class Allocator>
	bool	operator>(const ft::map<T,Alloc,Compare,Allocator>& lhs, const ft::map<T,Alloc,Compare,Allocator>& rhs)
	{
		return rhs < lhs;
	}
	template<class T, class Alloc, class Compare, class Allocator>
	bool	operator>=(const ft::map<T,Alloc,Compare,Allocator>& lhs, const ft::map<T,Alloc,Compare,Allocator>& rhs)
	{
		return !(lhs < rhs);
	}

	template<class T, class Alloc, class Compare, class Allocator>
	void	swap(map<T,Alloc,Compare,Allocator>& x, map<T,Alloc,Compare,Allocator>& y)
	{
		x.swap(y);
	}
}