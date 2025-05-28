#include <iostream>
#include <stdexcept> // for std::bad_alloc
#include "../include/Serializer.hpp"

int	main()
{
	// Define a simple struct obj
	Data	data; 
	data.id = 42;
	data.name = "Max";
	std::cout << "Pointer to object with: id: '" << data.id << "' and name: '" << data.name << "'\n";
	std::cout << "Pointer points to: " << &data << "\n";

	// Serialize the pointer
	uintptr_t	raw = Serializer::serialize(&data);
	std::cout << "Serialized pointer: " << raw << "\n";

	// Deserialize the pointer
	if (raw) {
		Data*	deserializedData = Serializer::deserialize(raw);
		std::cout << "Deserialized pointer points to: " << deserializedData << "\n";
		std::cout << "'Deserialized' object has: id: '" << deserializedData->id << "' and name: '" << deserializedData->name << "'\n";
	} else {
		std::cout << "Deserialized pointer is NULL\n";
		return 1;
	}
	
	return 0;
}
