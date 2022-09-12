#include <map>
#include <deque>
#include <fstream>
#include <iostream>
#include "includes/map.hpp"

#define NC "\e[0m"
#define BOLD "\e[1m"
#define RED "\e[31m"
#define GRN "\e[1;32m"
#define CYN "\e[1;36m"
#define YEL "\e[1;33m"
#define REDB "\e[41m"

int	compare_files(const std::string &test, bool is_out_of_range) {
	std::ifstream file("my_map_output.txt", std::ifstream::binary|std::ifstream::ate);
	std::ifstream file2("map_output.txt", std::ifstream::binary|std::ifstream::ate);

	if (file.fail() || file2.fail()) {
		std::cout << REDB << "Error: " << NC << "Can't open file" << (file.fail() ? "my_map_output.txt" : "map_output.txt") << std::endl;
		return (2);
	}

	if (is_out_of_range) {
		std::cout << " " BOLD << test << ":" NC " " GRN "OK " NC YEL "(output differs because throw error is not the same)" NC << std::endl;
		return (0);
	}

	if (file.tellg() != file2.tellg()) {
		std::cout << " " BOLD << test << ":" NC " " RED "KO (output differs)" NC << std::endl;
		return (0);
	}

	std::cout << " " BOLD << test << ":" NC " " GRN "OK" NC << std::endl;
	return (1);
}

void	resize_files(std::ofstream &file, std::ofstream &file2) {
	std::ifstream read("my_map_output.txt", std::ifstream::binary|std::ifstream::ate);
	std::ifstream read2("map_output.txt", std::ifstream::binary|std::ifstream::ate);
	if (read.tellg() > read2.tellg()) {
		for (int i = 0; i < (read.tellg() - read2.tellg()) - 1; i++)
			file2 << " ";
		file2 << std::endl;
	} else {
		for (int i = 0; i < (read2.tellg() - read.tellg()) - 1; i++)
			file << " ";
		file << std::endl;
	}
}

/* Function for testing map */
bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{ return lhs < rhs; }
};

