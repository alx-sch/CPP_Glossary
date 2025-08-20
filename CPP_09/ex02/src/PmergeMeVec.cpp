#include <cstdlib>		// atoi()
#include <algorithm>	// swap()
#include <vector>

#include "../include/PmergeMe.hpp"

static void	fordJohnson(std::vector<int>& vec, int& numComp);
static void	fordJohnsonSort(std::vector<int>& vec, size_t start, size_t end, int& numComp);

std::vector<int>	PmergeMe::sortVec(int argc, char** argv, int& numComp)
{
	std::vector<int>	vec;

	// Fill vector
	vec.reserve(argc - 1); // helps with performance, avoids repeated reallocation in growing vec
	for (int i = 1; i < argc; ++i)
	{
		vec.push_back(std::atoi(argv[i]));
	}

	fordJohnson(vec, numComp);

	return vec;
}

static void	fordJohnson(std::vector<int>& vec, int& numComp)
{
	fordJohnsonSort(vec, 0, vec.size(), numComp);
}

////////////
// HELPER //
////////////

// Pair elements in [start,end), smaller first in each pair
// Returns: number of pairs (pending size), leftover = last element if odd
static void	pairAndSplit(std::vector<int>& vec, size_t start, size_t end,
	size_t& numPairs, int& leftover, int& numComp)
{
	size_t		n = end - start;
	leftover = -1;

	// Pair elements and sort within pairs
	for (size_t i = 0; i + 1 < n; i += 2)
	{
		++numComp;
		if (vec[i] > vec[i+1])
			std::swap(vec[i], vec[i+1]); // smaller first, larger second
	}

	numPairs = n / 2; // number of pairs (pending size)
	if (n % 2 != 0)
	{
		leftover = vec[n-1]; // last element is leftover (unpaired)
	}
}

static void	fordJohnsonSort(std::vector<int>& vec, size_t start, size_t end, int& numComp)
{
	size_t	n = end - start;
	if (n <= 1) // Base case
	{
		return;
	}

	size_t	numPairs; // size_t as added to start (which is size_t)
	int		leftover;

	// [42 17 99 5 8 23 7]
	pairAndSplit(vec, start, end, numPairs, leftover, numComp);
	// [17,42  5,99  8,23  7]; numPairs = 3, leftover = 7

	// Step 1: recursively sort the main chain (larger element of each pair)
	size_t	mainEnd = end;
	if (leftover != -1)
	{
		mainEnd = end - 1; // Exclude leftover from main chain
	}
	(void)mainEnd;
	// fordJohnsonSort(vec, start + numPairs, mainEnd, numComp);
}
