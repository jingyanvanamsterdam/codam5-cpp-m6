#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	public:
		ScalarConverter(void) = delete;
		ScalarConverter(const ScalarConverter& obj) = delete;
		ScalarConverter& operator=(const ScalarConverter& obj) = delete;
		~ScalarConverter(void) = delete;

		static void convert(std::string& literal);
	private:


};



#endif