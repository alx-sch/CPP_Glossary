#include <iostream>
#include <vector>

#include "../include/PmergeMe.hpp"
#include "../include/define.hpp"	// for color codes
#include "../include/utils.hpp"		// for getCurrentTimeStruct(), getElapsedTime(), printIsSorted(), printNumComp()

int	main(int argc, char** argv)
{
	if (argc < 2) // No integers provided
	{
		std::cerr	<< YELLOW << "Usage: " << argv[0] << " <int1> <int2> ..." << RESET
					<< " (only positive integers allowed)\n";
		return 1;
	}

	timeval				start, end;	// structs to hold time info
	int					numCompVec = 0, numCompLst = 0;	// keeps track of comparisons made
	std::vector<int>	sortedVec;
	std::list<int>		sortedLst;

	try
	{
		PmergeMe::checkArgs(argc, argv);
		printBeforeAfter(argc, argv);

		// === Sorting using 'vector' ===
		start = getCurrentTimeStruct();
		sortedVec = PmergeMe::sortVec(argc, argv, numCompVec);
		end = getCurrentTimeStruct();
		printElapsedTime(start, end, argc - 1, "std::vector<int>");

		// === Sorting using 'list' ===
		start = getCurrentTimeStruct();
		sortedLst = PmergeMe::sortLst(argc, argv, numCompLst);
		end = getCurrentTimeStruct();
		printElapsedTime(start, end, argc - 1, "std::list<int>");

		// === Printing additional info ===
		std::cout << std::endl;

		// Is result really sorted?
		printIsSorted(sortedVec, "std::vector<int>");
		printIsSorted(sortedLst, "std::list<int>");

		// How many comparisons were made?
		printNumComp(numCompVec, "std::vector<int>");
		printNumComp(numCompLst, "std::list<int>");
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << BOLD << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}
