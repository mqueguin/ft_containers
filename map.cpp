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
	

	/* ELEMENT ACCESS: AT() MY MAP */
	ft::map<std::string, int> mymap9;

	file << "ELEMENT ACCESS TESTS: AT()" << std::endl;
	mymap9["one"] = 1;
	mymap9["two"] = 2;
	mymap9["three"] = 3;
	mymap9["four"] = 4;
	mymap9["five"] = 5;

	mymap9.at("one") = 10;
	mymap9.at("two") = 20;
	mymap9.at("three") = 30;
	mymap9.at("four") = 40;
	mymap9.at("five") = 50;

	file << "Map contains: " << std::endl;
	for (ft::map<std::string, int>::iterator it = mymap9.begin(); it != mymap9.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Map contains " << mymap9.size() << " elements" << std::endl;

	file << "Modif three element with at()" << std::endl;
	mymap9.at("three") = 42;
	file << "Map contains: " << std::endl;
	for (ft::map<std::string, int>::iterator it = mymap9.begin(); it != mymap9.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Map contains " << mymap9.size() << " elements" << std::endl;
	file << "Map max size: " << mymap9.max_size() << std::endl;
	file << std::endl;

	/* ELEMENT ACCESS TESTS: AT() STL MAP */
	std::map<std::string, int> mymap9stl;

	file2 << "ELEMENT ACCESS TESTS: AT()" << std::endl;
	mymap9stl["one"] = 1;
	mymap9stl["two"] = 2;
	mymap9stl["three"] = 3;
	mymap9stl["four"] = 4;
	mymap9stl["five"] = 5;

	mymap9stl.at("one") = 10;
	mymap9stl.at("two") = 20;
	mymap9stl.at("three") = 30;
	mymap9stl.at("four") = 40;
	mymap9stl.at("five") = 50;

	file2 << "Map contains: " << std::endl;
	for (std::map<std::string, int>::iterator it = mymap9stl.begin(); it != mymap9stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Map contains " << mymap9stl.size() << " elements" << std::endl;

	file2 << "Modif three element with at()" << std::endl;
	mymap9stl.at("three") = 42;
	file2 << "Map contains: " << std::endl;
	for (std::map<std::string, int>::iterator it = mymap9stl.begin(); it != mymap9stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Map contains " << mymap9stl.size() << " elements" << std::endl;
	file2 << "Map max size: " << mymap9stl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("ELEMENT ACCESS TESTS: AT", 0) == 0)
		resize_files(file, file2);
	

	/* MODIFIERS TESTS: INSERT() MY MAP */
	ft::map<std::string, int> mymap10;

	file << "MODIFIERS TESTS: INSERT()" << std::endl;

	file << "Insert with single parameter: pair()" << std::endl;
	mymap10.insert(ft::pair<std::string, int>("one", 20));
	mymap10.insert(ft::pair<std::string, int>("two", 10));
	mymap10.insert(ft::pair<std::string, int>("three", 30));
	file << "Map contains: " << std::endl;
	for (ft::map<std::string, int>::iterator it = mymap10.begin(); it != mymap10.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Create a return value" << std::endl;
	ft::pair<ft::map<std::string, int>::iterator, bool> ret;
	ret = mymap10.insert(ft::pair<std::string, int>("two", 100));
	file << "Check the value of ret" << std::endl;
	if (ret.second == false) {
		file << "Element 'two' already existed" << std::endl;
		file << "with a value of " << ret.first->second << std::endl;
	}
	file << "Map contains: " << std::endl;
	for (ft::map<std::string, int>::iterator it = mymap10.begin(); it != mymap10.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Map contains " << mymap10.size() << " elements" << std::endl;

	file << "Insert with a position hint" << std::endl;
	mymap10.insert(mymap10.begin(), ft::pair<std::string, int>("four", 40));
	mymap10.insert(mymap10.begin(), ft::pair<std::string, int>("five", 50));
	file << "Map contains: " << std::endl;
	for (ft::map<std::string, int>::iterator it = mymap10.begin(); it != mymap10.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Map contains " << mymap10.size() << " elements" << std::endl;
	file << "Size of map: " << mymap10.size() << std::endl;

	file << "Insert with range" << std::endl;
	ft::map<std::string, int> mymap11;
	mymap11.insert(mymap10.begin(), mymap10.find("three"));
	file << "Map contains: " << std::endl;
	for (ft::map<std::string, int>::iterator it = mymap11.begin(); it != mymap11.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Size of map: " << mymap11.size() << std::endl;
	file << "Map max size: " << mymap11.max_size() << std::endl;
	file << std::endl;

	/* MODIFIERS TESTS: INSERT() STL MAP */
	std::map<std::string, int> mymap10stl;

	file2 << "MODIFIERS TESTS: INSERT()" << std::endl;

	file2 << "Insert with single parameter: pair()" << std::endl;
	mymap10stl.insert(std::pair<std::string, int>("one", 20));
	mymap10stl.insert(std::pair<std::string, int>("two", 10));
	mymap10stl.insert(std::pair<std::string, int>("three", 30));
	file2 << "Map contains: " << std::endl;
	for (std::map<std::string, int>::iterator it = mymap10stl.begin(); it != mymap10stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Create a return value" << std::endl;
	std::pair<std::map<std::string, int>::iterator, bool> retstl;
	retstl = mymap10stl.insert(std::pair<std::string, int>("two", 100));
	file2 << "Check the value of ret" << std::endl;
	if (retstl.second == false) {
		file2 << "Element 'two' already existed" << std::endl;
		file2 << "with a value of " << retstl.first->second << std::endl;
	}
	file2 << "Map contains: " << std::endl;
	for (std::map<std::string, int>::iterator it = mymap10stl.begin(); it != mymap10stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Map contains " << mymap10stl.size() << " elements" << std::endl;

	file2 << "Insert with a position hint" << std::endl;
	mymap10stl.insert(mymap10stl.begin(), std::pair<std::string, int>("four", 40));
	mymap10stl.insert(mymap10stl.begin(), std::pair<std::string, int>("five", 50));
	file2 << "Map contains: " << std::endl;
	for (std::map<std::string, int>::iterator it = mymap10stl.begin(); it != mymap10stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Map contains " << mymap10stl.size() << " elements" << std::endl;
	file2 << "Size of map: " << mymap10stl.size() << std::endl;

	file2 << "Insert with range" << std::endl;
	std::map<std::string, int> mymap11stl;
	mymap11stl.insert(mymap10stl.begin(), mymap10stl.find("three"));
	file2 << "Map contains: " << std::endl;
	for (std::map<std::string, int>::iterator it = mymap11stl.begin(); it != mymap11stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Size of map: " << mymap11stl.size() << std::endl;
	file2 << "Map max size: " << mymap11stl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("MODIFIERS TESTS: INSERT", 0) == 0)
		resize_files(file, file2);

	/* MODIFIERS TESTS: ERASE() */
	ft::map<char, int> mymap12;
	ft::map<char, int>::iterator it12;

	file << "MODIFIERS TESTS: ERASE()" << std::endl;
	file << "Insert 8 elements" << std::endl;
	mymap12['a'] = 10;
	mymap12['b'] = 20;
	mymap12['c'] = 30;
	mymap12['d'] = 40;
	mymap12['e'] = 50;
	mymap12['f'] = 60;
	mymap12['g'] = 70;
	mymap12['h'] = 80;
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap12.begin(); it != mymap12.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Map contains " << mymap12.size() << " elements" << std::endl;
	file << "Find the second element and erase it" << std::endl;
	it12 = mymap12.find('b');
	mymap12.erase(it12);
	file << "Erase third element by key" << std::endl;
	mymap12.erase('c');
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap12.begin(); it != mymap12.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Map contains " << mymap12.size() << " elements" << std::endl;
	it12 = mymap12.find('e');
	file << "Erase some elements by range" << std::endl;
	mymap12.erase(it12, mymap12.end());
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap12.begin(); it != mymap12.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Map contains " << mymap12.size() << " elements" << std::endl;
	file << "Max size of map: " << mymap12.max_size() << std::endl;
	file << std::endl;

	/* MODIFIERS TESTS: ERASE() STL MAP */
	std::map<char, int> mymap12stl;
	std::map<char, int>::iterator it12stl;

	file2 << "MODIFIERS TESTS: ERASE()" << std::endl;
	file2 << "Insert 8 elements" << std::endl;
	mymap12stl['a'] = 10;
	mymap12stl['b'] = 20;
	mymap12stl['c'] = 30;
	mymap12stl['d'] = 40;
	mymap12stl['e'] = 50;
	mymap12stl['f'] = 60;
	mymap12stl['g'] = 70;
	mymap12stl['h'] = 80;
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap12stl.begin(); it != mymap12stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Map contains " << mymap12stl.size() << " elements" << std::endl;
	file2 << "Find the second element and erase it" << std::endl;
	it12stl = mymap12stl.find('b');
	mymap12stl.erase(it12stl);
	file2 << "Erase third element by key" << std::endl;
	mymap12stl.erase('c');
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap12stl.begin(); it != mymap12stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Map contains " << mymap12stl.size() << " elements" << std::endl;
	it12stl = mymap12stl.find('e');
	file2 << "Erase some elements by range" << std::endl;
	mymap12stl.erase(it12stl, mymap12stl.end());
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap12stl.begin(); it != mymap12stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Map contains " << mymap12stl.size() << " elements" << std::endl;
	file2 << "Max size of map: " << mymap12stl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("MODIFIERS TESTS: ERASE", 0) == 0)
		resize_files(file, file2);

	/* MODIFIERS TESTS: SWAP() */
	ft::map<char, int> foo, bar;

	file << "MODIFIERS TESTS: SWAP()" << std::endl;
	file << "Insert 3 elements in first map" << std::endl;
	foo['x'] = 100;
	foo['y'] = 200;
	foo['z'] = 300;

	file << "Insert 5 elements in second map" << std::endl;
	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;
	bar['d'] = 44;
	bar['e'] = 55;

	file << "First map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Second map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	
	file << "Swap maps" << std::endl;
	foo.swap(bar);

	file << "First map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Second map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Size of first map: " << foo.size() << std::endl;
	file << "Size of second map: " << bar.size() << std::endl;
	file << std::endl;

	/* MODIFIERS TESTS: SWAP() STL MAP */
	std::map<char, int> foostl, barstl;

	file2 << "MODIFIERS TESTS: SWAP()" << std::endl;
	file2 << "Insert 3 elements in first map" << std::endl;
	foostl['x'] = 100;
	foostl['y'] = 200;
	foostl['z'] = 300;

	file2 << "Insert 5 elements in second map" << std::endl;
	barstl['a'] = 11;
	barstl['b'] = 22;
	barstl['c'] = 33;
	barstl['d'] = 44;
	barstl['e'] = 55;

	file2 << "First map contains: " << std::endl;
	for (std::map<char, int>::iterator it = foostl.begin(); it != foostl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Second map contains: " << std::endl;
	for (std::map<char, int>::iterator it = barstl.begin(); it != barstl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	
	file2 << "Swap maps" << std::endl;
	foostl.swap(barstl);

	file2 << "First map contains: " << std::endl;
	for (std::map<char, int>::iterator it = foostl.begin(); it != foostl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Second map contains: " << std::endl;
	for (std::map<char, int>::iterator it = barstl.begin(); it != barstl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Size of first map: " << foostl.size() << std::endl;
	file2 << "Size of second map: " << barstl.size() << std::endl;
	file2 << std::endl;

	if (compare_files("MODIFIERS TESTS: SWAP", 0) == 0)
		resize_files(file, file2);

	/* MODIFIERS TESTS: CLEAR() */
	ft::map<char, int> mymap13;

	file << "MODIFIERS TESTS: CLEAR()" << std::endl;
	file << "Insert 3 elements in map" << std::endl;
	mymap13['a'] = 10;
	mymap13['b'] = 20;
	mymap13['c'] = 30;

	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap13.begin(); it != mymap13.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Map contains " << mymap13.size() << " elements" << std::endl;
	file << "Clear map" << std::endl;
	mymap13.clear();
	file << "Map contains " << mymap13.size() << " elements" << std::endl;
	file << "Add new elements" << std::endl;
	mymap13['x'] = 100;
	mymap13['y'] = 200;

	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap13.begin(); it != mymap13.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Size of map: " << mymap13.size() << std::endl;
	file << "Max size of map: " << mymap13.max_size() << std::endl;
	file << std::endl;

	/* MODIFIERS TESTS: CLEAR() STL MAP */
	std::map<char, int> mymap13stl;

	file2 << "MODIFIERS TESTS: CLEAR()" << std::endl;
	file2 << "Insert 3 elements in map" << std::endl;
	mymap13stl['a'] = 10;
	mymap13stl['b'] = 20;
	mymap13stl['c'] = 30;

	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap13stl.begin(); it != mymap13stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Map contains " << mymap13stl.size() << " elements" << std::endl;
	file2 << "Clear map" << std::endl;
	mymap13stl.clear();
	file2 << "Map contains " << mymap13stl.size() << " elements" << std::endl;
	file2 << "Add new elements" << std::endl;
	mymap13stl['x'] = 100;
	mymap13stl['y'] = 200;

	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap13stl.begin(); it != mymap13stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Size of map: " << mymap13stl.size() << std::endl;
	file2 << "Max size of map: " << mymap13stl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("MODIFIERS TESTS: CLEAR", 0) == 0)
		resize_files(file, file2);
	
	/* OBSERVERS TESTS: KEY_COMP() */
	ft::map<char, int> mymap14;

	file << "OBSERVERS TESTS: KEY_COMP()" << std::endl;
	file << "Create key compare object" << std::endl;
	ft::map<char, int>::key_compare mycomp = mymap14.key_comp();

	file << "Insert elements in map" << std::endl;
	mymap14['a'] = 100;
	mymap14['b'] = 200;
	mymap14['c'] = 300;

	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap14.begin(); it != mymap14.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Recover the last element value in map" << std::endl;
	char last = mymap14.rbegin()->first;
	ft::map<char, int>::iterator itcmp = mymap14.begin();
	do {
		file << itcmp->first << " => " << itcmp->second << std::endl;
	} while (mycomp((*itcmp++).first, last));

	file << std::endl;

	/* OBSERVERS TESTS: KEY_COMP() STL MAP */
	std::map<char, int> mymap14stl;

	file2 << "OBSERVERS TESTS: KEY_COMP()" << std::endl;
	file2 << "Create key compare object" << std::endl;
	std::map<char, int>::key_compare mycompstl = mymap14stl.key_comp();

	file2 << "Insert elements in map" << std::endl;
	mymap14stl['a'] = 100;
	mymap14stl['b'] = 200;
	mymap14stl['c'] = 300;

	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap14stl.begin(); it != mymap14stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Recover the last element value in map" << std::endl;
	char laststl = mymap14stl.rbegin()->first;
	std::map<char, int>::iterator itstl2 = mymap14stl.begin();
	do {
		file2 << itstl2->first << " => " << itstl2->second << std::endl;
	} while (mycompstl((*itstl2++).first, laststl));

	file2 << std::endl;

	if (compare_files("OBSERVERS TESTS: KEY_COMP", 0) == 0)
		resize_files(file, file2);

	/* OPERATIONS TESTS: FIND() */
	ft::map<char, int> mymap15;
	ft::map<char, int>::iterator it15;

	file << "OPERATIONS TESTS: FIND()" << std::endl;
	file << "Insert elements in map" << std::endl;
	mymap15['a'] = 50;
	mymap15['b'] = 100;
	mymap15['c'] = 150;
	mymap15['d'] = 200;

	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap15.begin(); it != mymap15.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Find element with key 'b'" << std::endl;
	it15 = mymap15.find('b');
	if (it15 != mymap15.end()) {
		file << "Element found: " << it15->first << " => " << it15->second << std::endl;
		file << "Erase this element" << std::endl;
		mymap15.erase(it15);
	}
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap15.begin(); it != mymap15.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Size of map: " << mymap15.size() << std::endl;
	file << "Max size of map: " << mymap15.max_size() << std::endl;
	file << std::endl;

	/* OPERATIONS TESTS: FIND() STL MAP */
	std::map<char, int> mymap15stl;
	std::map<char, int>::iterator it15stl;

	file2 << "OPERATIONS TESTS: FIND()" << std::endl;
	file2 << "Insert elements in map" << std::endl;
	mymap15stl['a'] = 50;
	mymap15stl['b'] = 100;
	mymap15stl['c'] = 150;
	mymap15stl['d'] = 200;

	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap15stl.begin(); it != mymap15stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Find element with key 'b'" << std::endl;
	it15stl = mymap15stl.find('b');
	if (it15stl != mymap15stl.end()) {
		file2 << "Element found: " << it15stl->first << " => " << it15stl->second << std::endl;
		file2 << "Erase this element" << std::endl;
		mymap15stl.erase(it15stl);
	}
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap15stl.begin(); it != mymap15stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Size of map: " << mymap15stl.size() << std::endl;
	file2 << "Max size of map: " << mymap15stl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("OPERATIONS TESTS: FIND()", 0) == 0)
		resize_files(file, file2);
	
	/* OPERATIONS TESTS: COUNT() */
	ft::map<char, int> mymap16;
	char c;

	file << "OPERATIONS TESTS: COUNT()" << std::endl;
	file << "Insert elements in map" << std::endl;
	mymap16['a'] = 101;
	mymap16['c'] = 202;
	mymap16['f'] = 303;

	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap16.begin(); it != mymap16.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Check with count() if each element is in map" << std::endl;
	for (c = 'a'; c < 'h'; c++) {
		file << "Value of key: " << c << std::endl;
		if (mymap16.count(c) > 0)
			file << "Element with key " << c << " is in map" << std::endl;
		else
			file << "Element with key " << c << " is not in map" << std::endl;
	}
	file << std::endl;

	/* OPERATIONS TESTS: COUNT() STL MAP */
	std::map<char, int> mymap16stl;
	char cstl;

	file2 << "OPERATIONS TESTS: COUNT()" << std::endl;
	file2 << "Insert elements in map" << std::endl;
	mymap16stl['a'] = 101;
	mymap16stl['c'] = 202;
	mymap16stl['f'] = 303;

	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap16stl.begin(); it != mymap16stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Check with count() if each element is in map" << std::endl;
	for (cstl = 'a'; cstl < 'h'; cstl++) {
		file2 << "Value of key: " << cstl << std::endl;
		if (mymap16stl.count(cstl) > 0)
			file2 << "Element with key " << cstl << " is in map" << std::endl;
		else
			file2 << "Element with key " << cstl << " is not in map" << std::endl;
	}
	file2 << std::endl;

	if (compare_files("OPERATIONS TESTS: COUNT()", 0) == 0)
		resize_files(file, file2);
	
	/* OPERATIONS TESTS: LOWER_BOUND() */
	ft::map<char, int> mymap17;

	file << "OPERATIONS TESTS: LOWER_BOUND()" << std::endl;
	ft::map<char, int>::iterator itlow, itup;

	file << "Insert elements in map" << std::endl;
	mymap17['a'] = 20;
	mymap17['b'] = 40;
	mymap17['c'] = 60;
	mymap17['d'] = 80;
	mymap17['e'] = 100;

	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap17.begin(); it != mymap17.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Lower bound points to: " << std::endl;
	itlow = mymap17.lower_bound('b');
	file << itlow->first << " => " << itlow->second << std::endl;
	file << "Upper bound points to: " << std::endl;
	itup = mymap17.upper_bound('d');
	file << itup->first << " => " << itup->second << std::endl;

	file << "Erase iterator from lower bound to upper bound" << std::endl;
	mymap17.erase(itlow, itup);
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap17.begin(); it != mymap17.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << std::endl;

	/* OPERATIONS TESTS: LOWER_BOUND() STL MAP */
	std::map<char, int> mymap17stl;

	file2 << "OPERATIONS TESTS: LOWER_BOUND()" << std::endl;
	std::map<char, int>::iterator itlowstl, itupstl;

	file2 << "Insert elements in map" << std::endl;
	mymap17stl['a'] = 20;
	mymap17stl['b'] = 40;
	mymap17stl['c'] = 60;
	mymap17stl['d'] = 80;
	mymap17stl['e'] = 100;

	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap17stl.begin(); it != mymap17stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Lower bound points to: " << std::endl;
	itlowstl = mymap17stl.lower_bound('b');
	file2 << itlowstl->first << " => " << itlowstl->second << std::endl;
	file2 << "Upper bound points to: " << std::endl;
	itupstl = mymap17stl.upper_bound('d');
	file2 << itupstl->first << " => " << itupstl->second << std::endl;

	file2 << "Erase iterator from lower bound to upper bound" << std::endl;
	mymap17stl.erase(itlowstl, itupstl);
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap17stl.begin(); it != mymap17stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << std::endl;

	if (compare_files("OPERATIONS TESTS: LOWER_BOUND()", 0) == 0)
		resize_files(file, file2);
	
	/* OPERATIONS TESTS: UPPER_BOUND() */
	ft::map<char, int> mymap18;

	file << "OPERATIONS TESTS: UPPER_BOUND()" << std::endl;
	ft::map<char, int>::iterator itlow2, itup2;

	file << "Insert elements in map" << std::endl;
	mymap18['a'] = 20;
	mymap18['b'] = 40;
	mymap18['c'] = 60;
	mymap18['d'] = 80;
	mymap18['e'] = 100;

	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap18.begin(); it != mymap18.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << "Lower bound points to: " << std::endl;
	itlow2 = mymap18.lower_bound('b');
	file << itlow2->first << " => " << itlow2->second << std::endl;
	file << "Upper bound points to: " << std::endl;
	itup2 = mymap18.upper_bound('d');
	file << itup2->first << " => " << itup2->second << std::endl;

	file << "Erase iterator from lower bound to upper bound" << std::endl;
	mymap18.erase(itlow2, itup2);
	file << "Map contains: " << std::endl;
	for (ft::map<char, int>::iterator it = mymap18.begin(); it != mymap18.end(); it++)
		file << it->first << " => " << it->second << std::endl;
	file << std::endl;

	/* OPERATIONS TESTS: UPPER_BOUND() STL MAP */
	std::map<char, int> mymap18stl;

	file2 << "OPERATIONS TESTS: UPPER_BOUND()" << std::endl;
	std::map<char, int>::iterator itlow2stl, itup2stl;

	file2 << "Insert elements in map" << std::endl;
	mymap18stl['a'] = 20;
	mymap18stl['b'] = 40;
	mymap18stl['c'] = 60;
	mymap18stl['d'] = 80;
	mymap18stl['e'] = 100;

	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap18stl.begin(); it != mymap18stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << "Lower bound points to: " << std::endl;
	itlow2stl = mymap18stl.lower_bound('b');
	file2 << itlow2stl->first << " => " << itlow2stl->second << std::endl;
	file2 << "Upper bound points to: " << std::endl;
	itup2stl = mymap18stl.upper_bound('d');
	file2 << itup2stl->first << " => " << itup2stl->second << std::endl;

	file2 << "Erase iterator from lower bound to upper bound" << std::endl;
	mymap18stl.erase(itlow2stl, itup2stl);
	file2 << "Map contains: " << std::endl;
	for (std::map<char, int>::iterator it = mymap18stl.begin(); it != mymap18stl.end(); it++)
		file2 << it->first << " => " << it->second << std::endl;
	file2 << std::endl;

	if (compare_files("OPERATIONS TESTS: UPPER_BOUND()", 0) == 0)
		resize_files(file, file2);
	
	/* OPERATIONS TESTS: EQUAL_RANGE() */
	


}