#include "map.hpp"
#include <map>

int main(void) {
	ft::map<int, char> ft_map;

	ft_map[1] = 'a';
	ft_map[2] = 'b';
	ft_map[3] = 'c';
	ft_map[4] = 'd';
	ft_map[5] = 'e';
	ft_map[6] = 'f';

	ft::map<int, char>::iterator it = ft_map.begin();
	std::cout << "Valeur de it avant ++ : " << it->first << std::endl;
	it++;
	std::cout << "Valeur de it apres ++ : " << it->first << std::endl;
	std::cout << std::endl;
	it++;
	std::cout << "Valeur de it apres ++ : " << it->first << std::endl;
}
