#include "Serializer.hpp"
#include <cstdint>
#include <iostream>

int	main()
{
	//Serializer a; -- to show it cannot create instance. 
	Data	d;
	
	std::uintptr_t ser_ptr = Serializer::serialize(&d);

	Data* res;

	res = Serializer::desrialize(ser_ptr);

	std::cout << res->geti() << std::endl;
	std::cout << res->getf() << std::endl;
	std::cout << res->getd() << std::endl;
	std::cout << res->getstr() << std::endl;
	
	return 0;
}