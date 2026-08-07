#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

/** TEST CASES 
 * 1
 * a
 * *
 * (
 * /
 * @
 * a
 * A
 * 117
 * -1
 * -1.0.0
 * -11.0ff
 * -11f
 * 11.000000
 * 123.789
 * 123.6789
 * 123.45678
 * 1234567897541645648974549787485465489453486735498456
*/

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