#pragma once

namespace ft {

	/*template <class T>
	struct is_integral {
		static const bool value = false;
	};
	template <>
	struct is_integral<bool> {
		static const bool value = true;
	};
	template <>
	struct is_integral<char> {
		static const bool value = true;
	};
	template <>
	struct is_integral<signed char> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned char> {
		static const bool value = true;
	};
	template <>
	struct is_integral<wchar_t> {
		static const bool value = true;
	};
	template <>
	struct is_integral<short int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned short int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<long int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned long int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<long long int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned long long int> {
		static const bool value = true;
	};
	
	template <bool Cond, class T = void>
	struct enable_if {};
	template <class T>
	struct enable_if<true, T> {
		typedef T type;
	};*/

	template <class T> struct is_integral { bool static const value = false; };
	template <> struct is_integral<bool> { bool static const	value = true; };
	template <> struct is_integral<char> { bool static const value = true; };
	template <> struct is_integral<wchar_t> { bool static const	value = true; };
	template <> struct is_integral<signed char> { bool static const	value = true; };
	template <> struct is_integral<short int> { bool static const	value = true; };
	template <> struct is_integral<int> { bool static const	value = true; };
	template <> struct is_integral<long int> { bool static const	value = true; };
	template <> struct is_integral<long long int> { bool static const	value = true; };
	template <> struct is_integral<unsigned char> { bool static const	value = true; };
	template <> struct is_integral<unsigned short int> { bool static const	value = true; };
	template <> struct is_integral<unsigned int> { bool static const	value = true; };
	template <> struct is_integral<unsigned long int> { bool static const	value = true; };
	template <> struct is_integral<unsigned long long int> { bool static const	value = true; };

	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };
}
