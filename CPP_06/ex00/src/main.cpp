#include <iostream>
#include "../include/ScalarConverter.hpp"

#include <cfloat>

int main(int argc, char** argv) {

	std::cout << "float max: " << FLT_MAX << "\n";
    std::cout << "float min: " << FLT_MIN << "\n";
    std::cout << "double max: " << DBL_MAX << "\n";
    std::cout << "double min: " << DBL_MIN << "\n";

	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <value>\n";
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	return 0;
}
