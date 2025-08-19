#include <iostream>
#include <vector>

#include "../include/PmergeMe.hpp"
#include "../include/define.hpp"	// for color codes
#include "../include/utils.hpp"		// for getCurrentTimeStruct(), getElapsedTime(), isSorted()

int	main(int argc, char** argv)
{
	if (argc < 2) // No integers provided
	{
		std::cerr	<< YELLOW << "Usage: " << argv[0] << " <int1> <int2> ..." << RESET
					<< " (only positive integers allowed)\n";
		return 1;
	}

	timeval				start, end;	// structs to hold time info
	std::vector<int>	sortedVec;

	try
	{
		PmergeMe::checkArgs(argc, argv);
		printBeforeAfter(argc, argv);

		// == Sorting using 'vector' ===
		start = getCurrentTimeStruct();
		sortedVec = PmergeMe::sortVec(argc, argv);
		end = getCurrentTimeStruct();
		printElapsedTime(start, end, argc - 1, "std::vector<int>");

		// == Sorting using 'XXXX' ==
		printElapsedTime(start, end, argc - 1, "std::XXXX");

		// Is result really sorted?
		isSorted(sortedVec, "std::vector<int>");

	}
	catch (const std::exception& e)
	{
		std::cerr << RED << BOLD << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}
