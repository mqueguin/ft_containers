#include "iterator.hpp"
#include "reverseIterator.hpp"
#include "vector.hpp"
#include "stack.hpp"

#include <iostream>
#include <fstream>
#include <vector>

int main(void) {
   /* //int tab[5] = {1, 2, 3, 4, 5};
    ft::vector<int> tab(5, 9);
    ft::vector<int> tab2(tab);

    ft::vector<int> tab3(1, 4);

    if (tab == tab2)
        std::cout << "tab == tab2" << std::endl;
    else
        std::cout << "tab != tab2" << std::endl;

    if (tab2 == tab3)
        std::cout << "tab2 == tab3" << std::endl;
    else
        std::cout << "tab2 != tab3" << std::endl;

    std::cout << std::endl;
    
    ft::vector<int>::iterator it = tab.begin();

    while (it != tab.end()) {
        std::cout << *it << std::endl;
        ++it;
    }*/

    ft::stack<int> stack;

    std::cout << "JE passe bien ici" << std::endl;
    stack.push(41);
    std::cout << "Maintenant je passe ici" << std::endl;
    stack.push(29);

    std::cout << "J arrive a la fin du programme" << std::endl;
   // std::vector<int> myvector;
    //for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

    // typedef std::vector<int>::iterator iter_type;

    /*ft::reverseIterator<int> rev_iterator = &tab[0];

     std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';*/

    return 0;
}