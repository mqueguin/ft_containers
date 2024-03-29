#pragma once

namespace ft {
	template<class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		T1	first;
		T2	second;

		pair(void) : first(), second() {}

		pair(const T1& x, const T2& y) : first(x), second(y) {}

		template<class U1, class U2>
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

		~pair(void) {}

		pair& operator=(const pair& other) {
			first = other.first;
			second = other.second;
			return (*this);
		}
	};

	template<class T1, class T2>
	ft::pair<T1, T2>	make_pair(T1 t, T2 u) {
		return (ft::pair<T1, T2>(t, u));
	}

	template<class T1, class T2>
	bool	operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return (lhs.first == rhs.first
				&& lhs.second == rhs.second);
	}

	template<class T1, class T2>
	bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return !(lhs == rhs);
	}

	template<class T1, class T2>
	bool	operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		if (lhs.first < rhs.first)
			return (true);
		if (lhs.second < rhs.second)
			return (true);
		return (false);
	}

	template<class T1, class T2>
	bool	operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return !(lhs > rhs);
	}

	template<class T1, class T2>
	bool	operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return rhs < lhs;
	}

	template<class T1, class T2>
	bool	operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return !(lhs < rhs);
	}

	template <typename T1, typename T2, typename Res>
	struct binary_function {
		typedef T1 first_argument_type;
		typedef T2 second_argument_type;
		typedef Res result_type;
	};

	template <typename T>
	struct less: binary_function<T, T, bool> {
		bool operator()(const T &x, const T &y) const {
			return (x < y);
		}
	};

}