#pragma once
#include <cmath>
#include <iostream>

#define MAX(a, b) ((a) > (b) ? (a) : (b)) 
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define POW(a, b) (std::pow((a), (b)))
#define IS_GREATER(a, b) ((a) > (b))

#define ENTER_VARIABLE(title, var) \
	std::cout << "Enter value for " << title << ": "; \
	std::cin >> var;

#define PRINT_RESULT(content) std::cout << "The result is: " << content << std::endl;