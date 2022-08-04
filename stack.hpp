#pragma once

#include <iostream>
#include <fstream>
#include "vector.hpp"

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class stack {
		
		public:
			typedef Container container_type;
			typedef typename container_type::value_type value_type;
			typedef typename container_type::size_type size_type;
			container_type c;
		
		public:
			explicit stack(const container_type &container = container_type()): c(container) {}

			size_type size(void) const {
				return (c.size());
			}

			bool empty(void) const {
				return (c.empty());
			}

			void push(const value_type &val) {
				c.push_back(val);
			}

			void pop(void) {
				c.pop_back();
			}

			value_type &top(void) {
				return (c.back());
			}

			const value_type &top(void) const {
				return (c.back());
			}
	};

	template<class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs.c == rhs.c);
	}

	template<class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs.c != rhs.c);
	}

	template<class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs.c < rhs.c);
	}

	template<class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs.c > rhs.c);
	}

	template<class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs.c <= rhs.c);
	}

	template<class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs.c >= rhs.c);
	}
}