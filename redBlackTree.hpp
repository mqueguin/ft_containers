#pragma once

#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "compare.hpp"
#include "reverseIterator.hpp"

#define BLACK 0
#define RED 1

template<typename T>
struct node {
	public:
		Value *value;
		node *parent;
		node *left;
		node *right;
		bool color;
		//bool nil;

		node(void): value(), parent(NULL), left(NULL), right(NULL), color(BLACK) {}

		node(const T &val): value(val), parent(NULL), left(NULL), right(NULL), color(BLACK) {}

		node(const node &copy): value(), parent(NULL), left(NULL), right(NULL), color() {
			*this = copy;
		}

		~node(void) {}

		node &operator=(const node &rhs) {
			value = rhs.value;
			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			return (*this);
		}
};