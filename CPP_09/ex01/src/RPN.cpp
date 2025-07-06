#include <stack>
#include <string> // empty(), find_first_not_of()
#include <cctype> // isdigit(), isspace()
#include <stdexcept> // runtime_error()
#include "../include/RPN.hpp"

// Forward declaration: Internal helpers (not part of the class)
static bool		isOperator(char c);
static double	applyOperator(double l_op, double r_op, char op);

////////////
// Method //
////////////

/**
Evaluates a Reverse Polish Notation (RPN) expression.
The expression is expected to contain single-digit integers and operators,
separated by whitespace. Valid operators are: +, -, *, /.
Example: "3 4 + 2 * 7 /"

@param expression	The RPN expression to evaluate.
@return 			The result of the evaluated expression as a double.
@throws 			std::runtime_error if the expression is invalid or malformed.
*/
double	RPN::calculate(const std::string& expression)
{
	std::stack<double>	stack;

	if (expression.empty() || expression.find_first_not_of(" \t\n\r\f\v") == std::string::npos)
		throw std::runtime_error("Empty expression.");

	for (size_t i = 0; i < expression.length(); ++i)
	{
		char	c = expression[i];

		if (std::isspace(c)) // Skip whitespace characters
			continue;

		if (std::isdigit(c))
		{
			stack.push(static_cast<double>(c - '0')); // Convert char to int
		}
		else if (isOperator(c))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Not enough operands.");
			
			double	r_op = stack.top(); stack.pop();
			double	l_op = stack.top(); stack.pop();

			double result = applyOperator(l_op, r_op, c);
			stack.push(result); // Push the result back onto the stack
		}
		else
		{
			throw std::runtime_error("Invalid character '" + std::string(1, c) + "'");
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("Malformed expression. Not enough operators or operands.");

	return stack.top(); // Return the final result
}

////////////
// HELPER //
////////////

// Checks if character is a valid operator (`+`, `-`, `*`, `/`).
static bool	isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Applies the operator to the two operands and returns the result.
// Throws an exception if division by zero is attempted or if the operator is invalid.
static double	applyOperator(double l_op, double r_op, char op)
{
	switch (op)
	{
		case '+':
			return l_op + r_op;
		case '-':
			return l_op - r_op;
		case '*':
			return l_op * r_op;
		case '/':
			if (r_op == 0)
				throw std::runtime_error("Division by zero.");
			return l_op / r_op;
		default: // Should never happen if isOperator() is used, but just in case
			throw std::runtime_error("Invalid operator '" + std::string(1, op) + "'");
	}
}
