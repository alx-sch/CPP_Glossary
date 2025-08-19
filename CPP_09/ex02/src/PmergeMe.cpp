#include <cstdlib>		// strtol()
#include <climits>		// INT_MAX
#include <cerrno>		// errno, ERANGE
#include <stdexcept>	// runtime_error()
#include <string>

#include "../include/PmergeMe.hpp"

// Checks if the provided arguments are valid integers.
// Throws exceptions for non-numeric values, non-positive numbers,
// and integers exceeding INT_MAX.
void	PmergeMe::checkArgs(int argc, char** argv)
{
	char		*endptr;
	long		val;
	std::string	arg;

	for (int i = 1; i < argc; ++i)
	{
		arg = std::string(argv[i]); // Convert C-style string (const char*) to std::string
		errno = 0;
		val = strtol(argv[i], &endptr, 10); // Convert to long (base 10); might set errno

		if (*argv[i] == '\0' || *endptr != '\0')
		{
			throw std::runtime_error("Invalid input, not an integer: '" + arg + "'");
		}

		if (errno == ERANGE || val > INT_MAX)
		{
			throw std::runtime_error("Integer overflow: value exceeds INT_MAX: " + arg);
		}

		if (val <= 0)
		{
			throw std::runtime_error("Only positive integers are allowed [1, INT_MAX]: " + arg);
		}
	}
}
