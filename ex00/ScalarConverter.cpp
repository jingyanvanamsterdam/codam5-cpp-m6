#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>
#include <limits>

static void	cast_to_char(double nb)
{
	if (!std::isfinite(nb) || std::trunc(nb) != nb)
		std::cout << "char: impossible" << std::endl; 
	else if (static_cast<int>(nb) > 127 || static_cast<int>(nb) < 0)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(nb)))
		std::cout << "char: Non displable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
}
static void	cast_char(std::string& lit)
{
	double	d = static_cast<double>(lit[0]);
	cast_to_char(d);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " << d << std::endl;
}
static void	cast_to_int(double nb)
{
	if (!std::isfinite(nb)
		|| nb < std::numeric_limits<int>::min() 
		|| nb > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	nb = std::trunc(nb);	
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
}
static void	cast_to_float(double nb)
{
	if (nb < std::numeric_limits<float>::lowest() 
		|| nb > std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}

	if (std::trunc(nb) == nb)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;	
		
}

bool	is_edge_case(std::string& literal)
{
	std::string edge_cases[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	int i = -1;
	while (++i < 6)
		if (literal == edge_cases[i])
			break;
	
	if (i == 6)
		return false;
	
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	switch ((i + 1) % 3)
	{		
		case 1:
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			break;
		case 2:
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			break;
		default:
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			break;
	}
	return true;
}

std::string parse_input(std::string& literal)
{
	size_t start = literal.find_first_not_of(" \t\n\f\v\r");
	size_t end = literal.find_last_not_of(" \t\n\f\v\r");
	if (start == std::string::npos)
		throw ScalarConverter::InvalidException();
	if (end == std::string::npos)
		end = literal.length() - 1;
	return (literal.substr(start, end - start + 1));
}

void	ScalarConverter::convert(std::string& literal)
{
	literal = parse_input(literal);
	
	if (is_edge_case(literal))
		return ;
	
	if (literal.length() == 1 && !isdigit(literal[0]))
		return (cast_char(literal));
	try 
	{
		size_t	pos;
		double nb = std::stod(literal, &pos);
		if (pos != literal.length())
			if(!(pos == literal.length() - 1 && literal[pos] == 'f'))
				throw ScalarConverter::InvalidException();
		cast_to_char(nb);
		cast_to_int(nb);
		cast_to_float(nb);
		if (std::trunc(nb) == nb)
			std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << nb << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Number overflow for double" << std::endl;
	}
	catch (const std::exception& e)
	{
		throw ScalarConverter::InvalidException();
	}
}

const char* ScalarConverter::InvalidException::what() const noexcept
{
	return "Invalid input";
}