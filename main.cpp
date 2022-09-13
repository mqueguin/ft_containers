#include <iostream>
#include <fstream>
#include "tester.hpp"

int main(int ac, char **av) {

	if (ac != 2) {
		std::cout << "Usage: ./tester [vector|stack|map]" << std::endl;
		return (1);
	}

	std::string test = av[1];

	if (test == "vector") {
		ft_vector();
	} else if (test == "stack") {
		ft_stack();
	} else if (test == "map") {
		ft_map();
	} else {
		std::cout << "Usage: ./tester [vector|stack|map]" << std::endl;
		return (1);
	}

	return (0);
}