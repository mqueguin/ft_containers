#include "stack.hpp"
#include "vector.hpp"
#include <stack>
#include <vector>
#include <deque>
#include <fstream>
#include <iostream>
#include "tester.hpp"

#define NC "\e[0m"
#define BOLD "\e[1m"
#define RED "\e[31m"
#define GRN "\e[1;32m"
#define CYN "\e[1;36m"
#define YEL "\e[1;33m"
#define REDB "\e[41m"

int	compare_files(const std::string &test, bool is_out_of_range, const std::string &file_name) {
	std::string name = "my_" + file_name + "_output.txt";
	std::string name2 = file_name + "_output.txt";
	std::ifstream file(name.c_str(), std::ifstream::binary|std::ifstream::ate);
	std::ifstream file2(name2.c_str(), std::ifstream::binary|std::ifstream::ate);

	if (file.fail() || file2.fail()) {
		std::cout << REDB << "Error: " << NC << "Can't open file" << (file.fail() ? name : name2) << std::endl;
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

void	resize_files(std::ofstream &file, std::ofstream &file2, const std::string &file_name) {
	std::string name = "my_" + file_name + "_output.txt";
	std::string name2 = file_name + "_output.txt";
	std::ifstream read(name.c_str(), std::ifstream::binary|std::ifstream::ate);
	std::ifstream read2(name2.c_str(), std::ifstream::binary|std::ifstream::ate);
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

int ft_stack(void) {

	std::string filename("my_stack_output.txt");
	std::ofstream file(filename.c_str());
	std::string filename2("stack_output.txt");
	std::ofstream file2(filename2.c_str());

	if (!file.is_open() || !file2.is_open()) {
		std::cout << REDB << "Error: " << NC << "Can't open file " << (!file.is_open() ? "my_stack_output.txt" : "stack_output.txt") << std::endl;
		return (1);
	}

	std::cout << BOLD "==================== " NC CYN "STACK TESTER" NC BOLD " ====================" << std::endl;
	std::cout << std::endl;

	/* CONSTRUCTORS TEST MY STACK */
  	ft::vector<int> myvector (2,200);        // vector with 2 elements

  	ft::stack<int> first;                    // empty stack
  	ft::stack<int, ft::vector<int> > second;  // empty stack using vector
  	ft::stack<int, ft::vector<int> > third (myvector);

	file << "CONSTRUCTOR TEST" << std::endl;
  	file << "size of first: " << first.size() << std::endl;
  	file << "size of second: " << second.size() << std::endl;
  	file << "size of third: " << third.size() << std::endl;
	file << std::endl;

	/* CONSTRUCTORS TEST STL STACK */
	std::vector<int> myvectorstl (2,200);        // vector with 2 elements

  	std::stack<int> firststl;                    // empty stack
  	std::stack<int, std::vector<int> > secondstl;  // empty stack using vector
  	std::stack<int, std::vector<int> > thirdstl (myvectorstl);

	file2 << "CONSTRUCTOR TEST" << std::endl;
  	file2 << "size of first: " << firststl.size() << std::endl;
  	file2 << "size of second: " << secondstl.size() << std::endl;
  	file2 << "size of third: " << thirdstl.size() << std::endl;
	file2 << std::endl;
	/* COMPARE FILES */
	if (compare_files("CONSTRUCTORS TEST", 0, "stack") == 0)
		resize_files(file, file2, "stack");

	/* EMPTY TEST MY STACK */
	ft::stack<int> mystack;
  	int sum (0);

	file << "EMPTY TEST" << std::endl;
  	for (int i = 1; i <= 10; i++) {
		file << "Push " << i << " in stack" << std::endl;
		mystack.push(i);
	}

  	while (!mystack.empty())
  	{
		file << "Pop " << mystack.top() << " from stack" << std::endl;
   		sum += mystack.top();
    	mystack.pop();
  	}

	file << "sum of all values from stack: " << sum << std::endl;
	file << std::endl;

	/* EMPTY TEST STL STACK */
	std::stack<int> stackstl;
  	sum = 0;

	file2 << "EMPTY TEST" << std::endl;
  	for (int i = 1; i <= 10; i++) {
		file2 << "Push " << i << " in stack" << std::endl;
		stackstl.push(i);
	}

  	while (!stackstl.empty())
  	{
		file2 << "Pop " << stackstl.top() << " from stack" << std::endl;
   		sum += stackstl.top();
    	stackstl.pop();
  	}

	file2 << "sum of all values from stack: " << sum << std::endl;
	file2 << std::endl;

	/* COMPARE FILES */
	if (compare_files("EMPTY TEST", 0, "stack") == 0)
		resize_files(file, file2, "stack");


	/* SIZE TEST MY STACK */
	ft::stack<int> myints;

	file << "SIZE TEST" << std::endl;
  	file << "0. size with 0 elements: " << myints.size() << std::endl;

  	for (int i = 0; i < 5; i++) {
		myints.push(i);
  		file << "1. size with " << i + 1 << " elements: " << myints.size() << std::endl;
	}

  	myints.pop();
  	file << "2. size with 4 elements: " << myints.size() << std::endl;
	file << std::endl;

	/* SIZE TEST STL STACK */
	std::stack<int> intsstl;

	file2 << "SIZE TEST" << std::endl;
  	file2 << "0. size with 0 elements: " << intsstl.size() << std::endl;

  	for (int i = 0; i < 5; i++) {
		intsstl.push(i);
  		file2 << "1. size with " << i + 1 << " elements: " << intsstl.size() << std::endl;
	}

  	intsstl.pop();
  	file2 << "2. size with 4 elements: " << intsstl.size() << std::endl;
	file2 << std::endl;

	/* COMPARE FILES */
	if (compare_files("SIZE TEST", 0, "stack") == 0)
		resize_files(file, file2, "stack");

	/* TOP TEST MY STACK */
	ft::stack<int> stacktop;

	file << "TOP TEST" << std::endl;

  	stacktop.push(10);
	file << "Push 10 in stack" << std::endl;
  	stacktop.push(20);
	file << "Push 20 in stack" << std::endl;

  	stacktop.top() -= 5;
	file << "Remove 5 from top of stack" << std::endl;

  	file << "top() is now " << stacktop.top() << std::endl;
	file << std::endl;

	/* TOP TEST STL STACK */
	std::stack<int> stacktopstl;

	file2 << "TOP TEST" << std::endl;

  	stacktopstl.push(10);
	file2 << "Push 10 in stack" << std::endl;
  	stacktopstl.push(20);
	file2 << "Push 20 in stack" << std::endl;

  	stacktopstl.top() -= 5;
	file2 << "Remove 5 from top of stack" << std::endl;

  	file2 << "top() is now " << stacktopstl.top() << std::endl;
	file2 << std::endl;

	/* COMPARE FILES */
	if (compare_files("TOP TEST", 0, "stack") == 0)
		resize_files(file, file2, "stack");

	/* PUSH TEST MY STACK */
	ft::stack<int> mystackpush;

	file << "PUSH TEST" << std::endl;
  	for (int i = 0; i < 5; ++i){
		mystackpush.push(i);
		file << "Push " << i << " in stack" << std::endl;
	}

  	file << "Popping out elements...";
  	while (!mystackpush.empty())
  	{
     	file << "Popping: " << mystackpush.top() << std::endl;
     	mystackpush.pop();
  	}
	file << "Size of stack: " << mystackpush.size() << std::endl;
  	file << std::endl;

	/* PUSH TEST STL STACK */
	std::stack<int> stackpushstl;
	file2 << "PUSH TEST" << std::endl;
  	for (int i = 0; i < 5; ++i){
		stackpushstl.push(i);
		file2 << "Push " << i << " in stack" << std::endl;
	}

  	file2 << "Popping out elements...";
  	while (!stackpushstl.empty())
  	{
     	file2 << "Popping: " << stackpushstl.top() << std::endl;
     	stackpushstl.pop();
  	}
	file2 << "Size of stack: " << stackpushstl.size() << std::endl;
  	file2 << std::endl;

	/* COMPARE FILES */
	if (compare_files("PUSH TEST", 0, "stack") == 0)
		resize_files(file, file2, "stack");

	/* POP TEST MY STACK */
	ft::stack<int> mystackpop;

	file << "POP TEST" << std::endl;
  	for (int i = 0; i < 14; ++i){
		mystackpop.push(i);
		file << "Push " << i << " in stack" << std::endl;
	}

  	while (!mystackpop.empty())
  	{
     	file << "Popping: " << mystackpop.top() << std::endl;
     	mystackpop.pop();
  	}
	file << "Size of stack: " << mystackpop.size() << std::endl;
  	file << std::endl;

	/* POP TEST STL STACK */
	std::stack<int> stackpopstl;

	file2 << "POP TEST" << std::endl;
  	for (int i = 0; i < 14; ++i){
		stackpopstl.push(i);
		file2 << "Push " << i << " in stack" << std::endl;
	}

  	while (!stackpopstl.empty())
  	{
     	file2 << "Popping: " << stackpopstl.top() << std::endl;
     	stackpopstl.pop();
  	}
	file2 << "Size of stack: " << stackpopstl.size() << std::endl;
  	file2 << std::endl;

	/* COMPARE FILES */
	if (compare_files("POP TEST", 0, "stack") == 0)
		resize_files(file, file2, "stack");

	/* RELATIONAL OPERATORS TEST MY STACK */
	ft::stack<int> a, b, c;

	file << "RELATIONAL OPERATORS TEST" << std::endl;
  	a.push(10);
  	a.push(20);
  	a.push(30);
	file << "Push 10, 20, 30 in stack a" << std::endl;
  	b.push(10);
  	b.push(20);
  	b.push(30);
	file << "Push 10, 20, 30 in stack b" << std::endl;
  	c.push(30);
  	c.push(20);
  	c.push(10);
	file << "Push 30, 20, 10 in stack c" << std::endl;

	file << "Test == operator: " << std::endl;
  	if (a == b)
		file << "a and b are equal\n";
	file << "Test != operator: " << std::endl;
  	if (b != c)
		file << "b and c are not equal\n";
	file << "Test < operator: " << std::endl;
  	if (b < c)
		file << "b is less than c\n";
	file << "Test > operator: " << std::endl;
  	if (c > b)
		file << "c is greater than b\n";
	file << "Test <= operator: " << std::endl;
  	if (a <= b)
		file << "a is less than or equal to b\n";
	file << "Test >= operator: " << std::endl;
  	if (a >= b)
		file << "a is greater than or equal to b\n";

	/* RELATIONAL OPERATORS TEST STL STACK */
	std::stack<int> a2, b2, c2;

	file2 << "RELATIONAL OPERATORS TEST" << std::endl;
  	a2.push(10);
  	a2.push(20);
  	a2.push(30);
	file2 << "Push 10, 20, 30 in stack a" << std::endl;
  	b2.push(10);
  	b2.push(20);
  	b2.push(30);
	file2 << "Push 10, 20, 30 in stack b" << std::endl;
  	c2.push(30);
  	c2.push(20);
  	c2.push(10);
	file2 << "Push 30, 20, 10 in stack c" << std::endl;

	file2 << "Test == operator: " << std::endl;
  	if (a2 == b2)
		file2 << "a and b are equal\n";
	file2 << "Test != operator: " << std::endl;
  	if (b2 != c2)
		file2 << "b and c are not equal\n";
	file2 << "Test < operator: " << std::endl;
  	if (b2 < c2)
		file2 << "b is less than c\n";
	file2 << "Test > operator: " << std::endl;
  	if (c2 > b2)
		file2 << "c is greater than b\n";
	file2 << "Test <= operator: " << std::endl;
  	if (a2 <= b2)
		file2 << "a is less than or equal to b\n";
	file2 << "Test >= operator: " << std::endl;
  	if (a2 >= b2)
		file2 << "a is greater than or equal to b\n";

	/* COMPARE FILES */
	if (compare_files("RELATIONAL OPERATORS TEST", 0, "stack") == 0)
		resize_files(file, file2, "stack");
	std::cout << std::endl;

	std::cout << BOLD "================" NC CYN " STACK TESTS FINISHED " NC BOLD "================" NC << std::endl;
	return (0);
}