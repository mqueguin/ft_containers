#include "vectorIterator.hpp"

#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
    int tab[5] = {1, 2, 3, 4, 5};

    ft::iterator<int> it;
    it = &tab[0];
    ft::iterator<int> it_end = &tab[4];

    while (it != it_end) {
        std::cout << *it << std::endl;
        ++it;
    }

   // std::vector<int> myvector;
    //for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

    // typedef std::vector<int>::iterator iter_type;

    ft::reverseIterator<int> rev_iterator = &tab[0];

     std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';

    return 0;
}