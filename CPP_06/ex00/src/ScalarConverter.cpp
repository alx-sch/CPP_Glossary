#include <iostream>
#include <sstream>	// for std::ostringstream
#include <cmath>	// for floor()
#include <iomanip>	// for std::setprecision()

#include "../include/ScalarConverter.hpp"
#include "../include/ScalarConverterUtils.hpp"

// No need to dfine private constructors or destructors as there is no instantiation of ScalarConverter
// Use default behavior

// Makes sure to add ".0" suffix for integer values when printing float and double representations.
static std::string	getSuffix(double val)
{
	if (std::floor(val) == val)
		return ".0";
	return "";
}

// Prints the character representation of a value (or "Non displayable" if not printable).
// If not in the range of a char (0-255), prints "impossible".
static void	printChar(double val)
{
	std::cout << "char: ";
	if (val < 0 || val > 255)
		std::cout << "impossible\n";
	else {
		unsigned char c = static_cast<unsigned char>(val);
		if (c < 32 || c > 126)
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << c << "'\n";
	}	
}

// Prints the integer representation of a value.
static void	printInt(double val)
{
	std::cout << "int: ";
	if (val < INT_MIN || val > INT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(val) << "\n";
}

void printFloat(float val)
{
	if (std::floor(val) == val)
		std::cout << std::fixed << std::setprecision(1) << val; // For integer values, print with one decimal place (e.g., 42.0)
	else
		std::cout << std::setprecision(15) << val;
	std::cout << "f\n";
}

void printDouble(double val)
{
	std::cout << "double: ";
	if (std::floor(val) == val)
		std::cout << std::fixed << std::setprecision(1) << val; // For integer values, print with one decimal place (e.g., 42.0)
	else
		std::cout << std::setprecision(15) << val;
	std::cout << "\n";
}

void ScalarConverter::convert(const std::string& input)
{
	if (isPseudoLiteral(input)) {
		std::string	floatOutput = input;
		std::string	doubleOutput = input;

		if (isFloatPseudoLiteral(input))
			doubleOutput = input.substr(0, input.size() - 1);
		else
			floatOutput = input + "f";
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << floatOutput << "\n";
		std::cout << "double: " << doubleOutput << "\n";
		return;
	}

	else if (isIntLiteral(input)) {
		char*	endptr;
		long	val = std::strtol(input.c_str(), &endptr, 10);

		printChar(static_cast<double>(val));
		std::cout << "int: " << static_cast<int>(val) << "\n";
		std::cout << "float: " << static_cast<float>(val) << ".0f\n";
		std::cout << "double: " << static_cast<double>(val) << ".0\n";
		return;
	}

	else if (isFloatLiteral(input)) {
		std::string	core = input.substr(0, input.size() - 1);
		char*		endptr;
		float		val = std::strtof(core.c_str(), &endptr);
		std::string	suffix = getSuffix(static_cast<double>(val));

		printChar(static_cast<double>(val));
		printInt(static_cast<double>(val));
		std::cout << "float: " << val << suffix << "f\n";
		std::cout << "double: " << static_cast<double>(val) << suffix << "\n";
		return;
	}
	
	else if (isDoubleLiteral(input)) {
		char*	endptr;
		double	val = std::strtod(input.c_str(), &endptr);
		std::string	suffix = getSuffix(static_cast<double>(val));

		printChar(static_cast<double>(val));
		printInt(static_cast<double>(val));
		std::cout << "float: " << static_cast<float>(val) << "f\n";
		printDouble(val);
		return;
	}

	else if (isCharLiteral(input)) {
		char c = input[0];
		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << "f\n";
		std::cout << "double: " << static_cast<double>(c) << "\n";
		return;
	}

	else {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
}
