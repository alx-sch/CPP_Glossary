#include <cstdlib>		// atoi()
#include <algorithm>	// swap()
#include <vector>

#include "../include/PmergeMe.hpp"
#include "../include/utils.hpp" // DEBUG -> printContainerDebug()

static void	sortMainChain(std::vector<int>& vec, int& numComp, int recDepth);

std::vector<int>	PmergeMe::sortVec(int argc, char** argv, int& numComp)
{
	std::vector<int>	vec;

	// Fill vector
	vec.reserve(argc - 1); // helps with performance, avoids repeated reallocation in growing vec
	for (int i = 1; i < argc; ++i)
	{
		vec.push_back(std::atoi(argv[i]));
	}

	// Step 1 of Ford–Johnson: sort main chain
	sortMainChain(vec, numComp, 1); // Starting recursion depth: 1

	return vec;
}

////////////
// HELPER //
////////////

/**
Swaps all elements of two sub-chains (blocks) in the vector
 @param vec			The vector containing the sub-chains
 @param start1		Starting index of the first sub-chain
 @param start2		Starting index of the second sub-chain
 @param blockSize	Number of elements in each sub-chain
*/
static void	swapBlock(std::vector<int>& vec, size_t start1, size_t start2, size_t blockSize)
{
	for (size_t k = 0; k < blockSize; ++k)
		std::swap(vec[start1 + k], vec[start2 + k]);
}

/**
Sorts the main chain using Ford–Johnson method.
Only the main chain is processed; leftovers are left untouched.
 @param vec			The vector to sort
 @param numComp		Counter for number of comparisons
 @param recDepth	Current recursion depth (starting at 1)

On each 'level' of recursion, the two blocks of a pair are compared.
Let's say, there are 13 numbers (n = 13):
 - Lvl 1: 13 -> 6 pairs -> 6 comparisons
 - Lvl 2: 6 -> 3 pairs -> 3 comparisons
 - Lvl 3: 3 -> 1 pair -> 1 comparison
*/
static void	sortMainChain(std::vector<int>& vec, int& numComp, int recDepth)
{
	int	blockSize = (1 << recDepth) / 2; // number of elements in one of the two blocks within the pair
	int	numBlocks = vec.size() / blockSize; // number of block pairs to process

	if (numBlocks <= 1)
		return; // base case, no more blocks to compare with one another

	// Iterate over all adjacent block pairs
	for (size_t i = 0; i + 2*blockSize - 1 < vec.size(); i += 2*blockSize)
	{
		++numComp;
		// Compare the last element of the two blocks, swap blocks if needed
		if (vec[i + blockSize - 1] > vec[i + 2*blockSize - 1])
			swapBlock(vec, i, i + blockSize, blockSize);
	}

	sortMainChain(vec, numComp, ++recDepth);
}
