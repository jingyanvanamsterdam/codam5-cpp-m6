#include "ScalarConverter.hpp"
#include <string>
#include <iostream>


//static void	cast_char(std::string& lit);
//static void	cast_int(std::string& lit);
//static void	cast_float(std::string& lit);
//static void	cast_double(std::string& lit);

void	ScalarConverter::convert(std::string& literal)
{
	std::cout <<  literal << "." << std::endl;

	/**
	 * parse input: 
	 * 1. +0123456
	 * 2. -123456
	 * 3. +0123456f
	 * 4. -0123456f
	 * 5. 0.1236.5f
	 * 6. -inff, +inff, nanf -- float
	 * 7. -inf, +inf, nan -- double
	 */

	if (!isdigit(literal[0]) && !isalpha(literal[0]) && literal[0] != '+' && literal[0] != '-')
	{
		std::cout << "Invalid number input!" << std::endl;
		return ;
	}



	//std::cout << "char: ";
	//cast_char(literal);
	//std::cout << "int: ";
	//cast_int(literal);
	//std::cout << "float: ";
	//cast_float(literal);
	//std::cout << "double: ";
	//cast_double(literal);
}