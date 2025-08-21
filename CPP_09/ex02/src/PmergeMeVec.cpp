// Implementing the Ford-Johnson algorithm in place was done following this article:
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91

#include <cstdlib>		// atoi()
#include <algorithm>	// swap()
#include <vector>

#include <iostream>

#include "../include/PmergeMe.hpp"
//#include "../include/utils.hpp" // DEBUG -> printContainerDebug(), toString()

static int	sortPairsRecursively(std::vector<int>& vec, int& numComp, int recDepth);

std::vector<int>	PmergeMe::sortVec(int argc, char** argv, int& numComp)
{
	std::vector<int>	vec;

	// Fill vector
	vec.reserve(argc - 1); // helps with performance, avoids repeated reallocation in growing vec
	for (int i = 1; i < argc; ++i)
	{
		vec.push_back(std::atoi(argv[i]));
	}

	// Only one number -> no sorting needed
	if (argc == 2)
	{
		return vec;
	}

	// Step 1: the division into the pairs & sorting
	int	recDepth = sortPairsRecursively(vec, numComp, 1);


	// #######

	int		maxPending = (vec.size() / 2) + 1; // +1 accommodates for potential leftover
	int*	jacSeq = generateJacobsthalSeq(maxPending);

	// while (recDepth > 1)
	// {
		// Step 2: initialization of pending elements
		int	blockSize = (1 << (recDepth - 1));
		int	numBlocks = vec.size() / blockSize;

		// if (numBlocks <= 2) // no pendings elements, only 'b1 < a1'
		// {
		// 	--recDepth;
		// 	continue;
		// }

		--recDepth;
		blockSize = (1 << (recDepth - 1));
		numBlocks = vec.size() / blockSize;
		// Step 3: insert pending elements into main chain
		int	numPending = (numBlocks / 2) - 1; // exclude b1
		if (numBlocks % 2 != 0) // leftover b without a
		{
			++numPending;
		}

		std::cout << "numBlocks: " << numBlocks << std::endl;
		std::cout << "numPending: " << numPending << std::endl;

		// The main chain initially contains: b1 + all a's
		//int	mainChainSize = numBlocks - numPending;

		// Check value of pending elements (last number in pending block)
		// '3 * blockSize - 1': skip b1 < a1; access last number of b2
		// 'i * (2 * blockSize)': access last number of b_i
		for (int i = 0; i < numPending; ++i)
		{
			int	pendingValue = vec[(3 * blockSize) - 1 + i * (2 * blockSize)]; // last element of pending block
			std::cout << "pendingValue: " << pendingValue << std::endl;
		}

		// Insert pending elements in order given by Jacobsthal indices
		// for (int i = 0; i < numPending; ++i)
		// {
		// 	int	pendingIdx = jacSeq[i];
		// 	int	pendingPos = blockSize * (pendingIdx + 1) - 1; // position of b in vec

		// }

//	}
	

	// #######

	for (int i = 0; jacSeq[i] != -1; ++i)
	{
		std::cout << "jacSeq[" << i << "]: " << jacSeq[i] << std::endl;
	}

	std::cout << "recDepth: " << recDepth << std::endl;

	delete[] jacSeq;
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
Recursively sorts the main chain in the Ford–Johnson algorithm by comparing
pairs, then pairs of pairs, and so on.
At each level, pairs of blocks are compared by their last elements,
and blocks are swapped if needed. Leftover elements are not touched.

 @param vec			The vector to sort (in place)
 @param numComp		Counter for number of comparisons
 @param recDepth	Current recursion depth (starting at 1)

 @return			The recursion depth in which the last comparison took place.

Let's say, there are 13 numbers (n = 13):
 - Lvl 1: 13 -> 6 pairs -> 6 comparisons
 - Lvl 2: 6 -> 3 pairs -> 3 comparisons
 - Lvl 3: 3 -> 1 pair -> 1 comparison
-> General formula: At each level i, ⌊n_i / 2⌋ (floor down) comparisons
-> Using formula: ⌊13/2⌋ + ⌊6/2⌋ + ⌊3/2⌋ = 6 + 3 + 1 = 10 comparisons
*/
static int	sortPairsRecursively(std::vector<int>& vec, int& numComp, int recDepth)
{
	int	blockSize = (1 << recDepth) / 2; // number of elements in one of the two blocks within the pair -> '1 << d' is '2^d'
	int	numBlocks = vec.size() / blockSize; // number of blocks to process

	if (numBlocks <= 1) // base case, no more blocks to compare with one another
	{
		return recDepth - 1; // returns recursion level in which the last comparison took place
	}

	// Iterate over all adjacent block pairs
	for (size_t i = 0; i + 2 * blockSize - 1 < vec.size(); i += 2 * blockSize)
	{
		++numComp;
		// Compare the last element of the two blocks, swap blocks if needed
		if (vec[i + blockSize - 1] > vec[i + 2 * blockSize - 1])
			swapBlock(vec, i, i + blockSize, blockSize);
	}

	return sortPairsRecursively(vec, numComp, recDepth + 1);
}
