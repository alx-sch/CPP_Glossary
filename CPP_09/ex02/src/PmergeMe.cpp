#include <cstdlib>		// for strtol(), atoi()
#include <climits>		// for INT_MAX
#include <cerrno>		// for errno, ERANGE
#include <stdexcept>	// runtime_error()
#include <string>
#include <vector>

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

std::vector<int>	PmergeMe::sortVec(int argc, char** argv)
{
	std::vector<int>	vec;

	// Fill vector
	vec.reserve(argc - 1); // helps with performance, avoids repeated reallocation in growing vec
	for (int i = 1; i < argc; ++i)
	{
		vec.push_back(std::atoi(argv[i]));
	}

	return vec;
}
