#include "../include/utils.hpp"

// Prints the character representation of an ASCII value (or "Non displayable" if not printable).
// If not in the range of a char (0-255), prints "impossible".
void	printChar(double val)
{
	std::cout << "char: ";
	if (val < 0 || val > 255)
		std::cout << "impossible\n";
	else {
		unsigned char	c = static_cast<unsigned char>(val);
		if (c < 32 || c > 126)
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << c << "'\n";
	}	
}

// Prints the integer representation of a value.
// Checks if value is within INT range, otherwise prints "impossible".
void	printInt(double val)
{
	std::cout << "int: ";
	if (val < INT_MIN || val > INT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(val) << "\n";
}

// Determines if a value will be printed in scientific notation.
static bool willPrintScientific(double val)
{
	std::ostringstream	oss;

	oss << val;
	std::string s = oss.str();
	return (s.find('e') != std::string::npos || s.find('E') != std::string::npos);
}

// Prints the float and double representations of a value.
// If the value is an integer, it prints with ".0" if not in scientific notation.
void	printFloatDouble(double val)
{
	if (std::floor(val) == val) { // Check if the value is an integer
		if (willPrintScientific(val)) { // Don't add ".0" for integers when printing in scientific notation
			std::cout << "float: " << static_cast<float>(val) << "f\n";
			std::cout << "double: " << val << "\n";
		} else { // Add ".0" for integers when not in scientific notation
			std::cout << "float: " << static_cast<float>(val) << ".0f\n";
			std::cout << "double: " << val << ".0\n";
		}
	} else {
		std::cout << "float: " << static_cast<float>(val) << "f\n";
		std::cout << "double: " << val << "\n";
	}
}

// Prints "impossible" for all types when the input cannot be converted to any of them.
// Makes sure to handle overflow and underflow for double types correctly
void	printImpossible(const std::string& s)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";

	// check if number is larger than double max or less than double min
	errno = 0;
	double	val = std::strtod(s.c_str(), NULL);
	if (errno == ERANGE) { // If strtod fails due to range error
		std::cout << "float: " << static_cast<float>(val) << "f\n"; // print inff / -inff
		std::cout << "double: " << val << "\n"; // print inf / -inf
	}
	else {
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
}
