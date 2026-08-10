#include "Serializer.hpp"
#include <cstdint>
#include <iostream>

int	main()
{
	//Serializer a; -- to show it cannot create instance. 
	Data	d;
	
	uintptr_t ser_ptr = Serializer::serialize(&d);

	Data* res;

	res = Serializer::desrialize(ser_ptr);

	std::cout << "address of d: " << &d << std::endl;
	std::cout << "value of ser_ptr: " << ser_ptr << std::endl;
	std::cout << "value of deser: " << res << std::endl;

	std::cout << "----- check values -----" << std::endl;

	std::cout << res->geti() << std::endl;
	std::cout << res->getf() << std::endl;
	std::cout << res->getd() << std::endl;
	std::cout << res->getstr() << std::endl;
	
	return 0;
}