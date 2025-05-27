#include <iostream>

#include "../include/ScalarConverter.hpp"
#include "../include/utils.hpp"

// No need to dfine private constructors or destructors as there is no instantiation of ScalarConverter
// Use default behavior

// Convert the input string to various scalar types and print the results.
void ScalarConverter::convert(const std::string& input)
{
	if (input.empty()) {
		printImpossible(input);
		return;
	}

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

	if (isIntLiteral(input)) {
		double	val = std::strtod(input.c_str(), NULL);
		printChar(val);
		printInt(val);
		printFloatDouble(val);
		return;
	}

	if (isFloatLiteral(input)) {
		std::string	core = input.substr(0, input.size() - 1); // Clean up the 'f' at the end
		double	val = std::strtod(core.c_str(), NULL);
		printChar(val);
		printInt(val);
		printFloatDouble(val);
		return;
	}
	
	if (isDoubleLiteral(input)) {
		double	val = std::strtod(input.c_str(), NULL);
		printChar(val);
		printInt(val);
		printFloatDouble(val);
		return;
	}

	if (isCharLiteral(input)) {
		char	c = input[0];
		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << ".0f\n";
		std::cout << "double: " << static_cast<double>(c) << ".0\n";
		return;
	}

	printImpossible(input);
}
