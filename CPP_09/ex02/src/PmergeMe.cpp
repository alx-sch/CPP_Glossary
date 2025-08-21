
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
	char*		endptr;
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

		if (val < 0)
		{
			throw std::runtime_error("Only positive integers are allowed [0, INT_MAX]: " + arg);
		}
	}
}

/**
Generates a dynamically allocated array containing the Jacobsthal sequence
indices less than the given number of pending elements.

The Jacobsthal sequence is defined as follows:
J(0) = 0, J(1) = 1, J(n) = J(n-1) + 2 * J(n-2) for n > 1

The array ends with a sentinel value of `-1`, allowing easy iteration.
The caller is responsible for freeing the array using `delete[]`.
*/
int*	PmergeMe::generateJacobsthalSeq(int numPending)
{
	if (numPending <= 0)
	{
		return NULL;
	}

	int	j1 = 0, j2 = 1; // first and second Jacobsthal numbers
	int	count = 0;

	if (j1 < numPending) ++count; // count J(0)
	if (j2 < numPending) ++count; // count J(1)

	// Count how many Jacobsthal numbers < numPending
	while (1)
	{
		int	jNext = j2 + 2 * j1; // J(n) = J(n-1) + 2*J(n-2)
		if (jNext >= numPending)
		{
			break;
		}
		++count; // increment number of valid Jacobsthal numbers
		j1 = j2;
		j2 = jNext;
	}

	// Allocate array (user needs to free it after use)
	int*	jacSeq = new int[count + 1]; // + 1 for sentinel

	// Fill the array with the Jacobsthal sequence
	int idx = 0;
	j1 = 0;
	j2 = 1;

	if (j1 < numPending) jacSeq[idx++] = j1;
	if (j2 < numPending) jacSeq[idx++] = j2;

	while(idx < count)
	{
		int	jNext = j2 + 2 * j1;
		jacSeq[idx++] = jNext;
		j1 = j2;
		j2 = jNext;
	}

	jacSeq[idx] = -1; // add sentinel

	return jacSeq;
}
