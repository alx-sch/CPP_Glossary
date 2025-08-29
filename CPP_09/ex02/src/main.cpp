#include "../include/PmergeMe.hpp"
#include "../include/utils.hpp"
#include "../include/define.hpp"

#include <iostream>
#include <vector>
#include <list>

/**
Handles sorting of integer arguments using both VECTOR and LIST containers.
 - Checks passed arguments (integers [1, INT_MAX])
 - Sort integers implementing the merge-insertion sort algorithm (Ford-Johnson),
   using both `std::vector<int>` and `std::list<int>`
 - Print the sorted results and performance metrics (process time, number of comparisons made)

This implementation minimizes computation time by using in-place operations within the containers.
*/
int	main(int argc, char** argv)
{
	if (argc < 2 || argc > MAX_ARGS + 1) // No arguments provided
	{
		std::cerr	<< YELLOW << "Usage: " << argv[0] << " <int1> <int2> ... <int"
					<< MAX_ARGS << ">" << RESET << " (only positive integers allowed);\n";
		return 1;
	}

	timeval				start, end;	// structs to hold time info
	int					numCompVec = 0, numCompLst = 0;	// keeps track of comparisons made
	std::vector<int>	sortedVec;
	std::list<int>		sortedLst;

	try
	{
		PmergeMe::checkArgs(argc, argv);

		// === Sorting using 'vector' ===
		start = getCurrentTimeStruct();
		sortedVec = PmergeMe::sortVec(argc, argv, numCompVec);
		end = getCurrentTimeStruct();

		printBeforeAfter(argv, sortedVec);
		printElapsedTime(start, end, argc - 1, "std::vector<int>");

		// === Sorting using 'list' ===
		start = getCurrentTimeStruct();
		sortedLst = PmergeMe::sortList(argc, argv, numCompLst);
		end = getCurrentTimeStruct();

		printElapsedTime(start, end, argc - 1, "std::list<int>");

		// === Printing additional info ===
		std::cout << std::endl;

		// Is result really sorted?
		printIsSorted(sortedVec, "std::vector<int>");
		printIsSorted(sortedLst, "std::list<int>");

		// How many comparisons were made?
		int	maxComps = maxComparisonsFJ(argc - 1);
		printNumComp(numCompVec, maxComps, "std::vector<int>");
		printNumComp(numCompLst, maxComps, "std::list<int>");
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << BOLD << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}