int main(void) {

	std::string filename("my_map_output.txt");
	std::ofstream file(filename.c_str());
	std::string filename2("map_output.txt");
	std::ofstream file2(filename2.c_str());

	if (!file.is_open() || !file2.is_open()) {
		std::cout << REDB << "Error: " << NC << "Can't open file " << (!file.is_open() ? "my_map_output.txt" : "map_output.txt") << std::endl;
		return (1);
	}

	std::cout << BOLD "==================== " NC CYN "MAP TESTER" NC BOLD " ====================" << std::endl;
	std::cout << std::endl;

	/* CONSTRUCTORS TESTS MY MAP*/
	ft::map<char, int> first;

	file << "CONSTRUCTORS TESTS" << std::endl;
	file << "Create a map with default constructor" << std::endl;
	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = first.begin(); it != first.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Create a second map with range constructor" << std::endl;
	ft::map<char, int> second(first.begin(), first.end());
	file << "Second map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = second.begin(); it != second.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Create a third map with copy constructor" << std::endl;
	ft::map<char, int> third(second);
	file << "Third map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = third.begin(); it != third.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Create a fourth map with a comparison function" << std::endl;
	ft::map<char, int, classcomp> fourth;                 // class as Compare
	file << "Fourth map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = fourth.begin(); it != fourth.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	bool(*fn_pt)(char, char) = fncomp;
	ft::map<char, int, bool(*)(char, char)> fifth(fn_pt); // function pointer as Compare
	file << "Fifth map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Size of first map: " << first.size() << std::endl;
	file << "Size of second map: " << second.size() << std::endl;
	file << "Size of third map: " << third.size() << std::endl;
	file << "Size of fourth map: " << fourth.size() << std::endl;
	file << "Size of fifth map: " << fifth.size() << std::endl;
	file << std::endl;

	/* CONSTRUCTORS TESTS STL MAP */
	std::map<char, int> firststl;

	file2 << "CONSTRUCTORS TESTS" << std::endl;
	file2 << "Create a map with default constructor" << std::endl;
	firststl['a'] = 10;
	firststl['b'] = 30;
	firststl['c'] = 50;
	firststl['d'] = 70;
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = firststl.begin(); it != firststl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Create a second map with range constructor" << std::endl;
	std::map<char, int> secondstl(firststl.begin(), firststl.end());
	file2 << "Second map contains: " << std::endl;
	for (std::map<char, int>::iterator it = secondstl.begin(); it != secondstl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Create a third map with copy constructor" << std::endl;
	std::map<char, int> thirdstl(secondstl);
	file2 << "Third map contains: " << std::endl;
	for (std::map<char, int>::iterator it = thirdstl.begin(); it != thirdstl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Create a fourth map with a comparison function" << std::endl;
	std::map<char, int, classcomp> fourthstl;                 // class as Compare
	file2 << "Fourth map contains: " << std::endl;
	for (std::map<char, int>::iterator it = fourthstl.begin(); it != fourthstl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	bool(*fn_ptstl)(char, char) = fncomp;
	std::map<char, int, bool(*)(char, char)> fifthstl(fn_ptstl); // function pointer as Compare
	file2 << "Fifth map contains: " << std::endl;
	for (std::map<char, int>::iterator it = fifthstl.begin(); it != fifthstl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Size of first map: " << firststl.size() << std::endl;
	file2 << "Size of second map: " << secondstl.size() << std::endl;
	file2 << "Size of third map: " << thirdstl.size() << std::endl;
	file2 << "Size of fourth map: " << fourthstl.size() << std::endl;
	file2 << "Size of fifth map: " << fifthstl.size() << std::endl;
	file2 << std::endl;

	if (compare_files("CONSTRUCTORS TESTS", 0) == 0)
		resize_files(file, file2);

	/* OPERATOR= TESTS MY MAP */
	ft::map<char, int> first2;
	ft::map<char, int> second2;

	file << "OPERATOR= TESTS" << std::endl;
	file << "Create a map with default constructor" << std::endl;
	first2['x'] = 100;
	first2['y'] = 200;
	first2['z'] = 300;
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = first2.begin(); it != first2.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Create a second map with overload operator=" << std::endl;
	second2 = first2;
	file << "Second map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = second2.begin(); it != second2.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Size of first map: " << first2.size() << std::endl;
	file << "Size of second map: " << second2.size() << std::endl;
	file << std::endl;

	/* OPERATOR= TESTS STL MAP */
	std::map<char, int> first2stl;
	std::map<char, int> second2stl;

	file2 << "OPERATOR= TESTS" << std::endl;
	file2 << "Create a map with default constructor" << std::endl;
	first2stl['x'] = 100;
	first2stl['y'] = 200;
	first2stl['z'] = 300;
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = first2stl.begin(); it != first2stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Create a second map with overload operator=" << std::endl;
	second2stl = first2stl;
	file2 << "Second map contains: " << std::endl;
	for (std::map<char, int>::iterator it = second2stl.begin(); it != second2stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Size of first map: " << first2stl.size() << std::endl;
	file2 << "Size of second map: " << second2stl.size() << std::endl;
	file2 << std::endl;

	if (compare_files("OPERATOR= TESTS", 0) == 0)
		resize_files(file, file2);

	/* ITERATORS TESTS: BEGIN() MY MAP */
	ft::map<char, int> mymap;

	file << "ITERATORS TESTS: BEGIN()" << std::endl;
	file << "Create a map and assign 3 elements" << std::endl;
	for (char c = 'a', i = 10; c <= 'c'; c++, i *= 12)
		mymap[c] = i;
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "First element of the map: " << mymap.begin()->first << " => " << mymap.begin()->second << std::endl;
	file << "Size of the map: " << mymap.size() << std::endl;
	file << "Max size of the map: " << mymap.max_size() << std::endl;
	file << std::endl;

	/* ITERATORS TESTS: BEGIN() STL MAP */
	std::map<char, int> mymapstl;

	file2 << "ITERATORS TESTS: BEGIN()" << std::endl;
	file2 << "Create a map and assign 3 elements" << std::endl;
	for (char c = 'a', i = 10; c <= 'c'; c++, i *= 12)
		mymapstl[c] = i;
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymapstl.begin(); it != mymapstl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "First element of the map: " << mymapstl.begin()->first << " => " << mymapstl.begin()->second << std::endl;
	file2 << "Size of the map: " << mymapstl.size() << std::endl;
	file2 << "Max size of the map: " << mymapstl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("ITERATORS TESTS: BEGIN()", 0) == 0)
		resize_files(file, file2);
	

	/* ITERATORS TESTS: END() MY MAP */
	ft::map<char, int> mymap2;

	file << "ITERATORS TESTS: END()" << std::endl;
	file << "Create a map and assign some elements" << std::endl;
	for (char c = 'a', i = 8; c <= 'c'; c++, i *= 12)
		mymap2[c] = i;
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap2.begin(); it != mymap2.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Last element of the map: " << (--mymap2.end())->first << " => " << (--mymap2.end())->second << std::endl;
	file << "Size of the map: " << mymap2.size() << std::endl;
	file << "Max size of the map: " << mymap2.max_size() << std::endl;
	file << std::endl;

	/* ITERATORS TESTS: END() STL MAP */
	std::map<char, int> mymap2stl;

	file2 << "ITERATORS TESTS: END()" << std::endl;
	file2 << "Create a map and assign some elements" << std::endl;
	for (char c = 'a', i = 8; c <= 'c'; c++, i *= 12)
		mymap2stl[c] = i;
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap2stl.begin(); it != mymap2stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Last element of the map: " << (--mymap2stl.end())->first << " => " << (--mymap2stl.end())->second << std::endl;
	file2 << "Size of the map: " << mymap2stl.size() << std::endl;
	file2 << "Max size of the map: " << mymap2stl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("ITERATORS TESTS: END()", 0) == 0)
		resize_files(file, file2);
	

	/* ITERATORS TESTS: RBEGIN() MY MAP */
	ft::map<char, int> mymap3;

	file << "ITERATORS TESTS: RBEGIN()" << std::endl;
	file << "Create a map and assign some elements" << std::endl;
	for (char c = 'a', i = 8; c <= 'c'; c++, i *= 12)
		mymap3[c] = i;
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::reverse_iterator it = mymap3.rbegin(); it != mymap3.rend(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "First element of the map: " << mymap3.rbegin()->first << " => " << mymap3.rbegin()->second << std::endl;
	file << "Size of the map: " << mymap3.size() << std::endl;
	file << "Max size of the map: " << mymap3.max_size() << std::endl;
	file << std::endl;

	/* ITERATORS TESTS: RBEGIN() STL MAP */
	std::map<char, int> mymap3stl;

	file2 << "ITERATORS TESTS: RBEGIN()" << std::endl;
	file2 << "Create a map and assign some elements" << std::endl;
	for (char c = 'a', i = 8; c <= 'c'; c++, i *= 12)
		mymap3stl[c] = i;
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::reverse_iterator it = mymap3stl.rbegin(); it != mymap3stl.rend(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "First element of the map: " << mymap3stl.rbegin()->first << " => " << mymap3stl.rbegin()->second << std::endl;
	file2 << "Size of the map: " << mymap3stl.size() << std::endl;
	file2 << "Max size of the map: " << mymap3stl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("ITERATORS TESTS: RBEGIN()", 0) == 0)
		resize_files(file, file2);
	

	/* ITERATORS TESTS: REND() MY MAP */
	ft::map<char, int> mymap4;

	file << "ITERATORS TESTS: REND()" << std::endl;
	file << "Create a map and assign some elements" << std::endl;
	for (char c = 'a', i = 8; c <= 'c'; c++, i *= 12)
		mymap4[c] = i;
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::reverse_iterator it = mymap4.rbegin(); it != mymap4.rend(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Last element of the map: " << (--mymap4.rend())->first << " => " << (--mymap4.rend())->second << std::endl;
	file << "Size of the map: " << mymap4.size() << std::endl;
	file << "Max size of the map: " << mymap4.max_size() << std::endl;
	file << std::endl;

	/* ITERATORS TESTS: REND() STL MAP */
	std::map<char, int> mymap4stl;

	file2 << "ITERATORS TESTS: REND()" << std::endl;
	file2 << "Create a map and assign some elements" << std::endl;
	for (char c = 'a', i = 8; c <= 'c'; c++, i *= 12)
		mymap4stl[c] = i;
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::reverse_iterator it = mymap4stl.rbegin(); it != mymap4stl.rend(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Last element of the map: " << (--mymap4stl.rend())->first << " => " << (--mymap4stl.rend())->second << std::endl;
	file2 << "Size of the map: " << mymap4stl.size() << std::endl;
	file2 << "Max size of the map: " << mymap4stl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("ITERATORS TESTS: REND()", 0) == 0)
		resize_files(file, file2);
	

	/* ICAPACITY TESTS: EMPTY() MY MAP */
	ft::map<char, int> mymap5;

	file << "CAPACITY TESTS: EMPTY()" << std::endl;
	file << "Create a map and assign some elements" << std::endl;
	for (char c = 'c', i = 45; c <= 'g'; c++, i *= 3)
		mymap5[c] = i;
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap5.begin(); it != mymap5.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Is the map empty? " << mymap5.empty() << std::endl;
	file << "Size of the map: " << mymap5.size() << std::endl;
	file << "Max size of the map: " << mymap5.max_size() << std::endl;
	file << "Erase all elements of the map" << std::endl;
	mymap5.erase(mymap5.begin(), mymap5.end());
	file << "Is the map empty? " << mymap5.empty() << std::endl;
	file << "Size of the map: " << mymap5.size() << std::endl;
	file << "Max size of the map: " << mymap5.max_size() << std::endl;
	file << std::endl;

	/* CAPACITY TESTS: EMPTY() STL MAP */
	std::map<char, int> mymap5stl;

	file2 << "CAPACITY TESTS: EMPTY()" << std::endl;
	file2 << "Create a map and assign some elements" << std::endl;
	for (char c = 'c', i = 45; c <= 'g'; c++, i *= 3)
		mymap5stl[c] = i;
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap5stl.begin(); it != mymap5stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Is the map empty? " << mymap5stl.empty() << std::endl;
	file2 << "Size of the map: " << mymap5stl.size() << std::endl;
	file2 << "Max size of the map: " << mymap5stl.max_size() << std::endl;
	file2 << "Erase all elements of the map" << std::endl;
	mymap5stl.erase(mymap5stl.begin(), mymap5stl.end());
	file2 << "Is the map empty? " << mymap5stl.empty() << std::endl;
	file2 << "Size of the map: " << mymap5stl.size() << std::endl;
	file2 << "Max size of the map: " << mymap5stl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("CAPACITY TESTS: EMPTY()", 0) == 0)
		resize_files(file, file2);
	

	/* CAPACITY TESTS: SIZE() MY MAP */
	ft::map<char, int> mymap6;

	file << "CAPACITY TESTS: SIZE()" << std::endl;
	file << "Create a map and assign some elements" << std::endl;
	for (char c = 'a', i = 22; c <= 'd'; c++, i *= 3)
		mymap6[c] = i;

	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap6.begin(); it != mymap6.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Size of the map: " << mymap6.size() << std::endl;
	file << "Max size of the map: " << mymap6.max_size() << std::endl;
	file << "Erase the second element of the map" << std::endl;
	ft::map<char, int>::iterator it = mymap6.find('b');
	mymap6.erase(it);
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap6.begin(); it != mymap6.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Size of the map: " << mymap6.size() << std::endl;
	file << "Max size of the map: " << mymap6.max_size() << std::endl;
	file << "Erase all elements of the map" << std::endl;
	mymap6.erase(mymap6.begin(), mymap6.end());
	file << "Size of the map: " << mymap6.size() << std::endl;
	file << "Max size of the map: " << mymap6.max_size() << std::endl;
	file << std::endl;

	/* CAPACITY TESTS: SIZE() STL MAP */
	std::map<char, int> mymap6stl;

	file2 << "CAPACITY TESTS: SIZE()" << std::endl;
	file2 << "Create a map and assign some elements" << std::endl;
	for (char c = 'a', i = 22; c <= 'd'; c++, i *= 3)
		mymap6stl[c] = i;

	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap6stl.begin(); it != mymap6stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Size of the map: " << mymap6stl.size() << std::endl;
	file2 << "Max size of the map: " << mymap6stl.max_size() << std::endl;
	file2 << "Erase the second element of the map" << std::endl;
	std::map<char, int>::iterator it2 = mymap6stl.find('b');
	mymap6stl.erase(it2);
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap6stl.begin(); it != mymap6stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Size of the map: " << mymap6stl.size() << std::endl;
	file2 << "Max size of the map: " << mymap6stl.max_size() << std::endl;
	file2 << "Erase all elements of the map" << std::endl;
	mymap6stl.erase(mymap6stl.begin(), mymap6stl.end());
	file2 << "Size of the map: " << mymap6stl.size() << std::endl;
	file2 << "Max size of the map: " << mymap6stl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("CAPACITY TESTS: SIZE()", 0) == 0)
		resize_files(file, file2);
	

	/* CAPACITY TESTS: MAX_SIZE() MY MAP */
	ft::map<char, int> mymap7;

	file << "CAPACITY TESTS: MAX_SIZE()" << std::endl;
	file << "Assign 1000 elements in the vector" << std::endl;
	if (mymap7.max_size() > 1000) {
		for (int i = 0; i < 1000; i++)
			mymap7[i] = i;
		file << "The map contains 1000 elements" << std::endl;
	} else {
		file << "The map can't contain 1000 elements" << std::endl;
	}
	file << "Max size of the map: " << mymap7.max_size() << std::endl;
	file << "Size of the map: " << mymap7.size() << std::endl;
	file << std::endl;

	/* CAPACITY TESTS: MAX_SIZE() STL MAP */
	std::map<char, int> mymap7stl;

	file2 << "CAPACITY TESTS: MAX_SIZE()" << std::endl;
	file2 << "Assign 1000 elements in the vector" << std::endl;
	if (mymap7stl.max_size() > 1000) {
		for (int i = 0; i < 1000; i++)
			mymap7stl[i] = i;
		file2 << "The map contains 1000 elements" << std::endl;
	} else {
		file2 << "The map can't contain 1000 elements" << std::endl;
	}
	file2 << "Max size of the map: " << mymap7stl.max_size() << std::endl;
	file2 << "Size of the map: " << mymap7stl.size() << std::endl;
	file2 << std::endl;

	if (compare_files("CAPACITY TESTS: MAX_SIZE()", 0) == 0)
		resize_files(file, file2);

	/* ELEMENT ACCESS TESTS: OPERATOR[] MY MAP */
	ft::map<char, std::string> mymap8;

	file << "ELEMENT ACCESS TESTS: OPERATOR[]" << std::endl;
	file << "Assign 5 elements in the map" << std::endl;
	mymap8['a'] = "an element";
	mymap8['b'] = "another element";
	mymap8['c'] = "yet another element";
	mymap8['d'] = mymap8['a'];
	mymap8['e'] = mymap8['c'];
	file << "Map contains: " << std::endl;
	for (ft::map<char, std::string>::iterator it = mymap8.begin(); it != mymap8.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "map['a'] = " << mymap8['a'] << std::endl;
	file << "map['b'] = " << mymap8['b'] << std::endl;
	file << "map['c'] = " << mymap8['c'] << std::endl;
	file << "map['d'] = " << mymap8['d'] << std::endl;
	file << "map['e'] = " << mymap8['e'] << std::endl;

	file << "Map contains " << mymap8.size() << " elements" << std::endl;
	file << std::endl;

	/* ELEMENT ACCESS TESTS: OPERATOR[] STL MAP */
	std::map<char, std::string> mymap8stl;

	file2 << "ELEMENT ACCESS TESTS: OPERATOR[]" << std::endl;
	file2 << "Assign 5 elements in the map" << std::endl;
	mymap8stl['a'] = "an element";
	mymap8stl['b'] = "another element";
	mymap8stl['c'] = "yet another element";
	mymap8stl['d'] = mymap8stl['a'];
	mymap8stl['e'] = mymap8stl['c'];
	file2 << "Map contains: " << std::endl;
	for (std::map<char, std::string>::iterator it = mymap8stl.begin(); it != mymap8stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "map['a'] = " << mymap8stl['a'] << std::endl;
	file2 << "map['b'] = " << mymap8stl['b'] << std::endl;
	file2 << "map['c'] = " << mymap8stl['c'] << std::endl;
	file2 << "map['d'] = " << mymap8stl['d'] << std::endl;
	file2 << "map['e'] = " << mymap8stl['e'] << std::endl;

	file2 << "Map contains " << mymap8stl.size() << " elements" << std::endl;
	file2 << std::endl;

	if (compare_files("ELEMENT ACCESS TESTS: OPERATOR[]", 0) == 0)
		resize_files(file, file2);
	

	/* MODIFIERS TESTS: INSERT MY MAP */
	




}