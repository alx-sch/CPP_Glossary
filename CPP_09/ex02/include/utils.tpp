#ifndef UTILS_TPP
# define UTILS_TPP

# include <iostream>
# include <iomanip>	// setw()
# include <sstream>	// stringstream

# include "../include/define.hpp"	// for color codes, WIDTH_N, WIDTH_C    

// Prints if the container is sorted in a non-decreasing order or not.
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
			std::cout << RED << "NOT SORTED" << RESET << std::endl;
			return;
		}
		++it;
		++next;
	}
	std::cout << GREEN << "SORTED" << RESET << std::endl; // All elements sorted
}

// Prints the content of any container.
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
	std::cout << std::endl;
}

// Returns the content of any container with formatting as a string.
// Great for debugging!
template <typename Container>
std::string	returnContainerDebug(const Container& c, const std::string& prefix)
{
	std::stringstream	ss;
	ss << prefix << GREEN;
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
		ss << *it << " ";
	ss << RESET;
	return ss.str();
}

// Prints out numbers before sorting (`argv`) and after sorting (sorted container).
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
