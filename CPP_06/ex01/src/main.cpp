#include <iostream>
#include "../include/Serializer.hpp"

int	main()
{
 { // Valid pointer
	Data*	data = new Data;
	if (!data) {
		std::cerr << "Error: Memory allocation failed.\n";
		return 1;
	}
	data->id = 42;
	data->name = "Max";

	std::count << 
	uintptr_t	raw = Serializer::serialize(data);
	std::cout << "Serialized pointer: " << raw << "\n";

 }

}