#ifndef TESTER_HPP
#define TESTER_HPP

#include <fstream>
#include <iostream>
#include <string>
#include "map.hpp"
#include "vector.hpp"
#include "stack.hpp"

int		compare_files(const std::string &test, bool is_out_of_range, const std::string &file_name);
void	resize_files(std::ofstream &file, std::ofstream &file2, const std::string &file_name);

int		ft_stack(void);
int		ft_vector(void);
int		ft_map(void);

#endif