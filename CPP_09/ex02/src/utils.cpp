#include <iostream>
#include <iomanip>		// setw()
#include <vector>
#include <algorithm>	// sort()
#include <cstdlib>		// for atoi

#include <sys/time.h>	// for gettimeofday()

#include "../include/define.hpp"	// for color codes, WIDTH_N, WIDTH_C

// Returns `timeval` struct representing the current time
timeval	getCurrentTimeStruct()
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv);
}

// Returns the elapsed time in microseconds between two `timeval` structs
static long	getElapsedTime(const timeval& start, const timeval& end)
{
	long	sec = end.tv_sec - start.tv_sec;
	long	usec = end.tv_usec - start.tv_usec;

	return (sec * 1000000 + usec); // sec * 1000 = msec * 1000 = usec
}

// Prints a formatted elapsed time message
void	printElapsedTime(const timeval& start, const timeval& end, int elements,
			const std::string& contName)
{
	long	elapsed = getElapsedTime(start, end);

	std::cout	<< "Time to process " << YELLOW << std::right << std::setw(WIDTH_N)
				<< elements << " numbers" << RESET << " with "
				<< YELLOW << std::left << std::setw(WIDTH_C) << contName << RESET << ": "
				<< YELLOW << elapsed << " us" << RESET << std::endl;
}

// Prints numbers before and after sorting (expected, no sorting Ford-Johnson algo performed yet)
void	printBeforeAfter(int argc, char **argv)
{
	std::vector<int>	numbers;

	// Fill vector with command line arguments
	for (int i = 1; i < argc; ++i)
	{
		numbers.push_back(std::atoi(argv[i]));
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	// Just for printing 'expected' sorting result! 
	// Results of merge-insert sort algo implementation is tested separately via isSorted()
	std::sort(numbers.begin(), numbers.end());

	std::cout << "After:  ";
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}

// Prints the number of comparisons made
void	printNumComp(int numComp, const std::string& contName)
{
	std::cout	<< "Number of comparisons (" << YELLOW
				<< std::left << std::setw(WIDTH_C) << contName << RESET
				<< "): " << YELLOW << numComp << RESET << std::endl;
}
