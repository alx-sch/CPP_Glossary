#include <string>
#include <iostream>

#include "../include/ScalarConverter.hpp"

// No special behavior for the constructors or destructor needed as class is non-instantiateable

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const std::string& dummy) {
	(void)dummy;
}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

/// Conversion functions

void ScalarConverter::convert(const std::string& input) {
	// Conversion logic goes here
	std::cout << "Converting: " << input << std::endl;
	// For demonstration, just print the input
	printChar(42.0); // Example value
	printInt(42.0);
	printFloat(42.0f);
	printDouble(42.0);
}