#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Not enough argument. Please input a number to convert." << std::endl;
		return (1);
	}

	std::string lit(argv[1]);
	try
	{
		ScalarConverter::convert(lit);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}