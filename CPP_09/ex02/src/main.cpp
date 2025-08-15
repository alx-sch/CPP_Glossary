#include <iostream>
#include "../include/PmergeMe.hpp"

#define YELLOW	"\033[33m"
#define RED		"\033[31m"
#define BOLD	"\033[1m"
#define RESET	"\033[0m"

int	main(int argc, char** argv)
{
	if (argc < 2) // No integers provided
	{
		std::cerr	<< YELLOW << "Usage: " << argv[0] << " <int1> <int2> ..." << RESET
					<< " (only positive integers allowed)\n";
		return 1;
	}

	try
	{
		PmergeMe::checkArgs(argc, argv);
		PmergeMe::sort(argc, argv);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << BOLD << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}
