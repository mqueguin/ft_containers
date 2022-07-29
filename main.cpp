#include "vectorIterator.hpp"

#include <iostream>
#include <fstream>

int main(void) {
    int tab[5] = {1, 2, 3, 4, 5};

    ft::vectorIterator<int> it;
    it = &tab[0];
    ft::vectorIterator<int> it_end = &tab[4];

    while (it != it_end) {
        std::cout << *it << std::endl;
        ++it;
    }
    return (0);
}