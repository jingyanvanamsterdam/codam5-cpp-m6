#include <string>
#include <iostream>
#include <iomanip>
#include <climits>

int main(int argc, char *argv[])
{
	(void)argc;
	std::string lit(argv[1]);
	
	int res = 0;
	float f_res = static_cast<float>(res);
	double d_res = static_cast<double>(res);
	
	double temp = std::stod(lit);
	std::cout << "temp: " << temp << std::endl;

	std::cout << "char: ";
	if (temp < 1 || temp > 127)
		std::cout << "Impossible" << std::endl;
	else
	{
		if (isprint(temp))
			std::cout << static_cast<char>(temp) << std::endl;
		else
			std::cout << "Non displayble" << std::endl;
	}
	
	std::cout << "int: ";
	if (temp > INT_MAX || temp < INT_MIN)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(temp) << std::endl;
	
	std::cout << std::setprecision(20);
	std::cout << "float: " << static_cast<float>(temp) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(temp) << std::endl;
}