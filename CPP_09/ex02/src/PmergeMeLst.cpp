#include <cstdlib>	// atoi()
#include <list>

#include "../include/PmergeMe.hpp"

std::list<int>	PmergeMe::sortLst(int argc, char** argv, int& numComp)
{
	std::list<int>	lst;

	// Fill list
	for (int i = 1; i < argc; ++i)
	{
		lst.push_back(std::atoi(argv[i]));
	}

	--numComp;

	return lst;
}
