#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <string>
#include "Data.hpp"

class Data;

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* desrialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(const Serializer& obj);
		Serializer& operator=(const Serializer& obj);
		~Serializer(void);
};

#endif