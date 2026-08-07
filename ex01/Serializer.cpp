#include <cstdint>
#include "Serializer.hpp"

Serializer::Serializer(void) = default;
Serializer::Serializer(const Serializer& obj) = default;
Serializer& Serializer::operator=(const Serializer& obj) = default;
Serializer::~Serializer(void) = default;

std::uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<std::uintptr_t>(ptr);
}

Data* Serializer::desrialize(std::uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}