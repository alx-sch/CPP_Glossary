#include <iostream>
#include "../include/Serializer.hpp"

// Converts Data pointers to uintptr_t. Returns 0 if the pointer is null.
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// Converts uintptr_t back to Data pointers. Returns NULL if the raw pointer is 0.
Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
