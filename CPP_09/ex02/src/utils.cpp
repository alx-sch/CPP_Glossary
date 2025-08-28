#include <iostream>
#include <iomanip>		// setw()
#include <sstream>		// for std::ostringstream
#include <cmath>		// ceil(), log2()

#include "../include/utils.hpp"
#include "../include/define.hpp"	// for color codes, WIDTH_N, WIDTH_C

// Returns `timeval` struct representing the current time.
timeval	getCurrentTimeStruct()
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv);
}

// Returns the elapsed time in microseconds between two `timeval` structs.
static long	getElapsedTime(const timeval& start, const timeval& end)
{
	long	sec = end.tv_sec - start.tv_sec;
	long	usec = end.tv_usec - start.tv_usec;

	return (sec * 1000000 + usec); // sec * 1000 = msec * 1000 = usec
}

// Prints a formatted elapsed time message.
void	printElapsedTime(const timeval& start, const timeval& end, int elements,
			const std::string& contName)
{
	long	elapsed = getElapsedTime(start, end);

	std::cout	<< "Time to process " << YELLOW << std::right << std::setw(WIDTH_N)
				<< elements << " numbers" << RESET << " with "
				<< YELLOW << std::left << std::setw(WIDTH_C) << contName << RESET << ": "
				<< YELLOW << elapsed << " us" << RESET << std::endl;
}

// Prints the number of comparisons made and checks if this is within the limit
// of comparisons in a Ford-Johnson implementation
void	printNumComp(int numComp, int maxComp, const std::string& contName)
{
	std::cout	<< "Number of comparisons (" << YELLOW
				<< std::left << std::setw(WIDTH_C) << contName << RESET
				<< "): " << YELLOW << numComp << RESET
				<< " / " << maxComp;

	if (numComp <= maxComp)
		std::cout << GREEN << " OK" << RESET << std::endl;
	else
		std::cout << RED << " NOT OK" << RESET << std::endl;
}

// Converts a `size_t` to a string.
// Used for debugging.
std::string	toString(size_t n)
{
	std::ostringstream	oss;
	
	oss << n;
	return oss.str();
}

// Gives the maximum number of comparisons with the Ford-Johnson algorithm to
// sort a sequence of `n` integers.
// See p. 186, The Art of Computer Programming (vol. 3, 1998), Donald E. Knuth
int	maxComparisonsFJ(int n)
{
	int	sum = 0;

	for (int k = 1; k <= n; ++k)
	{
		double	value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}

	return sum;
}
