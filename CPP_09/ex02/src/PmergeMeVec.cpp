#include <cstdlib>		// atoi()
#include <algorithm>	// swap()
#include <vector>

#include <iostream>

#include "../include/PmergeMe.hpp"
//#include "../include/utils.hpp" // DEBUG -> printContainerDebug(), toString()

static int	sortMainChain(std::vector<int>& vec, int& numComp, int recDepth);

std::vector<int>	PmergeMe::sortVec(int argc, char** argv, int& numComp)
{
	std::vector<int>	vec;

	// Fill vector
	vec.reserve(argc - 1); // helps with performance, avoids repeated reallocation in growing vec
	for (int i = 1; i < argc; ++i)
	{
		vec.push_back(std::atoi(argv[i]));
	}

	// Only one number to sort -> no sorting needed
	if (argc == 2)
	{
		return vec;
	}

	// Step 1 of Ford–Johnson: sort main chain
	int	blockSize = sortMainChain(vec, numComp, 1);

	std::cout << "Block size: " << blockSize << std::endl;

	return vec;
}

////////////
// HELPER //
////////////

/**
Swaps all elements of two sub-chains (blocks) in the vector.

 @param vec			The vector containing the sub-chains
 @param start1		Starting index of the first sub-chain
 @param start2		Starting index of the second sub-chain
 @param blockSize	Number of elements in each sub-chain
*/
static void	swapBlock(std::vector<int>& vec, int start1, int start2, int blockSize)
{
	for (int k = 0; k < blockSize; ++k)
	{
		std::swap(vec[start1 + k], vec[start2 + k]);
	}
}

/**
Recursively orders blocks in the main chain.
At each level, pairs of blocks are compared by their last elements,
and blocks are swapped if needed. Leftover elements are not touched.

 @param vec			The vector to sort (in place)
 @param numComp		Counter for number of comparisons
 @param recDepth	Current recursion depth (starting at 1)

 @return			The block size from the last level where blocks
					were compared and blocks reordered if necessary.

Let's say, there are 13 numbers (n = 13):
 - Lvl 1: 13 -> 6 pairs -> 6 comparisons
 - Lvl 2: 6 -> 3 pairs -> 3 comparisons
 - Lvl 3: 3 -> 1 pair -> 1 comparison
-> General formula: At each level i, ⌊n_i / 2⌋ (floor down) comparisons
-> Using formula: ⌊13/2⌋ + ⌊6/2⌋ + ⌊3/2⌋ = 6 + 3 + 1 = 10 comparisons
*/
static int	sortMainChain(std::vector<int>& vec, int& numComp, int recDepth)
{
	int	blockSize = (1 << recDepth) / 2; // number of elements in one of the two blocks within the pair -> '1 << d' is '2^d'
	int	numBlocks = vec.size() / blockSize; // number of blocks to process

	if (numBlocks <= 1) // base case, no more blocks to compare with one another
	{
		return blockSize / 2; // return block size of previous level (su)
	}

	// Iterate over all adjacent block pairs
	for (size_t i = 0; i + 2 * blockSize - 1 < vec.size(); i += 2 * blockSize)
	{
		++numComp;
		// Compare the last element of the two blocks, swap blocks if needed
		if (vec[i + blockSize - 1] > vec[i + 2 * blockSize - 1])
			swapBlock(vec, i, i + blockSize, blockSize);
	}

	return sortMainChain(vec, numComp, recDepth + 1);
}
