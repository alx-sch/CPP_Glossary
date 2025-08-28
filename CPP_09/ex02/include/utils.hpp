#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <sys/time.h>	// timeval

// utils.cpp

timeval		getCurrentTimeStruct();
void		printElapsedTime(const timeval& start, const timeval& end, int elements,
				const std::string& contName);
void		printNumComp(int numComp, int maxComp, const std::string& contName);
std::string	toString(int n);
int			maxComparisonsFJ(int n);
std::string	formatWithCommas(long value);

// utils.tpp

template <typename Container>
void		printIsSorted(const Container& c, const std::string& contName);

template <typename Container>
void		printContainer(const Container& c);

template <typename Container>
std::string	returnContainerDebug(const Container& c, const std::string& prefix);

template <typename Container>
void		printBeforeAfter(char** argv, const Container& afterSort);

# include "utils.tpp"

#endif
