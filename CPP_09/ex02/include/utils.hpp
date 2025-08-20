#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>
# include <iomanip>		// setw()
# include <sys/time.h>	// timeval

# include "../include/define.hpp"	// for color codes, WIDTH_C

timeval		getCurrentTimeStruct();
void		printElapsedTime(const timeval& start, const timeval& end, int elements,
				const std::string& contName);
void		printNumComp(int numComp, const std::string& contName);
std::string	toString(size_t n);

// Prints if the container is sorted in a non-decreasing order or not
template <typename Container>
void	printIsSorted(const Container& c, const std::string& contName)
{
	typename Container::const_iterator	it = c.begin();
	typename Container::const_iterator	next = it;
	++next;

	std::cout	<< "Container " << YELLOW << std::left << std::setw(WIDTH_C)
				<< contName << RESET << " is ";

	while (next != c.end())
	{
		if (*it > *next) // Pair is not sorted
		{
			std::cout << RED << "not sorted" << RESET << std::endl;
			return;
		}
		++it;
		++next;
	}
	// All elements are sorted
	std::cout << GREEN << "sorted" << RESET << std::endl;
}

// Prints the content of any container
template <typename Container>
void	printContainer(const Container& c)
{
	typename Container::const_iterator	it = c.begin();

	while (it != c.end())
	{
		std::cout << *it;
		++it;
		if (it != c.end())
			std::cout << " ";
	}
}

// Prints the content of any container with formatting
// Great for debugging!
template <typename Container>
void	printContainerDebug(const Container& c, const std::string& prefix)
{
	std::cout << GREEN << prefix;
	printContainer(c);
	std::cout << RESET << std::endl;
}

// Prints out numbers before sorting (`argv`) and after sorting (sorted container)
template <typename Container>
void	printBeforeAfter(char** argv, const Container& afterSort)
{
	size_t	n = afterSort.size();

	std::cout << "Before: ";
	for (size_t i = 0; i < n; ++i)
	{
		std::cout << argv[i + 1] << " ";
	}
	std::cout << "\nAfter:  ";
	printContainer(afterSort);
	std::cout << std::endl;
}

#endif
