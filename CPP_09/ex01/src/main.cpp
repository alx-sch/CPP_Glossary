/**
Reverse Polish Notation (RPN):
A mathematical notation where operators follow their operands, also known as postfix notation.
In RPN, operators are written after their operands instead of between them (infix notation).

Regular notation: 3 + 4
RPN notation: 3 4 +

Operators are applied to the two most recent operands on the stack:
*/

#include <iostream>
#include "../include/RPN.hpp"

#define YELLOW	"\033[33m"
#define RED		"\033[31m"
#define BOLD	"\033[1m"
#define RESET	"\033[0m"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr	<< YELLOW << "Usage: " << argv[0] << " \"7 7 * 7 -\"" << RESET
					<< "   # Reverse Polish Notation\n\n"
					<< "Note:\n"
					<< "  - Only single-digit integers are allowed.\n"
					<< "  - Supported operators: +, -, *, /\n"
					<< "  - Brackets and decimal numbers are not supported.\n";
		return 1;
	}

	try
	{
		double	result = RPN::calculate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << BOLD <<  "Error: " << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}
