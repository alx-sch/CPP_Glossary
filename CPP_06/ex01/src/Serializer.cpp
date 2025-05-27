#include <iostream>
#include "../include/Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr)
{
	if (!ptr) {
		std::cerr << "Error: Null pointer cannot be serialized.\n";
		return 0;
	}
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	if (raw == 0) {
		std::cerr << "Error: Raw pointer is null and cannot be deserialized.\n";
		return NULL;
	}
	return (reinterpret_cast<Data*>(raw));
}
