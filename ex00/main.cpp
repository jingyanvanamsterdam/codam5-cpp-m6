#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

/** TEST CASES
 * // for char 
 * a
 * *
 * (
 * /
 * @
 * 31
 * 32
 * 42
 * 65
 * 126
 * 127
 * 128
 * -1
 * 
 * // invaild input
 * -1.0.0
 * -11.0ff
 * 
 * //int
 * 2147483647
 * 2147483647.9
 * 2147483648
 * -2147483648
 * -2147483648.9
 * 
 * // float
 * 1e-50: underflow for float, too small->0.0f
 * 1e50: overflow for float, impossible. 
 * percision of float: more than 7 digits of a int, the number will change for float
 * 16777218 -> 2²⁴ 
 * 16777216
 * 
 * 1e-40：subnormal float
 * 1e-50
 * 1e38
 * 3.4028235e38
 * 3.5e38
 * 1e39
 * 1e300
 * 
 * // 0.0 & -0.0
 * 
 * // double -> stod fail
 * 1e999
 * 1e-999
 * 1e308 
 * 1e309 out of range
 * 
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