// Implementing the Ford-Johnson algorithm in place was done following these articles:
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
// https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42

#include <cstdlib>		// atoi()
#include <algorithm>	// swap_ranges(), std::rotate()
#include <vector>
#include <iostream>

#include "../include/PmergeMe.hpp"
#include "../include/utils.hpp" // DEBUG -> printContainerDebug(), toString()

std::vector<int>	PmergeMe::sortVec(int argc, char** argv, int& numComp)
{
	std::vector<int>	vec;
	vec.reserve(argc - 1); // helps with performance, avoids repeated reallocation in growing vec

	for (int i = 1; i < argc; ++i) // fill vector
		vec.push_back(std::atoi(argv[i]));

	if (argc == 2) // no sorting needed if there is only one number
		return vec;

	// === Step 1: division into pairs & sorting
	int	recDepth = sortPairsRecursivelyVec(vec, numComp, 1);

	// === Step 2: initialization of pending elements

	// Generate Jacobsthal sequence
	int					maxPending = vec.size() / 2 + 1; // '+1' to accommodate for potential leftover
	std::vector<int>	jacSeq = buildJacobsthalSeq<std::vector<int> >(maxPending); // space between '> >' to avoid confusion with >> operator

	while (recDepth > 0)
	{
		int	blockSize = 1 << (recDepth - 1); // '1 << n' -> '2^n'
		int	numBlocks = vec.size() / blockSize;
		int	numPending = getNumPending(numBlocks);

		std::cout << "RecDepth: " << recDepth << ", BlockSize: " << blockSize << ", NumBlocks: " << numBlocks << ", NumPending: " << numPending << std::endl;
		printContainerDebug(vec, "vector: ");

		// No pending elements on this recursion level (only main chain: 'b1 < a1')
		if (numPending == 0)
		{
			--recDepth;
			continue;
		}

		// == Step 3: insert pending elements
		int	posPending = rearrangeVec(vec, blockSize);
		printContainerDebug(vec, "Rearranged vector: ");
		std::cout << "posPending: " << posPending << std::endl;

		std::vector<int>	insertionOrder = buildInsertOrder(numPending, jacSeq); // no need for explicit type, as can be deduced from 'jacSeq'
		printContainerDebug(insertionOrder, "Insertion order (pending " + toString(numPending) + "): ");

		insertPendingBlocksVec(vec, blockSize, posPending, insertionOrder);

		--recDepth;
	}

	return vec;
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
int	PmergeMe::sortPairsRecursivelyVec(std::vector<int>& vec, int& numComp, int recDepth)
{
	int	blockSize =  1 << (recDepth - 1); // blockSize doubles each recursion: 1 -> 2 -> 4 -> ...
	int	numBlocks = vec.size() / blockSize; // number of blocks to process

	if (numBlocks <= 1) // base case, no more blocks to compare with one another
		return recDepth - 1; // returns recursion level in which the last comparison took place

	// Iterate over all adjacent block pairs
	for (size_t i = 0; i + 2*blockSize - 1 < vec.size(); i += 2*blockSize)
	{
		++numComp;
		// Compare the last element of the two blocks, swap blocks if needed
		if (vec[i + blockSize - 1] > vec[i + 2*blockSize - 1])
		{
			swap_ranges(	vec.begin() + i,	// start first block
							vec.begin() + i + blockSize, // one past the end of first block
							vec.begin() + i + blockSize); // start second block
		}
	}

	return PmergeMe::sortPairsRecursivelyVec(vec, numComp, recDepth + 1);
}

/**
Rearranges a vector so that main chain elements are in front
and pending elements (+ leftovers) are at the back.

 @param vec			The interleaved input vector `[b1 a1 b2 a2 b3 a3 ...]`,
 					possibly with leftover elements. This vector is modified
					in place to contain `[mainChain | pending | leftovers]`
 @param blockSize	Number of elements per block.
 @return			The index at which the pending elements start in `vec`.
					All elements from this index onward belong to the pending chain.
*/
int	PmergeMe::rearrangeVec(std::vector<int>& vec, int blockSize)
{
	std::vector<int>	mainChain, pending;
	size_t				vecSize = vec.size();
	int					posPending; // inde

	mainChain.reserve(vecSize); // overestimating, but oh well
	pending.reserve(vecSize);

	// Separate main-chain and pending
	for (size_t i = 0; i < vecSize; ++i)
	{
		if (isMainChain(i, blockSize, vecSize))
			mainChain.push_back(vec[i]);
		else
			pending.push_back(vec[i]);
	}

	posPending = mainChain.size();

	// merge main-chain + pending (+ leftovers)
	mainChain.insert(mainChain.end(), pending.begin(), pending.end());

	// Reassign vec
	vec = mainChain;

	return posPending;
}


void	PmergeMe::insertPendingBlocksVec(std::vector<int>& vec, int blockSize, int& posPending,
			const std::vector<int>& insertionOrder)
{
	for (size_t i = 0; i < insertionOrder.size(); ++i)
	{
		int pendIdx = insertionOrder[i];

		if (pendIdx == 1)  // first pending element (b1) can be inserted right away to the top of the main-chain (b1 < a1)
		{
			std::rotate(vec.begin(), vec.begin() + posPending, vec.begin() + posPending + blockSize);
			printContainerDebug(vec, "vector after b1 is moved to main (pendIdx: " + toString(pendIdx) + "): ");
			posPending += blockSize;
			continue;
		}

		// count previous smaller pending blocks
		size_t numMovedBefore = 0;
		for (size_t j = 0; j < i; ++j)
			if (insertionOrder[j] < pendIdx)
				++numMovedBefore;

		size_t	start = posPending + (pendIdx - 1 - numMovedBefore) * blockSize;
		size_t	end   = start + blockSize;

		std::rotate(vec.begin(), vec.begin() + start, vec.begin() + end);
		posPending += blockSize;

		printContainerDebug(vec, "vector after XX is moved to main (pendIdx: " + toString(pendIdx) + "): ");
	}
}

/**
Inserts a value into the sorted subrange [0, end) of a vector.

Uses binary search to find the correct insertion index and shifts
elements as needed. Each comparison is counted in numComp.

 @param vec		Vector to insert into.
 @param value	Value to insert.
 @param end		Exclusive upper bound of the useful main chain.
 @param numComp	Counter for the number of comparisons made.
*/
void PmergeMe::binaryInsertVec(std::vector<int>& vec, int value, size_t end, int& numComp)
{
	size_t	left = 0; // inclusive
	size_t	right = end; // exclusive

	while (left < right)
	{
		size_t	mid = left + (right - left) / 2;
		
		++numComp;
		if (value < vec[mid]) // narrow search to [left, mid).
			right = mid;
		else
			left = mid + 1; // narrow search to [mid + 1, right)
	} // when the loop ends, 'left' is the correct insertion index

	vec.insert(vec.begin() + left, value);
}
