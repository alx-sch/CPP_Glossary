#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iomanip>		// setw()
# include <vector>
# include <sys/time.h>	// timeval

# include "../include/define.hpp"	// for color codes, WIDTH_C

void	printBeforeAfter(char** argv, std::vector<int>& afterSort);
timeval	getCurrentTimeStruct();
void	printElapsedTime(const timeval& start, const timeval& end, int elements,
			const std::string& contName);
void	printNumComp(int numComp, const std::string& contName);

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

#endif
