#include "vector.hpp"
#include "stack.hpp"
#include <vector>

using namespace std;

#define TESTED_TYPE int

int             main(void)
{
        ft::vector<TESTED_TYPE> vct(7);
        ft::vector<TESTED_TYPE> vct_two(4);
        ft::vector<TESTED_TYPE> vct_three;
        ft::vector<TESTED_TYPE> vct_four;

        for (unsigned long int i = 0; i < vct.size(); ++i)
                vct[i] = (vct.size() - i) * 3;
        for (unsigned long int i = 0; i < vct_two.size(); ++i)
                vct_two[i] = (vct_two.size() - i) * 5;
        /*printSize(vct);
        printSize(vct_two);*/

/*        vct_three.assign(vct.begin(), vct.end());
*/        vct.assign(vct_two.begin(), vct_two.end());
		for (ft::vector<int>::iterator it = vct_two.begin(); it != vct_two.end(); ++it)
			std::cout << *it << std::endl;
		for (ft::vector<int>::iterator it = vct.begin(); it != vct.end(); ++it)
			std::cout << *it << std::endl;
        /*vct_two.assign(2, 42);
        vct_four.assign(4, 21);*/

        std::cout << "\t### After assign(): ###" << std::endl;

        /*printSize(vct);
        printSize(vct_two);
        printSize(vct_three);
        printSize(vct_four);*/
		/*for (ft::vector<int>::iterator it = vct_four.begin(); it != vct_four.end(); ++it)
			std::cout << *it << std::endl;

		std::cout << "Valeur de size: " << vct_four.size() << " et valeur de capacity: " << vct_four.capacity() << std::endl;

		std::vector<int> v(4, 21);

		for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << "Valeur de size: " << v.size() << " et valeur de capacity: " << v.capacity() << std::endl;*/
        /*vct_four.assign(6, 84);
        printSize(vct_four);

        std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

        vct.assign(5, 53);
        vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

        printSize(vct);
        printSize(vct_two);*/

        return (0);
}
