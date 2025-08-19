#include <cstdlib>	// atoi()
#include <vector>

#include "../include/PmergeMe.hpp"

std::vector<int>	PmergeMe::sortVec(int argc, char** argv, int& numComp)
{
	std::vector<int>	vec;

	// Fill vector
	vec.reserve(argc - 1); // helps with performance, avoids repeated reallocation in growing vec
	for (int i = 1; i < argc; ++i)
	{
		vec.push_back(std::atoi(argv[i]));
	}

	++numComp;

	return vec;
}
