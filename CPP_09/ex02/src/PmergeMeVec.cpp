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
	DEBUG_PRINT("== Main chain elements are sorted on highest recursion lvl ==\nnum comps: " << numComp);

	// === Step 2: initialization of pending elements

	// Generate Jacobsthal sequence
	int					maxPending = vec.size() / 2 + 1; // '+1' to accommodate for potential leftover
	std::vector<int>	jacSeq = buildJacobsthalSeq<std::vector<int> >(maxPending); // space between '> >' to avoid confusion with >> operator

	while (recDepth > 0)
	{
		int	blockSize = 1u << (recDepth - 1); // '1<<n' -> '2^n'; u makes 1 unsigned (safer)
		int	numBlocks = vec.size() / blockSize;
		int	numPending = getNumPending(numBlocks);

		DEBUG_PRINT("RecDepth: " << recDepth << ", BlockSize: " << blockSize << ", NumBlocks: " << numBlocks << ", NumPending: " << numPending);
		DEBUG_PRINT(returnContainerDebug(vec, "vector: "));

		// No pending elements on this recursion level (only main chain: 'b1<a1')
		if (numPending == 0)
		{
			--recDepth;
			DEBUG_PRINT("");
			continue;
		}

		// == Step 3: insert pending elements
		int	posPending = rearrangeVec(vec, blockSize);
		DEBUG_PRINT(returnContainerDebug(vec, "Rearranged vector: "));
		DEBUG_PRINT("posPending: " << posPending);

		std::vector<int>	insertionOrder = buildInsertOrder(numPending, jacSeq); // no need for explicit type, as can be deduced from 'jacSeq'
		DEBUG_PRINT(returnContainerDebug(insertionOrder, "Insertion order (pending " + toString(numPending) + "): "));
		DEBUG_PRINT("----");

		insertPendingBlocksVec(vec, blockSize, posPending, insertionOrder, jacSeq, numComp);

		--recDepth;
		DEBUG_PRINT("");
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
	int	blockSize =  1u << (recDepth - 1); // blockSize doubles each recursion: 1 -> 2 -> 4 -> ...
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
			const std::vector<int>& insertionOrder, const std::vector<int>& jacSeq, int& numComp)
{
	for (size_t i = 0; i < insertionOrder.size(); ++i)
	{
		int pendIdx = insertionOrder[i];

		if (pendIdx == 1)  // first pending element (b1) can be inserted right away to the top of the main-chain (b1 < a1)
		{
			DEBUG_PRINT("inserting value: " <<  vec[posPending + blockSize - 1]);
			DEBUG_PRINT("num comps BEFORE insert: " << numComp);
			std::rotate(vec.begin(), vec.begin() + posPending, vec.begin() + posPending + blockSize);
			DEBUG_PRINT("num comps AFTER insert: " << numComp);
			DEBUG_PRINT(returnContainerDebug(vec, "vector after b" + toString(pendIdx) + " is moved to main: "));
			DEBUG_PRINT("Inserting at position of main chain: " << 0);
			posPending += blockSize;
			DEBUG_PRINT("----");
			continue;
		}

		// count previous smaller pending blocks
		size_t numMovedBefore = 0;
		for (size_t j = 0; j < i; ++j)
			if (insertionOrder[j] < pendIdx)
				++numMovedBefore;

		// adjust index: some smaller pending blocks may already have been moved,
		// so subtract them to find the correct current position of pendIdx
		size_t	start = posPending + (pendIdx - 1 - numMovedBefore) * blockSize;
		size_t	end   = start + blockSize;

		// calculate where in the main chain to insert the current pending block to
		int		k = computeK(pendIdx, jacSeq);
		size_t	numMainBlocks = computeUsefulMainEnd(k, posPending, blockSize);
		
		DEBUG_PRINT("looking at value: " << vec[end-1]);
		DEBUG_PRINT("k group val: " << k);
		DEBUG_PRINT("last useful main chain block: " << numMainBlocks);
		DEBUG_PRINT("number of comps BEFORE insert: " << numComp);
		//numMainBlocks = posPending / blockSize;
		size_t	insertPos = binaryInsertBlockVec(vec, vec[end-1], blockSize, numMainBlocks, numComp);
		DEBUG_PRINT("number of comps AFTER insert: " << numComp);

		if (insertPos < start) // do nothing when insertPos == start; insertPos > start is not possible
			std::rotate(vec.begin() + insertPos, vec.begin() + start, vec.begin() + end); // moves main chain elements to right to make space

		DEBUG_PRINT("Inserting at position of main chain: " << insertPos);
		posPending += blockSize;

		DEBUG_PRINT(returnContainerDebug(vec, "vector after b" + toString(pendIdx) + " is moved to main (pendIdx: " + toString(pendIdx) + "): "));
		DEBUG_PRINT("----");
	}
}

#include <cmath>

/**
Finds the insertion index for a pending block in a main chain of blocks.

Uses binary search to locate the position of the pending block based on its
last element, comparing it only with the last element of each main chain block.
Counts comparisons in `numComp`.

 @param vec			Vector containing main chain blocks (assumed sorted by last element of each block).
 @param value		The representative value of the pending block (usually its last element).
 @param blockSize	Number of elements per block.
 @param numBlocks	Number of useful main chain blocks to consider for insertion.
 @param numComp		Counter for the number of comparisons made.
 @return			Element index in `vec` at which the pending block should be inserted.
*/
size_t	PmergeMe::binaryInsertBlockVec(	const std::vector<int>& vec, int value,
										size_t blockSize, size_t numBlocks, int& numComp)
{
	size_t	left = 0; // inclusive
	size_t	right = numBlocks; // exclusive

	while (left < right)
	{
		size_t	mid = left + (right - left) / 2;

		int		midValue = vec[(mid + 1) * blockSize - 1]; // last element of mid-th block

		++numComp;
		DEBUG_PRINT("comparing with val: " << midValue << " (pos: " << (mid + 1) * blockSize - 1 << ")");
		if (value < midValue)
			right = mid;
		else
			left = mid + 1;
	} // when the loop ends, 'left' is the correct insertion index
	return left * blockSize;
}

