#include <vector>
#include <deque>
#include <fstream>
#include <iostream>
#include "vector.hpp"
#include "tester.hpp"

#define NC "\e[0m"
#define BOLD "\e[1m"
#define RED "\e[31m"
#define GRN "\e[1;32m"
#define CYN "\e[1;36m"
#define YEL "\e[1;33m"
#define REDB "\e[41m"

int ft_vector(void) {

	std::string filename("my_vector_output.txt");
	std::ofstream file(filename.c_str());
	std::string filename2("vector_output.txt");
	std::ofstream file2(filename2.c_str());

	if (!file.is_open() || !file2.is_open()) {
		std::cout << REDB << "Error: " << NC << "Can't open file " << (!file.is_open() ? "my_vector_output.txt" : "vector_output.txt") << std::endl;
		return (1);
	}

	std::cout << BOLD "==================== " NC CYN "VECTOR TESTER" NC BOLD " ====================" << std::endl;
	std::cout << std::endl;

	/* CONSTRUCTORS TESTS MY VECTOR */
	ft::vector<int> first;                                // empty vector of ints
  	ft::vector<int> second (4,100);                       // four ints with value 100
  	ft::vector<int> third (second.begin(),second.end());  // iterating through second
  	ft::vector<int> fourth (third);                       // a copy of third

	file << "CONSTRUCTORS TESTS" << std::endl;
	file << "Create empty vector: " << first.size() << std::endl;

	file << "Create vector with 4 ints with value 100: " << second.size() << std::endl;
	file << "and his content: ";
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
		file << *it << " ";
	file << std::endl;

	file << "Create vector with iterator: " << third.size() << std::endl;
	file << "and his content: ";
	for (ft::vector<int>::iterator it = third.begin(); it != third.end(); it++)
		file << *it << " ";
	file << std::endl;

	file << "Create vector with copy constructor: " << fourth.size() << std::endl;
	file << "and his content: ";
	for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
		file << *it << " ";
	file << std::endl;

  	// the iterator constructor can also be used to construct from arrays:
  	int myints[] = {16,2,77,29};
  	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	
	file << "Create vector with array: " << fifth.size() << std::endl;
  	file << "The contents of fifth are:";
  	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    	file << ' ' << *it;
  	file << std::endl;
	file << std::endl;

	/* CONSTRUCTORS TESTS STL VECTOR */
	std::vector<int> firststl;                                // empty vector of ints
  	std::vector<int> secondstl (4,100);                       // four ints with value 100
  	std::vector<int> thirdstl (secondstl.begin(),secondstl.end());  // iterating through second
  	std::vector<int> fourthstl (thirdstl);                       // a copy of third

	file2 << "CONSTRUCTORS TESTS" << std::endl;
	file2 << "Create empty vector: " << firststl.size() << std::endl;

	file2 << "Create vector with 4 ints with value 100: " << secondstl.size() << std::endl;
	file2 << "and his content: ";
	for (std::vector<int>::iterator it = secondstl.begin(); it != secondstl.end(); it++)
		file2 << *it << " ";
	file2 << std::endl;

	file2 << "Create vector with iterator: " << thirdstl.size() << std::endl;
	file2 << "and his content: ";
	for (std::vector<int>::iterator it = thirdstl.begin(); it != thirdstl.end(); it++)
		file2 << *it << " ";
	file2 << std::endl;

	file2 << "Create vector with copy constructor: " << fourthstl.size() << std::endl;
	file2 << "and his content: ";
	for (std::vector<int>::iterator it = fourthstl.begin(); it != fourthstl.end(); it++)
		file2 << *it << " ";
	file2 << std::endl;

  	// the iterator constructor can also be used to construct from arrays:
  	std::vector<int> fifthstl (myints, myints + sizeof(myints) / sizeof(int) );
	
	file2 << "Create vector with array: " << fifthstl.size() << std::endl;
  	file2 << "The contents of fifth are:";
  	for (std::vector<int>::iterator it = fifthstl.begin(); it != fifthstl.end(); ++it)
    	file2 << ' ' << *it;
  	file2 << std::endl;
	file2 << std::endl;

	if (compare_files("CONSTRUCTORS TEST", 0, "vector") == 0)
		resize_files(file, file2, "vector");
	
	/* OPERATOR= TESTS MY VECTOR */
	ft::vector<int> foo (3,0);
  	ft::vector<int> bar (5,0);

	file << "OPERATOR= TESTS" << std::endl;
	file << "Create vector foo with 3 ints with value 0: " << foo.size() << std::endl;
	file << "foo content: ";
	for (ft::vector<int>::iterator it = foo.begin(); it != foo.end(); it++)
		file << *it << " ";
	file << std::endl;
	file << "Create vector bar with 5 ints with value 0: " << bar.size() << std::endl;
	file << "bar content: ";
	for (ft::vector<int>::iterator it = bar.begin(); it != bar.end(); it++)
		file << *it << " ";
	file << std::endl;
	file << "Assign bar to foo" << std::endl;
  	foo = bar;
	file << "foo content: ";
	for (ft::vector<int>::iterator it = foo.begin(); it != foo.end(); it++)
		file << *it << " ";
	file << std::endl;
  	bar = ft::vector<int>();
	file << "Assign empty vector to bar" << std::endl;
	file << "Size of bar: " << bar.size() << std::endl;
	file << "Size of foo: " << foo.size() << std::endl;
	file << std::endl;

	/* OPERATOR= TESTS STL VECTOR */
	std::vector<int> foostl (3,0);
  	std::vector<int> barstl (5,0);

	file2 << "OPERATOR= TESTS" << std::endl;
	file2 << "Create vector foo with 3 ints with value 0: " << foostl.size() << std::endl;
	file2 << "foo content: ";
	for (std::vector<int>::iterator it = foostl.begin(); it != foostl.end(); it++)
		file2 << *it << " ";
	file2 << std::endl;
	file2 << "Create vector bar with 5 ints with value 0: " << barstl.size() << std::endl;
	file2 << "bar content: ";
	for (std::vector<int>::iterator it = barstl.begin(); it != barstl.end(); it++)
		file2 << *it << " ";
	file2 << std::endl;
	file2 << "Assign bar to foo" << std::endl;
  	foostl = barstl;
	file2 << "foo content: ";
	for (std::vector<int>::iterator it = foostl.begin(); it != foostl.end(); it++)
		file2 << *it << " ";
	file2 << std::endl;
  	barstl = std::vector<int>();
	file2 << "Assign empty vector to bar" << std::endl;
	file2 << "Size of bar: " << barstl.size() << std::endl;
	file2 << "Size of foo: " << foostl.size() << std::endl;
	file2 << std::endl;

	if (compare_files("OPERATOR= TEST", 0, "vector") == 0)
		resize_files(file, file2, "vector");

	/* ITERATORS TESTS: BEGIN() MY VECTOR */
	ft::vector<int> myvector;

	file << "ITERATORS TESTS BEGIN()" << std::endl;
  	for (int i = 1; i <= 5; i++) {
		file << "Push back: " << i << std::endl;
		myvector.push_back(i);
	}
	file << "myvector contains:";
  	for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		file << ' ' << *it;
  	file << std::endl;
	file << "Valeur de begin(): " << *myvector.begin() << std::endl;
	file << "Valeur de begin() + 3: " << *(myvector.begin() + 3) << std::endl;
	file << std::endl;


	/* ITERATORS TESTS: BEGIN() STL VECTOR */
	std::vector<int> myvectorstl;

	file2 << "ITERATORS TESTS BEGIN()" << std::endl;
  	for (int i = 1; i <= 5; i++) {
		file2 << "Push back: " << i << std::endl;
		myvectorstl.push_back(i);
	}
	file2 << "myvector contains:";
  	for (std::vector<int>::iterator it = myvectorstl.begin() ; it != myvectorstl.end(); ++it)
		file2 << ' ' << *it;
  	file2 << std::endl;
	file2 << "Valeur de begin(): " << *myvectorstl.begin() << std::endl;
	file2 << "Valeur de begin() + 3: " << *(myvectorstl.begin() + 3) << std::endl;
	file2 << std::endl;

	if (compare_files("ITERATORS TESTS BEGIN()", 0, "vector") == 0)
		resize_files(file, file2, "vector");


	/* ITERATORS TESTS: END() MY VECTOR */
	ft::vector<int> myvector2;

	file << "ITERATORS TESTS END()" << std::endl;
  	for (int i = 1; i <= 8; i++) {
		file << "Push back: " << i << std::endl;
		myvector2.push_back(i);
	}
	file << "myvector contains:";
  	for (ft::vector<int>::iterator it = myvector2.begin() ; it != myvector2.end(); ++it)
		file << ' ' << *it;
  	file << std::endl;
	file << "Valeur de end() - 3: " << *(myvector2.end() - 3) << std::endl;
	file << "Valeur de end() - 7: " << *(myvector2.end() - 7) << std::endl;
	file << "Valeur de end() - begin(): " << myvector2.end() - myvector2.begin() << std::endl;
	file << std::endl;


	/* ITERATORS TESTS: END() STL VECTOR */
	std::vector<int> myvectorstl2;

	file2 << "ITERATORS TESTS END()" << std::endl;
  	for (int i = 1; i <= 8; i++) {
		file2 << "Push back: " << i << std::endl;
		myvectorstl2.push_back(i);
	}
	file2 << "myvector contains:";
  	for (std::vector<int>::iterator it = myvectorstl2.begin() ; it != myvectorstl2.end(); ++it)
		file2 << ' ' << *it;
  	file2 << std::endl;
	file2 << "Valeur de end() - 3: " << *(myvectorstl2.end() - 3) << std::endl;
	file2 << "Valeur de end() - 7: " << *(myvectorstl2.end() - 7) << std::endl;
	file2 << "Valeur de end() - begin(): " << myvectorstl2.end() - myvectorstl2.begin() << std::endl;
	file2 << std::endl;

	if (compare_files("ITERATORS TESTS END()", 0, "vector") == 0)
		resize_files(file, file2, "vector");

	
	/* ITERATORS TESTS: RBEGIN() MY VECTOR */
	ft::vector<int> myvector3;

	file << "ITERATORS TESTS RBEGIN()" << std::endl;
  	for (int i = 1; i <= 5; i++) {
		file << "Push back: " << i << std::endl;
		myvector3.push_back(i);
	}
	file << "myvector contains:";
  	for (ft::vector<int>::reverse_iterator it = myvector3.rbegin() ; it != myvector3.rend(); ++it)
		file << ' ' << *it;
  	file << std::endl;
	file << "Valeur de rbegin(): " << *myvector3.rbegin() << std::endl;
	file << "Valeur de rbegin() + 3: " << *(myvector3.rbegin() + 3) << std::endl;
	file << std::endl;


	/* ITERATORS TESTS: RBEGIN() STL VECTOR */
	std::vector<int> myvectorstl3;

	file2 << "ITERATORS TESTS RBEGIN()" << std::endl;
  	for (int i = 1; i <= 5; i++) {
		file2 << "Push back: " << i << std::endl;
		myvectorstl3.push_back(i);
	}
	file2 << "myvector contains:";
  	for (std::vector<int>::reverse_iterator it = myvectorstl3.rbegin() ; it != myvectorstl3.rend(); ++it)
		file2 << ' ' << *it;
  	file2 << std::endl;
	file2 << "Valeur de rbegin(): " << *myvectorstl3.rbegin() << std::endl;
	file2 << "Valeur de rbegin() + 3: " << *(myvectorstl3.rbegin() + 3) << std::endl;
	file2 << std::endl;

	if (compare_files("ITERATORS TESTS RBEGIN()", 0, "vector") == 0)
		resize_files(file, file2, "vector");

	
	/* ITERATORS TESTS: REND() MY VECTOR */
	ft::vector<int> myvector4;

	file << "ITERATORS TESTS REND()" << std::endl;
  	for (int i = 1; i <= 5; i++) {
		file << "Push back: " << i << std::endl;
		myvector4.push_back(i);
	}
	file << "myvector contains:";
  	for (ft::vector<int>::reverse_iterator it = myvector4.rbegin() ; it != myvector4.rend(); ++it)
		file << ' ' << *it;
  	file << std::endl;
	file << "Valeur de rend() - rbegin(): " << myvector4.rend() - myvector4.rbegin() << std::endl;
	file << std::endl;


	/* ITERATORS TESTS: REND() STL VECTOR */
	std::vector<int> myvectorstl4;

	file2 << "ITERATORS TESTS REND()" << std::endl;
  	for (int i = 1; i <= 5; i++) {
		file2 << "Push back: " << i << std::endl;
		myvectorstl4.push_back(i);
	}
	file2 << "myvector contains:";
  	for (std::vector<int>::reverse_iterator it = myvectorstl4.rbegin() ; it != myvectorstl4.rend(); ++it)
		file2 << ' ' << *it;
  	file2 << std::endl;
	file2 << "Valeur de rend() - rbegin(): " << myvectorstl4.rend() - myvectorstl4.rbegin() << std::endl;
	file2 << std::endl;

	if (compare_files("ITERATORS TESTS REND()", 0, "vector") == 0)
		resize_files(file, file2, "vector");


	/* ITERATORS TESTS: CONST ITERATOR MY VECTOR */
	ft::vector<int> myvector5;

	file << "ITERATORS TESTS CONST ITERATOR" << std::endl;
  	for (int i = 1; i <= 5; i++) {
		file << "Push back: " << i << std::endl;
		myvector5.push_back(i);
	}
	file << "myvector contains:";
  	for (ft::vector<int>::const_iterator it = myvector5.begin() ; it != myvector5.end(); ++it)
		file << ' ' << *it;
  	file << std::endl;
	file << "Valeur de begin(): " << *myvector5.begin() << std::endl;
	file << "Valeur de begin() + 3: " << *(myvector5.begin() + 3) << std::endl;
	file << std::endl;


	/* ITERATORS TESTS: CONST ITERATOR STL VECTOR */
	std::vector<int> myvectorstl5;

	file2 << "ITERATORS TESTS CONST ITERATOR" << std::endl;
  	for (int i = 1; i <= 5; i++) {
		file2 << "Push back: " << i << std::endl;
		myvectorstl5.push_back(i);
	}
	file2 << "myvector contains:";
  	for (std::vector<int>::const_iterator it = myvectorstl5.begin() ; it != myvectorstl5.end(); ++it)
		file2 << ' ' << *it;
  	file2 << std::endl;
	file2 << "Valeur de begin(): " << *myvectorstl5.begin() << std::endl;
	file2 << "Valeur de begin() + 3: " << *(myvectorstl5.begin() + 3) << std::endl;
	file2 << std::endl;

	if (compare_files("ITERATORS TESTS CONST ITERATOR", 0, "vector") == 0)
		resize_files(file, file2, "vector");


	/* CAPACITY TESTS: SIZE MY VECTOR */
	ft::vector<int> myvector7;

	file << "CAPACITY TESTS SIZE" << std::endl;
  	ft::vector<int> myintssize;
		file << "0. size: " << myintssize.size() << std::endl;
  	for (int i = 0; i < 10; i++) {
		file << "Push back: " << i << std::endl;	
		myintssize.push_back(i);
		file << "1. size: " << myintssize.size() << std::endl;
	}
	file << "Vector contains:";
  	for (ft::vector<int>::iterator it = myintssize.begin() ; it != myintssize.end(); ++it)
		file << ' ' << *it;
  	file << std::endl;
	file << "insert(end(), 10, 100): ";
	myintssize.insert (myintssize.end(), 10, 100);
	for (ft::vector<int>::iterator it = myintssize.begin() ; it != myintssize.end(); ++it)
		file << ' ' << *it;
  	file << std::endl;
	file << "2. size: " << myintssize.size() << std::endl;

  	file << std::endl;
	file << "Pop back" << std::endl;
	myintssize.pop_back();
	file << "Vector contains:";
  	for (ft::vector<int>::iterator it = myintssize.begin() ; it != myintssize.end(); ++it)
		file << ' ' << *it;
	file << std::endl;
	file << "3. size: " << myintssize.size() << std::endl;
	file << std::endl;


	/* CAPACITY TESTS: SIZE STL VECTOR */
	std::vector<int> myvectorstl7;

	file2 << "CAPACITY TESTS SIZE" << std::endl;
  	std::vector<int> myintssize2;
		file2 << "0. size: " << myintssize2.size() << std::endl;
  	for (int i = 0; i < 10; i++) {
		file2 << "Push back: " << i << std::endl;	
		myintssize2.push_back(i);
		file2 << "1. size: " << myintssize2.size() << std::endl;
	}
	file2 << "Vector contains:";
  	for (std::vector<int>::iterator it = myintssize2.begin() ; it != myintssize2.end(); ++it)
		file2 << ' ' << *it;
  	file2 << std::endl;
	file2 << "insert(end(), 10, 100): ";
	myintssize2.insert (myintssize2.end(), 10, 100);
	for (std::vector<int>::iterator it = myintssize2.begin() ; it != myintssize2.end(); ++it)
		file2 << ' ' << *it;
  	file2 << std::endl;
	file2 << "2. size: " << myintssize2.size() << std::endl;

  	file2 << std::endl;
	file2 << "Pop back" << std::endl;
	myintssize2.pop_back();
	file2 << "Vector contains:";
  	for (std::vector<int>::iterator it = myintssize2.begin() ; it != myintssize2.end(); ++it)
		file2 << ' ' << *it;
	file2 << std::endl;
	file2 << "3. size: " << myintssize2.size() << std::endl;
	file2 << std::endl;

	if (compare_files("CAPACITY TESTS SIZE", 0, "vector") == 0)
		resize_files(file, file2, "vector");


	/* CAPACITY TESTS: MAX SIZE MY VECTOR */
	ft::vector<int> myvector8;

	file << "CAPACITY TESTS MAX SIZE" << std::endl;
	file << "Max size: " << myvector8.max_size() << std::endl;
	file << "Push back 100 elements in the vector" << std::endl;
	for (int i = 0; i < 100; i++)
		myvector8.push_back(i);
	file << "Max size: " << myvector8.max_size() << std::endl;
	file << "Size: " << myvector8.size() << std::endl;
	file << "Capacity: " << myvector8.capacity() << std::endl;
	file << std::endl;


	/* CAPACITY TESTS: MAX SIZE STL VECTOR */
	std::vector<int> myvectorstl8;

	file2 << "CAPACITY TESTS MAX SIZE" << std::endl;
	file2 << "Max size: " << myvectorstl8.max_size() << std::endl;
	file2 << "Push back 100 elements in the vector" << std::endl;
	for (int i = 0; i < 100; i++)
		myvectorstl8.push_back(i);
	file2 << "Max size: " << myvectorstl8.max_size() << std::endl;
	file2 << "Size: " << myvectorstl8.size() << std::endl;
	file2 << "Capacity: " << myvectorstl8.capacity() << std::endl;
	file2 << std::endl;

	if (compare_files("CAPACITY TESTS MAX SIZE", 0, "vector") == 0)
		resize_files(file, file2, "vector");

	
	/* CAPACITY TESTS: RESIZE MY VECTOR */
	ft::vector<int> myvector9;

	file << "CAPACITY TESTS RESIZE" << std::endl;
	file << "Add 10 elements in the vector" << std::endl;
	for (int i = 0; i < 10; i++)
		myvector9.push_back(i);
	file << "Size: " << myvector9.size() << std::endl;
	file << "Resize to 5" << std::endl;
	myvector9.resize(5);
	file << "Vector contains: ";
	for (ft::vector<int>::iterator it = myvector9.begin() ; it != myvector9.end(); ++it)
		file << ' ' << *it;
	file << std::endl;
	file << "Size: " << myvector9.size() << std::endl;
	file << "Resize to 8, 100" << std::endl;
	myvector9.resize(8, 100);
	file << "Vector contains: ";
	for (ft::vector<int>::iterator it = myvector9.begin() ; it != myvector9.end(); ++it)
		file << ' ' << *it;
	file << std::endl;
	file << "Size: " << myvector9.size() << std::endl;
	file << "Resize to 12" << std::endl;
	myvector9.resize(12);

	file << "Vector contains: ";
	for (ft::vector<int>::iterator it = myvector9.begin() ; it != myvector9.end(); ++it)
		file << ' ' << *it;
	file << std::endl;
	file << "Size: " << myvector9.size() << std::endl;
	file << "Capacity: " << myvector9.capacity() << std::endl;
	file << "Max size: " << myvector9.max_size() << std::endl;
	file << std::endl;


	/* CAPACITY TESTS: RESIZE STL VECTOR */
	std::vector<int> myvectorstl9;

	file2 << "CAPACITY TESTS RESIZE" << std::endl;
	file2 << "Add 10 elements in the vector" << std::endl;
	for (int i = 0; i < 10; i++)
		myvectorstl9.push_back(i);
	file2 << "Size: " << myvectorstl9.size() << std::endl;
	file2 << "Resize to 5" << std::endl;
	myvectorstl9.resize(5);
	file2 << "Vector contains: ";
	for (std::vector<int>::iterator it = myvectorstl9.begin() ; it != myvectorstl9.end(); ++it)
		file2 << ' ' << *it;
	file2 << std::endl;
	file2 << "Size: " << myvectorstl9.size() << std::endl;
	file2 << "Resize to 8, 100" << std::endl;
	myvectorstl9.resize(8, 100);
	file2 << "Vector contains: ";
	for (std::vector<int>::iterator it = myvectorstl9.begin() ; it != myvectorstl9.end(); ++it)
		file2 << ' ' << *it;
	file2 << std::endl;
	file2 << "Size: " << myvectorstl9.size() << std::endl;
	file2 << "Resize to 12" << std::endl;
	myvectorstl9.resize(12);

	file2 << "Vector contains: ";
	for (std::vector<int>::iterator it = myvectorstl9.begin() ; it != myvectorstl9.end(); ++it)
		file2 << ' ' << *it;
	file2 << std::endl;
	file2 << "Size: " << myvectorstl9.size() << std::endl;
	file2 << "Capacity: " << myvectorstl9.capacity() << std::endl;
	file2 << "Max size: " << myvectorstl9.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("CAPACITY TESTS RESIZE", 0, "vector") == 0)
		resize_files(file, file2, "vector");

	
	/* CAPACITY TESTS: RESERVE MY VECTOR */
	ft::vector<int> myvector10;

	file << "CAPACITY TESTS RESERVE" << std::endl;
	file << "Add 10 elements in the vector" << std::endl;
	for (int i = 0; i < 10; i++)
		myvector10.push_back(i);
	file << "Size: " << myvector10.size() << std::endl;
	file << "Capacity: " << myvector10.capacity() << std::endl;
	file << "Reserve 50" << std::endl;
	myvector10.reserve(50);
	file << "Vector contains: ";
	for (ft::vector<int>::iterator it = myvector10.begin() ; it != myvector10.end(); ++it)
		file << ' ' << *it;
	file << std::endl;
	file << "Size: " << myvector10.size() << std::endl;
	file << "Capacity: " << myvector10.capacity() << std::endl;
	file << "Reserve 5" << std::endl;
	myvector10.reserve(5);
	file << "Vector contains: ";
	for (ft::vector<int>::iterator it = myvector10.begin() ; it != myvector10.end(); ++it)
		file << ' ' << *it;
	file << std::endl;
	file << "Size: " << myvector10.size() << std::endl;
	file << "Capacity: " << myvector10.capacity() << std::endl;
	file << std::endl;


	/* CAPACITY TESTS: RESERVE STL VECTOR */
	std::vector<int> myvectorstl10;

	file2 << "CAPACITY TESTS RESERVE" << std::endl;
	file2 << "Add 10 elements in the vector" << std::endl;
	for (int i = 0; i < 10; i++)
		myvectorstl10.push_back(i);
	file2 << "Size: " << myvectorstl10.size() << std::endl;
	file2 << "Capacity: " << myvectorstl10.capacity() << std::endl;
	file2 << "Reserve 50" << std::endl;
	myvectorstl10.reserve(50);
	file2 << "Vector contains: ";
	for (std::vector<int>::iterator it = myvectorstl10.begin() ; it != myvectorstl10.end(); ++it)
		file2 << ' ' << *it;
	file2 << std::endl;
	file2 << "Size: " << myvectorstl10.size() << std::endl;
	file2 << "Capacity: " << myvectorstl10.capacity() << std::endl;
	file2 << "Reserve 5" << std::endl;
	myvectorstl10.reserve(5);
	file2 << "Vector contains: ";
	for (std::vector<int>::iterator it = myvectorstl10.begin() ; it != myvectorstl10.end(); ++it)
		file2 << ' ' << *it;
	file2 << std::endl;
	file2 << "Size: " << myvectorstl10.size() << std::endl;
	file2 << "Capacity: " << myvectorstl10.capacity() << std::endl;
	file2 << std::endl;

	if (compare_files("CAPACITY TESTS RESERVE", 0, "vector") == 0)
		resize_files(file, file2, "vector");

	
	/* CAPACITY TESTS: EMPTY MY VECTOR */
	ft::vector<int> myvector11;

	file << "CAPACITY TESTS EMPTY" << std::endl;
	file << "Test if the vector is empty" << std::endl;
	if (myvector11.empty())
		file << "Vector is empty" << std::endl;
	else
		file << "Vector is not empty" << std::endl;
	file << "Add 10 elements in the vector" << std::endl;
	for (int i = 0; i < 10; i++)
		myvector11.push_back(i);
	file << "Test if the vector is empty" << std::endl;
	if (myvector11.empty())
		file << "Vector is empty" << std::endl;
	else
		file << "Vector is not empty" << std::endl;
	file << "Pop back 10 elements" << std::endl;
	for (int i = 0; i < 10; i++)
		myvector11.pop_back();
	file << "Test if the vector is empty" << std::endl;
	if (myvector11.empty())
		file << "Vector is empty" << std::endl;
	else
		file << "Vector is not empty" << std::endl;
	file << "Size: " << myvector11.size() << std::endl;
	file << "Capacity: " << myvector11.capacity() << std::endl;
	file << std::endl;


	/* CAPACITY TESTS: EMPTY STL VECTOR */
	std::vector<int> myvectorstl11;

	file2 << "CAPACITY TESTS EMPTY" << std::endl;
	file2 << "Test if the vector is empty" << std::endl;
	if (myvectorstl11.empty())
		file2 << "Vector is empty" << std::endl;
	else
		file2 << "Vector is not empty" << std::endl;
	file2 << "Add 10 elements in the vector" << std::endl;
	for (int i = 0; i < 10; i++)
		myvectorstl11.push_back(i);
	file2 << "Test if the vector is empty" << std::endl;
	if (myvectorstl11.empty())
		file2 << "Vector is empty" << std::endl;
	else
		file2 << "Vector is not empty" << std::endl;
	file2 << "Pop back 10 elements" << std::endl;
	for (int i = 0; i < 10; i++)
		myvectorstl11.pop_back();
	file2 << "Test if the vector is empty" << std::endl;
	if (myvectorstl11.empty())
		file2 << "Vector is empty" << std::endl;
	else
		file2 << "Vector is not empty" << std::endl;
	file2 << "Size: " << myvectorstl11.size() << std::endl;
	file2 << "Capacity: " << myvectorstl11.capacity() << std::endl;
	file2 << std::endl;

	if (compare_files("CAPACITY TESTS EMPTY", 0, "vector") == 0)
		resize_files(file, file2, "vector");


	/* CAPACITY TESTS: RESERVE MY VECTOR */
	ft::vector<int>::size_type sz;
	ft::vector<int> fooreserve;
	file << "CAPACITY TESTS RESERVE" << std::endl;

	sz = fooreserve.capacity();
	file << "making fooreserve grow:" << std::endl;
	file << "Add 100 elements in the vector fooreserve" << std::endl;
	for (int i = 0; i < 100; ++i) {
		fooreserve.push_back(i);
		if (sz != fooreserve.capacity()) {
			sz = fooreserve.capacity();
			file << "capacity changed: " << sz << std::endl;
		}
	}
	file << "Size: " << fooreserve.size() << std::endl;
	file << "Capacity: " << fooreserve.capacity() << std::endl;
	file << "Vector contains: ";
	for (ft::vector<int>::iterator it = fooreserve.begin() ; it != fooreserve.end(); ++it)
		file << ' ' << *it;
	file << std::endl;

	ft::vector<int> barreserve;
	sz = barreserve.capacity();
	barreserve.reserve(100);   // this is the only difference with fooreserve above
	file << "making barreserve grow:" << std::endl;
	file << "Add 100 elements in the vector barreserve" << std::endl;
	for (int i = 0; i < 100; ++i) {
		barreserve.push_back(i);
		if (sz != barreserve.capacity()) {
			sz = barreserve.capacity();
			file << "capacity changed: " << sz << std::endl;
		}
	}
	file << "Size: " << barreserve.size() << std::endl;
	file << "Capacity: " << barreserve.capacity() << std::endl;
	file << "Vector contains: ";
	for (ft::vector<int>::iterator it = barreserve.begin() ; it != barreserve.end(); ++it)
		file << ' ' << *it;
	file << std::endl;
	file << std::endl;

	/* CAPACITY TESTS: RESERVE STL VECTOR */
	std::vector<int>::size_type szstl;
	std::vector<int> fooreservestl;
	file2 << "CAPACITY TESTS RESERVE" << std::endl;

	szstl = fooreservestl.capacity();
	file2 << "making fooreserve grow:" << std::endl;
	file2 << "Add 100 elements in the vector fooreserve" << std::endl;
	for (int i = 0; i < 100; ++i) {
		fooreservestl.push_back(i);
		if (szstl != fooreservestl.capacity()) {
			szstl = fooreservestl.capacity();
			file2 << "capacity changed: " << szstl << std::endl;
		}
	}
	file2 << "Size: " << fooreservestl.size() << std::endl;
	file2 << "Capacity: " << fooreservestl.capacity() << std::endl;
	file2 << "Vector contains: ";
	for (std::vector<int>::iterator it = fooreservestl.begin() ; it != fooreservestl.end(); ++it)
		file2 << ' ' << *it;
	file2 << std::endl;

	std::vector<int> barreservestl;
	szstl = barreservestl.capacity();
	barreservestl.reserve(100);   // this is the only difference with fooreserve above
	file2 << "making barreserve grow:" << std::endl;
	file2 << "Add 100 elements in the vector barreserve" << std::endl;
	for (int i = 0; i < 100; ++i) {
		barreservestl.push_back(i);
		if (szstl != barreservestl.capacity()) {
			szstl = barreservestl.capacity();
			file2 << "capacity changed: " << szstl << std::endl;
		}
	}
	file2 << "Size: " << barreservestl.size() << std::endl;
	file2 << "Capacity: " << barreservestl.capacity() << std::endl;
	file2 << "Vector contains: ";
	for (std::vector<int>::iterator it = barreservestl.begin() ; it != barreservestl.end(); ++it)
		file2 << ' ' << *it;
	file2 << std::endl;
	file2 << std::endl;

	if (compare_files("CAPACITY TESTS RESERVE", 0, "vector") == 0)
		resize_files(file, file2, "vector");
	

	/* ELEMENT ACCESS TESTS: OPERATOR[] MY VECTOR */
	ft::vector<int> myvectorop(10);  // 10 zero-initialized ints
	ft::vector<int>::size_type szop = myvectorop.size();
	file << "ELEMENT ACCESS TESTS OPERATOR[]" << std::endl;

	// assign some values:
	file << "Assign some values in vector" << std::endl;
	for (unsigned i = 0; i < szop; i++) {
		myvectorop[i] = i;
	}
	file << "Vector contains: ";
	for (unsigned i = 0; i < szop; i++) {
		file << ' ' << myvectorop[i];
	}
	file << std::endl;
	file << "Size: " << myvectorop.size() << std::endl;
	file << "Capacity: " << myvectorop.capacity() << std::endl;
	//reverse vector using operator[]:
	file << "Reverse vector using operator[]" << std::endl;
	for (unsigned i = 0; i < szop / 2; i++) {
		int temp;
		temp = myvectorop[szop - 1 - i];
		myvectorop[szop - 1 - i] = myvectorop[i];
		myvectorop[i] = temp;
	}
	file << "Vector contains: ";
	for (unsigned i = 0; i < szop; i++) {
		file << ' ' << myvectorop[i];
	}
	file << std::endl;
	file << "Size: " << myvectorop.size() << std::endl;
	file << "Capacity: " << myvectorop.capacity() << std::endl;
	file << std::endl;

	/* ELEMENT ACCESS TESTS: OPERATOR[] STL VECTOR */
	std::vector<int> myvectoropstl(10);  // 10 zero-initialized ints
	std::vector<int>::size_type szopstl = myvectoropstl.size();
	file2 << "ELEMENT ACCESS TESTS OPERATOR[]" << std::endl;

	// assign some values:
	file2 << "Assign some values in vector" << std::endl;
	for (unsigned i = 0; i < szopstl; i++) {
		myvectoropstl[i] = i;
	}
	file2 << "Vector contains: ";
	for (unsigned i = 0; i < szopstl; i++) {
		file2 << ' ' << myvectoropstl[i];
	}
	file2 << std::endl;
	file2 << "Size: " << myvectoropstl.size() << std::endl;
	file2 << "Capacity: " << myvectoropstl.capacity() << std::endl;
	//reverse vector using operator[]:
	file2 << "Reverse vector using operator[]" << std::endl;
	for (unsigned i = 0; i < szopstl / 2; i++) {
		int temp;
		temp = myvectoropstl[szopstl - 1 - i];
		myvectoropstl[szopstl - 1 - i] = myvectoropstl[i];
		myvectoropstl[i] = temp;
	}
	file2 << "Vector contains: ";
	for (unsigned i = 0; i < szopstl; i++) {
		file2 << ' ' << myvectoropstl[i];
	}
	file2 << std::endl;
	file2 << "Size: " << myvectoropstl.size() << std::endl;
	file2 << "Capacity: " << myvectoropstl.capacity() << std::endl;
	file2 << std::endl;

	if (compare_files("ELEMENT ACCESS TESTS OPERATOR[]", 0, "vector") == 0)
		resize_files(file, file2, "vector");
	
	/* ELEMENT ACCESS TESTS: AT MY VECTOR */
	ft::vector<int> myvectorat(10);  // 10 zero-initialized ints

	file << "ELEMENT ACCESS TESTS AT" << std::endl;
	file << "Assign some values in vector" << std::endl;
	for (unsigned i = 0; i < myvectorat.size(); i++) {
		myvectorat.at(i) = i;
	}
	file << "Vector contains (with at()): ";
	for (unsigned i = 0; i < myvectorat.size(); i++) {
		file << ' ' << myvectorat.at(i);
	}
	file << std::endl;
	file << "Size: " << myvectorat.size() << std::endl;
	file << "Capacity: " << myvectorat.capacity() << std::endl;
	file << "Access with at(20) (out of range)" << std::endl;
	try {
		myvectorat.at(20) = 100;
	}
	catch (std::exception &e) {
		file << "Exception: " << e.what() << std::endl;
	}
	file << std::endl;

	/* ELEMENT ACCESS TESTS: AT STL VECTOR */
	std::vector<int> myvectoratstl(10);  // 10 zero-initialized ints

	file2 << "ELEMENT ACCESS TESTS AT" << std::endl;
	file2 << "Assign some values in vector" << std::endl;
	for (unsigned i = 0; i < myvectoratstl.size(); i++) {
		myvectoratstl.at(i) = i;
	}
	file2 << "Vector contains (with at()): ";
	for (unsigned i = 0; i < myvectoratstl.size(); i++) {
		file2 << ' ' << myvectoratstl.at(i);
	}
	file2 << std::endl;
	file2 << "Size: " << myvectoratstl.size() << std::endl;
	file2 << "Capacity: " << myvectoratstl.capacity() << std::endl;
	file2 << "Access with at(20) (out of range)" << std::endl;
	try {
		myvectoratstl.at(20) = 100;
	}
	catch (std::exception &e) {
		file2 << "Exception: " << e.what() << std::endl;
	}
	file2 << std::endl;

	if (compare_files("ELEMENT ACCESS TESTS AT", 1, "vector") == 0)
		resize_files(file, file2, "vector");
	

	/* ELEMENT ACCESS TESTS: FRONT MY VECTOR */
	ft::vector<int> myvectorfront;

	file << "ELEMENT ACCESS TESTS FRONT" << std::endl;
	
	file << "Push back 78 in vector" << std::endl;
	myvectorfront.push_back(78);
	file << "Vector contains: ";
	for (unsigned i = 0; i < myvectorfront.size(); i++) {
		file << ' ' << myvectorfront[i];
	}
	file << "Front: " << myvectorfront.front() << std::endl;
	file << "Size: " << myvectorfront.size() << std::endl;
	file << "Capacity: " << myvectorfront.capacity() << std::endl;
	file << "Push back 16 in vector" << std::endl;
	myvectorfront.push_back(16);
	file << "Vector contains: ";
	for (unsigned i = 0; i < myvectorfront.size(); i++) {
		file << ' ' << myvectorfront[i];
	}
	file << "Front: " << myvectorfront.front() << std::endl;
	file << "Size: " << myvectorfront.size() << std::endl;
	file << "Capacity: " << myvectorfront.capacity() << std::endl;
	file << "Front -= back" << std::endl;
	myvectorfront.front() -= myvectorfront.back();
	file << "Front() is now " << myvectorfront.front() << std::endl;
	file << std::endl;

	/* ELEMENT ACCESS TESTS: FRONT STL VECTOR */
	std::vector<int> myvectorfrontstl;
	
	file2 << "ELEMENT ACCESS TESTS FRONT" << std::endl;

	file2 << "Push back 78 in vector" << std::endl;
	myvectorfrontstl.push_back(78);
	file2 << "Vector contains: ";
	for (unsigned i = 0; i < myvectorfrontstl.size(); i++) {
		file2 << ' ' << myvectorfrontstl[i];
	}
	file2 << "Front: " << myvectorfrontstl.front() << std::endl;
	file2 << "Size: " << myvectorfrontstl.size() << std::endl;
	file2 << "Capacity: " << myvectorfrontstl.capacity() << std::endl;
	file2 << "Push back 16 in vector" << std::endl;
	myvectorfrontstl.push_back(16);
	file2 << "Vector contains: ";
	for (unsigned i = 0; i < myvectorfrontstl.size(); i++) {
		file2 << ' ' << myvectorfrontstl[i];
	}
	file2 << "Front: " << myvectorfrontstl.front() << std::endl;
	file2 << "Size: " << myvectorfrontstl.size() << std::endl;
	file2 << "Capacity: " << myvectorfrontstl.capacity() << std::endl;
	file2 << "Front -= back" << std::endl;
	myvectorfrontstl.front() -= myvectorfrontstl.back();
	file2 << "Front() is now " << myvectorfrontstl.front() << std::endl;
	file2 << std::endl;

	if (compare_files("ELEMENT ACCESS TESTS FRONT", 0, "vector") == 0)
		resize_files(file, file2, "vector");
	

	/* ELEMENT ACCESS TESTS: BACK MY VECTOR */
	ft::vector<int> myvectorback;

	file << "ELEMENT ACCESS TESTS BACK" << std::endl;
	file << "Push back 10 in vector" << std::endl;
	myvectorback.push_back(10);
	file << "Vector contains: ";
	for (unsigned i = 0; i < myvectorback.size(); i++) {
		file << ' ' << myvectorback[i];
	}
	file << std::endl;
	file << "Back: " << myvectorback.back() << std::endl;
	file << "Size: " << myvectorback.size() << std::endl;
	file << "Capacity: " << myvectorback.capacity() << std::endl;

	file << "While vector.back() != 0 push back back() -1" << std::endl;
	while (myvectorback.back() != 0) {
		myvectorback.push_back(myvectorback.back() - 1);
	}
	file << "Vector contains: ";
	for (unsigned i = 0; i < myvectorback.size(); i++) {
		file << ' ' << myvectorback[i];
	}
	file << std::endl;
	file << "Back: " << myvectorback.back() << std::endl;
	file << "Size: " << myvectorback.size() << std::endl;
	file << "Capacity: " << myvectorback.capacity() << std::endl;
	file << std::endl;

	/* ELEMENT ACCESS TESTS: BACK STL VECTOR */
	std::vector<int> myvectorbackstl;

	file2 << "ELEMENT ACCESS TESTS BACK" << std::endl;
	file2 << "Push back 10 in vector" << std::endl;
	myvectorbackstl.push_back(10);
	file2 << "Vector contains: ";
	for (unsigned i = 0; i < myvectorbackstl.size(); i++) {
		file2 << ' ' << myvectorbackstl[i];
	}
	file2 << std::endl;
	file2 << "Back: " << myvectorbackstl.back() << std::endl;
	file2 << "Size: " << myvectorbackstl.size() << std::endl;
	file2 << "Capacity: " << myvectorbackstl.capacity() << std::endl;

	file2 << "While vector.back() != 0 push back back() -1" << std::endl;
	while (myvectorbackstl.back() != 0) {
		myvectorbackstl.push_back(myvectorbackstl.back() - 1);
	}
	file2 << "Vector contains: ";
	for (unsigned i = 0; i < myvectorbackstl.size(); i++) {
		file2 << ' ' << myvectorbackstl[i];
	}
	file2 << std::endl;
	file2 << "Back: " << myvectorbackstl.back() << std::endl;
	file2 << "Size: " << myvectorbackstl.size() << std::endl;
	file2 << "Capacity: " << myvectorbackstl.capacity() << std::endl;
	file2 << std::endl;

	if (compare_files("ELEMENT ACCESS TESTS BACK", 0, "vector") == 0)
		resize_files(file, file2, "vector");

	
	/* MODIFIERS TESTS: ASSIGN MY VECTOR */
	ft::vector<int> firstassign;
	ft::vector<int> secondassign;
	ft::vector<int> thirdassign;

	file << "MODIFIERS TESTS ASSIGN" << std::endl;
	file << "Assign 7 ints with value 100 in the first vector" << std::endl;
	firstassign.assign(7, 100);
	ft::vector<int>::iterator itassign;
	itassign = firstassign.begin() + 1;
	file << "First vector contains: ";
	for (unsigned i = 0; i < firstassign.size(); i++) {
		file << ' ' << firstassign[i];
	}
	file << std::endl;
	
	file << "Assign range from first to last in the second vector" << std::endl;
	secondassign.assign(itassign, firstassign.end() - 1);
	file << "Second vector contains: ";
	for (unsigned i = 0; i < secondassign.size(); i++) {
		file << ' ' << secondassign[i];
	}
	file << std::endl;
	int intsassign[] = {1776, 7, 4};
	file << "Assign array of 3 ints in the third vector" << std::endl;
	thirdassign.assign(intsassign, intsassign + 3);
	file << "Third vector contains: ";
	for (unsigned i = 0; i < thirdassign.size(); i++) {
		file << ' ' << thirdassign[i];
	}
	file << std::endl;
	file << "Size of first vector: " << firstassign.size() << std::endl;
	file << "Size of second vector: " << secondassign.size() << std::endl;
	file << "Size of third vector: " << thirdassign.size() << std::endl;
	file << std::endl;

	/* MODIFIERS TESTS: ASSIGN STL VECTOR */
	std::vector<int> firstassignstl;
	std::vector<int> secondassignstl;
	std::vector<int> thirdassignstl;

	file2 << "MODIFIERS TESTS ASSIGN" << std::endl;
	file2 << "Assign 7 ints with value 100 in the first vector" << std::endl;
	firstassignstl.assign(7, 100);
	std::vector<int>::iterator itassignstl;
	itassignstl = firstassignstl.begin() + 1;
	file2 << "First vector contains: ";
	for (unsigned i = 0; i < firstassignstl.size(); i++) {
		file2 << ' ' << firstassignstl[i];
	}
	file2 << std::endl;

	file2 << "Assign range from first to last in the second vector" << std::endl;
	secondassignstl.assign(itassignstl, firstassignstl.end() - 1);
	file2 << "Second vector contains: ";
	for (unsigned i = 0; i < secondassignstl.size(); i++) {
		file2 << ' ' << secondassignstl[i];
	}
	file2 << std::endl;

	int intsassignstl[] = {1776, 7, 4};
	file2 << "Assign array of 3 ints in the third vector" << std::endl;
	thirdassignstl.assign(intsassignstl, intsassignstl + 3);
	file2 << "Third vector contains: ";
	for (unsigned i = 0; i < thirdassignstl.size(); i++) {
		file2 << ' ' << thirdassignstl[i];
	}
	file2 << std::endl;
	file2 << "Size of first vector: " << firstassignstl.size() << std::endl;
	file2 << "Size of second vector: " << secondassignstl.size() << std::endl;
	file2 << "Size of third vector: " << thirdassignstl.size() << std::endl;
	file2 << std::endl;

	if (compare_files("MODIFIERS TESTS ASSIGN", 0, "vector") == 0)
		resize_files(file, file2, "vector");

	
	/* MODIFIERS TESTS: PUSH BACK MY VECTOR */
	ft::vector<int> myvectorpushback;

	file << "MODIFIERS TESTS PUSH BACK" << std::endl;
	file << "Size of vector: " << myvectorpushback.size() << std::endl;
	file << "Push back 100" << std::endl;
	myvectorpushback.push_back(100);
	file << "Size of vector: " << myvectorpushback.size() << std::endl;
	file << "Push back 150 elements" << std::endl;
	for (int i = 0; i < 150; i++) {
		myvectorpushback.push_back(i);
	}
	file << "Size of vector: " << myvectorpushback.size() << std::endl;
	file << "Vector contains: ";
	for (unsigned i = 0; i < myvectorpushback.size(); i++) {
		file << ' ' << myvectorpushback[i];
	}
	file << std::endl;
	file << "Capacity of vector: " << myvectorpushback.capacity() << std::endl;
	file << std::endl;

	/* MODIFIERS TESTS: PUSH BACK STL VECTOR */
	std::vector<int> myvectorpushbackstl;

	file2 << "MODIFIERS TESTS PUSH BACK" << std::endl;
	file2 << "Size of vector: " << myvectorpushbackstl.size() << std::endl;
	file2 << "Push back 100" << std::endl;
	myvectorpushbackstl.push_back(100);
	file2 << "Size of vector: " << myvectorpushbackstl.size() << std::endl;
	file2 << "Push back 150 elements" << std::endl;
	for (int i = 0; i < 150; i++) {
		myvectorpushbackstl.push_back(i);
	}
	file2 << "Size of vector: " << myvectorpushbackstl.size() << std::endl;
	file2 << "Vector contains: ";
	for (unsigned i = 0; i < myvectorpushbackstl.size(); i++) {
		file2 << ' ' << myvectorpushbackstl[i];
	}
	file2 << std::endl;
	file2 << "Capacity of vector: " << myvectorpushbackstl.capacity() << std::endl;
	file2 << std::endl;

	if (compare_files("MODIFIERS TESTS PUSH BACK", 0, "vector") == 0)
		resize_files(file, file2, "vector");

	
	/* MODIFIERS TESTS: POP BACK MY VECTOR */
	ft::vector<int> myvectorpopback;

	file << "MODIFIERS TESTS POP BACK" << std::endl;
	file << "Size of vector: " << myvectorpopback.size() << std::endl;
	file << "Push back 15 elements" << std::endl;
	for (int i = 0; i < 15; i++) {
		myvectorpopback.push_back(i);
	}
	file << "Size of vector: " << myvectorpopback.size() << std::endl;
	file << "Vector contains: ";
	for (unsigned i = 0; i < myvectorpopback.size(); i++) {
		file << ' ' << myvectorpopback[i];
	}
	file << std::endl;
	file << "Pop back 5 elements" << std::endl;
	for (int i = 0; i < 5; i++) {
		myvectorpopback.pop_back();
	}
	file << "Size of vector: " << myvectorpopback.size() << std::endl;
	file << "Vector contains: ";
	for (unsigned i = 0; i < myvectorpopback.size(); i++) {
		file << ' ' << myvectorpopback[i];
	}
	file << std::endl;
	int sum = 0;
	file << "Sum of elements: ";
	while (!myvectorpopback.empty()) {
		sum += myvectorpopback.back();
		myvectorpopback.pop_back();
	}
	file << "The elements of vector add up to: " << sum << std::endl;
	file << std::endl;

	/* MODIFIERS TESTS: POP BACK STL VECTOR */
	std::vector<int> myvectorpopbackstl;

	file2 << "MODIFIERS TESTS POP BACK" << std::endl;
	file2 << "Size of vector: " << myvectorpopbackstl.size() << std::endl;
	file2 << "Push back 15 elements" << std::endl;
	for (int i = 0; i < 15; i++) {
		myvectorpopbackstl.push_back(i);
	}
	file2 << "Size of vector: " << myvectorpopbackstl.size() << std::endl;
	file2 << "Vector contains: ";
	for (unsigned i = 0; i < myvectorpopbackstl.size(); i++) {
		file2 << ' ' << myvectorpopbackstl[i];
	}
	file2 << std::endl;
	file2 << "Pop back 5 elements" << std::endl;
	for (int i = 0; i < 5; i++) {
		myvectorpopbackstl.pop_back();
	}
	file2 << "Size of vector: " << myvectorpopbackstl.size() << std::endl;
	file2 << "Vector contains: ";
	for (unsigned i = 0; i < myvectorpopbackstl.size(); i++) {
		file2 << ' ' << myvectorpopbackstl[i];
	}
	file2 << std::endl;
	int sum2 = 0;
	file2 << "Sum of elements: ";
	while (!myvectorpopbackstl.empty()) {
		sum2 += myvectorpopbackstl.back();
		myvectorpopbackstl.pop_back();
	}
	file2 << "The elements of vector add up to: " << sum2 << std::endl;
	file2 << std::endl;

	if (compare_files("MODIFIERS TESTS POP BACK", 0, "vector") == 0)
		resize_files(file, file2, "vector");
	

	/* MODIFIERS TESTS: INSERT MY VECTOR */
	ft::vector<int> myvectorinsert(3, 100);
	ft::vector<int>::iterator it;

	file << "MODIFIERS TESTS INSERT" << std::endl;
	it = myvectorinsert.begin();
	it = myvectorinsert.insert(it, 200);

	myvectorinsert.insert(it, 2, 300);

	// "it" no longer valid, get a new one:
	it = myvectorinsert.begin();

	ft::vector<int> anothervector(2, 400);
	myvectorinsert.insert(it + 2, anothervector.begin(), anothervector.end());

	int myarray[] = { 501,502,503 };
	myvectorinsert.insert(myvectorinsert.begin(), myarray, myarray + 3);

	file << "Vector contains:";
	for (it = myvectorinsert.begin(); it < myvectorinsert.end(); it++)
		file << ' ' << *it;
	file << std::endl;
	file << "Size of vector: " << myvectorinsert.size() << std::endl;
	file << "Capacity of vector: " << myvectorinsert.capacity() << std::endl;
	file << "Max size of vector: " << myvectorinsert.max_size() << std::endl;
	file << std::endl;

	/* MODIFIERS TESTS: INSERT STL VECTOR */
	std::vector<int> myvectorinsertstl(3, 100);
	std::vector<int>::iterator itstl;

	file2 << "MODIFIERS TESTS INSERT" << std::endl;
	itstl = myvectorinsertstl.begin();
	itstl = myvectorinsertstl.insert(itstl, 200);

	myvectorinsertstl.insert(itstl, 2, 300);

	// "it" no longer valid, get a new one:
	itstl = myvectorinsertstl.begin();

	std::vector<int> anothervectorstl(2, 400);
	myvectorinsertstl.insert(itstl + 2, anothervectorstl.begin(), anothervectorstl.end());

	int myarraystl[] = { 501,502,503 };
	myvectorinsertstl.insert(myvectorinsertstl.begin(), myarraystl, myarraystl + 3);

	file2 << "Vector contains:";
	for (itstl = myvectorinsertstl.begin(); itstl < myvectorinsertstl.end(); itstl++)
		file2 << ' ' << *itstl;
	file2 << std::endl;
	file2 << "Size of vector: " << myvectorinsertstl.size() << std::endl;
	file2 << "Capacity of vector: " << myvectorinsertstl.capacity() << std::endl;
	file2 << "Max size of vector: " << myvectorinsertstl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("MODIFIERS TESTS INSERT", 0, "vector") == 0)
		resize_files(file, file2, "vector");


	/* MODIFIERS TESTS: ERASE MY VECTOR */
	ft::vector<int> myvectorerase;

	file << "MODIFIERS TESTS ERASE" << std::endl;
	// set some values (from 1 to 10)
	file << "Push back 10 elements in the vector" << std::endl;
	for (int i = 1; i <= 10; i++) {
		myvectorerase.push_back(i);
	}
	file << "Vector contains: ";
	for (unsigned i = 0; i < myvectorerase.size(); i++) {
		file << ' ' << myvectorerase[i];
	}
	file << std::endl;
	file << "Size of vector: " << myvectorerase.size() << std::endl;
	file << "Capacity of vector: " << myvectorerase.capacity() << std::endl;
	file << "Max size of vector: " << myvectorerase.max_size() << std::endl;
	// erase the 6th element
	file << "Erase the 6th element" << std::endl;
	myvectorerase.erase(myvectorerase.begin() + 5);
	file << "Vector contains: ";
	for (unsigned i = 0; i < myvectorerase.size(); i++) {
		file << ' ' << myvectorerase[i];
	}
	file << std::endl;
	file << "Size of vector: " << myvectorerase.size() << std::endl;
	file << "Capacity of vector: " << myvectorerase.capacity() << std::endl;
	file << "Max size of vector: " << myvectorerase.max_size() << std::endl;

	// erase the first 3 elements:
	file << "Erase the first 3 elements" << std::endl;
	myvectorerase.erase(myvectorerase.begin(), myvectorerase.begin() + 3);
	file << "Vector contains: ";
	for (unsigned i = 0; i < myvectorerase.size(); i++) {
		file << ' ' << myvectorerase[i];
	}
	file << std::endl;
	file << "Size of vector: " << myvectorerase.size() << std::endl;
	file << "Capacity of vector: " << myvectorerase.capacity() << std::endl;
	file << "Max size of vector: " << myvectorerase.max_size() << std::endl;
	file << std::endl;

	/* MODIFIERS TESTS: ERASE STL VECTOR */
	std::vector<int> myvectorerasestl;

	file2 << "MODIFIERS TESTS ERASE" << std::endl;
	// set some values (from 1 to 10)
	file2 << "Push back 10 elements in the vector" << std::endl;
	for (int i = 1; i <= 10; i++) {
		myvectorerasestl.push_back(i);
	}
	file2 << "Vector contains: ";
	for (unsigned i = 0; i < myvectorerasestl.size(); i++) {
		file2 << ' ' << myvectorerasestl[i];
	}
	file2 << std::endl;
	file2 << "Size of vector: " << myvectorerasestl.size() << std::endl;
	file2 << "Capacity of vector: " << myvectorerasestl.capacity() << std::endl;
	file2 << "Max size of vector: " << myvectorerasestl.max_size() << std::endl;
	// erase the 6th element
	file2 << "Erase the 6th element" << std::endl;
	myvectorerasestl.erase(myvectorerasestl.begin() + 5);
	file2 << "Vector contains: ";
	for (unsigned i = 0; i < myvectorerasestl.size(); i++) {
		file2 << ' ' << myvectorerasestl[i];
	}
	file2 << std::endl;
	file2 << "Size of vector: " << myvectorerasestl.size() << std::endl;
	file2 << "Capacity of vector: " << myvectorerasestl.capacity() << std::endl;
	file2 << "Max size of vector: " << myvectorerasestl.max_size() << std::endl;

	// erase the first 3 elements:
	file2 << "Erase the first 3 elements" << std::endl;
	myvectorerasestl.erase(myvectorerasestl.begin(), myvectorerasestl.begin() + 3);
	file2 << "Vector contains: ";
	for (unsigned i = 0; i < myvectorerasestl.size(); i++) {
		file2 << ' ' << myvectorerasestl[i];
	}
	file2 << std::endl;
	file2 << "Size of vector: " << myvectorerasestl.size() << std::endl;
	file2 << "Capacity of vector: " << myvectorerasestl.capacity() << std::endl;
	file2 << "Max size of vector: " << myvectorerasestl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("MODIFIERS TESTS ERASE", 0, "vector") == 0)
		resize_files(file, file2, "vector");
	

	/* MODIFIERS TESTS: SWAP MY VECTOR */
	ft::vector<int> myvectorswap1(3, 100);   // three ints with a value of 100
	ft::vector<int> myvectorswap2(5, 200);   // five ints with a value of 200

	file << "MODIFIERS TESTS SWAP" << std::endl;
	file << "myvectorswap1 contains:";
	for (unsigned i = 0; i < myvectorswap1.size(); i++)
		file << ' ' << myvectorswap1[i];
	file << std::endl;

	file << "myvectorswap2 contains:";
	for (unsigned i = 0; i < myvectorswap2.size(); i++)
		file << ' ' << myvectorswap2[i];
	file << std::endl;

	file << "myvectorswap1.swap(myvectorswap2);" << std::endl;
	myvectorswap1.swap(myvectorswap2);

	file << "myvectorswap1 contains:";
	for (unsigned i = 0; i < myvectorswap1.size(); i++)
		file << ' ' << myvectorswap1[i];
	file << std::endl;

	file << "myvectorswap2 contains:";
	for (unsigned i = 0; i < myvectorswap2.size(); i++)
		file << ' ' << myvectorswap2[i];
	file << std::endl;
	file << std::endl;

	/* MODIFIERS TESTS: SWAP STL VECTOR */
	std::vector<int> myvectorswap1stl(3, 100);   // three ints with a value of 100
	std::vector<int> myvectorswap2stl(5, 200);   // five ints with a value of 200

	file2 << "MODIFIERS TESTS SWAP" << std::endl;
	file2 << "myvectorswap1 contains:";
	for (unsigned i = 0; i < myvectorswap1stl.size(); i++)
		file2 << ' ' << myvectorswap1stl[i];
	file2 << std::endl;

	file2 << "myvectorswap2 contains:";
	for (unsigned i = 0; i < myvectorswap2stl.size(); i++)
		file2 << ' ' << myvectorswap2stl[i];
	file2 << std::endl;

	file2 << "myvectorswap1.swap(myvectorswap2);" << std::endl;
	myvectorswap1stl.swap(myvectorswap2stl);

	file2 << "myvectorswap1 contains:";
	for (unsigned i = 0; i < myvectorswap1stl.size(); i++)
		file2 << ' ' << myvectorswap1stl[i];
	file2 << std::endl;

	file2 << "myvectorswap2 contains:";
	for (unsigned i = 0; i < myvectorswap2stl.size(); i++)
		file2 << ' ' << myvectorswap2stl[i];
	file2 << std::endl;
	file2 << std::endl;

	if (compare_files("MODIFIERS TESTS SWAP", 0, "vector") == 0)
		resize_files(file, file2, "vector");
	

	/* MODIFIERS TESTS: CLEAR MY VECTOR */
	ft::vector<int> myvectorclear;

	file << "MODIFIERS TESTS CLEAR" << std::endl;
	file << "Push back 100, 200, 300" << std::endl;

	file << "Vector contains:";
	for (unsigned i = 0; i < myvectorclear.size(); i++)
		file << ' ' << myvectorclear[i];
	file << std::endl;

	file << "Size of vector: " << myvectorclear.size() << std::endl;
	file << "Capacity of vector: " << myvectorclear.capacity() << std::endl;
	file << "Max size of vector: " << myvectorclear.max_size() << std::endl;

	file << "Clear the vector" << std::endl;
	myvectorclear.clear();
	file << "Push back 1042, 3022" << std::endl;
	myvectorclear.push_back(1042);
	myvectorclear.push_back(3022);

	file << "Vector contains:";
	for (unsigned i = 0; i < myvectorclear.size(); i++)
		file << ' ' << myvectorclear[i];
	file << std::endl;

	file << "Size of vector: " << myvectorclear.size() << std::endl;
	file << "Capacity of vector: " << myvectorclear.capacity() << std::endl;
	file << "Max size of vector: " << myvectorclear.max_size() << std::endl;
	file << std::endl;

	/* MODIFIERS TESTS: CLEAR STL VECTOR */
	std::vector<int> myvectorclearstl;

	file2 << "MODIFIERS TESTS CLEAR" << std::endl;
	file2 << "Push back 100, 200, 300" << std::endl;

	file2 << "Vector contains:";
	for (unsigned i = 0; i < myvectorclearstl.size(); i++)
		file2 << ' ' << myvectorclearstl[i];
	file2 << std::endl;

	file2 << "Size of vector: " << myvectorclearstl.size() << std::endl;
	file2 << "Capacity of vector: " << myvectorclearstl.capacity() << std::endl;
	file2 << "Max size of vector: " << myvectorclearstl.max_size() << std::endl;

	file2 << "Clear the vector" << std::endl;
	myvectorclearstl.clear();
	file2 << "Push back 1042, 3022" << std::endl;
	myvectorclearstl.push_back(1042);
	myvectorclearstl.push_back(3022);

	file2 << "Vector contains:";
	for (unsigned i = 0; i < myvectorclearstl.size(); i++)
		file2 << ' ' << myvectorclearstl[i];
	file2 << std::endl;

	file2 << "Size of vector: " << myvectorclearstl.size() << std::endl;
	file2 << "Capacity of vector: " << myvectorclearstl.capacity() << std::endl;
	file2 << "Max size of vector: " << myvectorclearstl.max_size() << std::endl;
	file2 << std::endl;

	if (compare_files("MODIFIERS TESTS CLEAR", 0, "vector") == 0)
		resize_files(file, file2, "vector");
	

	/* RELATIONAL OERATOR TESTS: MY VECTOR */
	ft::vector<int> myvectorrel1(3, 100);         // three ints with a value of 100
	ft::vector<int> myvectorrel2(2, 200);         // two ints with a value of 200

	file << "RELATIONAL OPERATOR TESTS" << std::endl;
	file << "myvectorrel1 contains:";
	for (unsigned i = 0; i < myvectorrel1.size(); i++)
		file << ' ' << myvectorrel1[i];
	file << std::endl;

	file << "myvectorrel2 contains:";
	for (unsigned i = 0; i < myvectorrel2.size(); i++)
		file << ' ' << myvectorrel2[i];
	file << std::endl;

	if (myvectorrel1 == myvectorrel2)
		file << "myvectorrel1 and myvectorrel2 are equal" << std::endl;
	if (myvectorrel1 != myvectorrel2)
		file << "myvectorrel1 and myvectorrel2 are not equal" << std::endl;
	if (myvectorrel1 <  myvectorrel2)
		file << "myvectorrel1 is less than myvectorrel2" << std::endl;
	if (myvectorrel1 >  myvectorrel2)
		file << "myvectorrel1 is greater than myvectorrel2" << std::endl;
	if (myvectorrel1 <= myvectorrel2)
		file << "myvectorrel1 is less than or equal to myvectorrel2" << std::endl;
	if (myvectorrel1 >= myvectorrel2)
		file << "myvectorrel1 is greater than or equal to myvectorrel2" << std::endl;
	file << std::endl;

	/* RELATIONAL OERATOR TESTS: STL VECTOR */
	std::vector<int> myvectorrel1stl(3, 100);         // three ints with a value of 100
	std::vector<int> myvectorrel2stl(2, 200);         // two ints with a value of 200

	file2 << "RELATIONAL OPERATOR TESTS" << std::endl;
	file2 << "myvectorrel1 contains:";
	for (unsigned i = 0; i < myvectorrel1stl.size(); i++)
		file2 << ' ' << myvectorrel1stl[i];
	file2 << std::endl;

	file2 << "myvectorrel2 contains:";
	for (unsigned i = 0; i < myvectorrel2stl.size(); i++)
		file2 << ' ' << myvectorrel2stl[i];
	file2 << std::endl;

	if (myvectorrel1stl == myvectorrel2stl)
		file2 << "myvectorrel1 and myvectorrel2 are equal" << std::endl;
	if (myvectorrel1stl != myvectorrel2stl)
		file2 << "myvectorrel1 and myvectorrel2 are not equal" << std::endl;
	if (myvectorrel1stl <  myvectorrel2stl)
		file2 << "myvectorrel1 is less than myvectorrel2" << std::endl;
	if (myvectorrel1stl >  myvectorrel2stl)
		file2 << "myvectorrel1 is greater than myvectorrel2" << std::endl;
	if (myvectorrel1stl <= myvectorrel2stl)
		file2 << "myvectorrel1 is less than or equal to myvectorrel2" << std::endl;
	if (myvectorrel1stl >= myvectorrel2stl)
		file2 << "myvectorrel1 is greater than or equal to myvectorrel2" << std::endl;
	file2 << std::endl;

	if (compare_files("RELATIONAL OPERATOR TESTS", 0, "vector") == 0)
		resize_files(file, file2, "vector");
	
	std::cout << std::endl;
	std::cout << BOLD "================ " NC CYN "VECTOR TESTS FINISHED" NC BOLD " ================" << std::endl;
	return (1);
}