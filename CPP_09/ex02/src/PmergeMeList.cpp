// Implementing the Ford-Johnson algorithm in place was done following these articles:
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
// https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42

#include "../include/PmergeMe.hpp"

#include <cstdlib>	// atoi()
#include <cstddef>	// size_t
#include <list>
#include <iterator>	// std::distance(), std::advance()

static std::list<int>	buildListFromArgs(int argc, char** argv);

/**
Sorts a list of integers using the Ford–Johnson (Merge-Insertion) algorithm.

Steps:
 1.	List Initialization: Converts the command-line arguments (argv) into a list of integers.
	If only one number is provided, it returns immediately since it is already sorted.

 2.	Pair Division & Recursive Sorting: Divides the list into pairs and sorts them recursively.
	This step produces a "main chain" and determines the recursion depth needed for pending insertions.

 3.	Pending Elements Initialization: Generates the Jacobsthal sequence up to the maximum number
	of pending elements. This sequence determines the optimal order for inserting elements
	not yet in the main chain.

 4.	Insertion of Pending Elements: Iterates from the deepest recursion level down to 1.
	- Computes block size and the number of blocks for the current recursion depth.
	- Determines the number of pending elements at this level.
	- Inserts pending elements according to the Jacobsthal sequence if any exist.

 5.	Returns the fully sorted list.

 @param argc	Number of command-line arguments.
 @param argv	Command-line argument strings representing integers to sort.
 @param numComp	Reference to an integer counting the number of comparisons made.
 @return		The sorted list of integers.
*/
std::list<int>	PmergeMe::sortList(int argc, char** argv, int& numComp)
{
	std::list<int>	lst = buildListFromArgs(argc, argv);
	if (lst.size() <= 1) // Already sorted
		return lst;

	int				recDepth = sortPairsRecursivelyList(lst, numComp, 1);
	int				maxPending = lst.size() / 2 + 1; // '+1' to accommodate for potential leftover
	std::list<int>	jacSeq = buildJacobsthalSeq<std::list<int> >(maxPending); // space between '> >' to avoid confusion with >> operator

	while (recDepth > 0)
	{
		int	blockSize = 1 << (recDepth - 1); // '1<<n' -> '2^n'; u makes 1 unsigned (safer)
		int	numBlocks = lst.size() / blockSize;
		int	numPending = getNumPending(numBlocks);

		if (numPending > 1) // no need to insert anything if there's only 1 pending element, already sorted! -> 'b1 < a1'
			insertPendingBlocksList(lst, blockSize, numPending, jacSeq, numComp);

		--recDepth;
	}

	return lst;
}

/**
Recursively sorts the main chain in the Ford–Johnson algorithm by comparing
pairs, then pairs of pairs, and so on.
At each level, pairs of blocks are compared by their last elements,
and blocks are swapped if needed. Leftover elements are not touched.

Let's say, there are 13 numbers (n = 13):
 - Lvl 1: 13 -> 6 pairs -> 6 comparisons
 - Lvl 2: 6 -> 3 pairs -> 3 comparisons
 - Lvl 3: 3 -> 1 pair -> 1 comparison
-> General formula: At each level i, ⌊n_i / 2⌋ (floor down) comparisons
-> Using formula: ⌊13/2⌋ + ⌊6/2⌋ + ⌊3/2⌋ = 6 + 3 + 1 = 10 comparisons

 @param lst			The list to sort (in place)
 @param numComp		Counter for number of comparisons
 @param recDepth	Current recursion depth (starting at 1)
 @return			The recursion depth in which the last comparison took place.
*/
int	PmergeMe::sortPairsRecursivelyList(std::list<int>& lst, int& numComp, int recDepth)
{
	int	blockSize = 1 << (recDepth - 1);	// blockSize doubles each recursion: 1 -> 2 -> 4 -> ...
	int	numBlocks = lst.size() / blockSize;	// number of blocks to process

	if (numBlocks <= 1)			// base case, no more blocks to compare with one another
		return recDepth - 1;	// returns recursion level in which the last comparison took place

	// Iterate over all adjacent block pairs
	std::list<int>::iterator	it = lst.begin();
	size_t						i = 0;

	while (i + 2*blockSize - 1 < lst.size())
	{
		// First block
		std::list<int>::iterator	firstBlockStart = it;
		std::list<int>::iterator	firstBlockEnd = it;
		std::advance(firstBlockEnd, blockSize); // one past last of first block

		// Second block
		std::list<int>::iterator	secondBlockEnd = firstBlockEnd;
		std::advance(secondBlockEnd, blockSize); // one past last of second block

		// temps
		std::list<int>::iterator last1 = firstBlockEnd;
		--last1;	// now points to last element of first block

		std::list<int>::iterator last2 = secondBlockEnd;
		--last2;	// last element of second block

		++numComp;
		if (*last1 > *last2)
			lst.splice(secondBlockEnd, lst, firstBlockStart, firstBlockEnd);

		it = secondBlockEnd;
		i += 2*blockSize;
	}

	return sortPairsRecursivelyList(lst, numComp, recDepth + 1);
}

/**
Rearranges a list so that main chain elements are in front
and pending elements (+ leftovers) are at the back.

 @param lst			The interleaved input list `[b1 a1 b2 a2 b3 a3 ...]`,
 					possibly with leftover elements. This list is modified
					in place to contain `[mainChain | pending | (leftovers)]`
 @param blockSize	Number of elements per block.
 @return			The index at which the pending elements start in `lst`.
					All elements from this index onward belong to the pending chain.
*/
int	PmergeMe::rearrangeList(std::list<int>& lst, int blockSize)
{
	std::list<int>::iterator	it = lst.begin();
	int							posPending = 0;
	size_t						idx = 0;

	// Move main-chain elements to the front of the list
	while (idx + blockSize < lst.size())
	{
		std::list<int>::iterator	blockEnd = it;
		std::advance(blockEnd, blockSize);

		idx = std::distance(lst.begin(), it);

		if (isMainChain(idx, blockSize, lst.size()))
		{
			std::list<int>::iterator	mainEnd = lst.begin();
			for (int i = 0; i < posPending; ++i)
				++mainEnd;
			lst.splice(mainEnd, lst, it, blockEnd); // move main-chain block to the front
			posPending += blockSize;
		}

		it = blockEnd;
	}

	return posPending;
}

/**
Inserts pending blocks into the main chain within a list.

The function uses the Jacobsthal sequence and Ford–Johnson logic to
determine the order and number of comparisons needed for insertion.
Each pending block is inserted in binary-search order based on the
last element of each block. The main chain grows as blocks are inserted.

 @param lst			The list containing main chain blocks and pending blocks.
 @param blockSize	Number of elements per block.
 @param numPending	Number of pending blocks to insert.
 @param jacSeq		Jacobsthal sequence used to compute insertion group `k`.
 @param numComp		Reference counter for the number of comparisons performed.
*/
void	PmergeMe::insertPendingBlocksList(std::list<int>& lst, int blockSize, int numPending,
			const std::list<int>& jacSeq, int& numComp)
{
	int				posPending = rearrangeList(lst, blockSize);
	std::list<int>	insertionOrder = buildInsertOrder(numPending, jacSeq);

	for (std::list<int>::const_iterator itOrder = insertionOrder.begin(); itOrder != insertionOrder.end(); ++itOrder)
	{
		int		pendIdx = *itOrder; // get current pending block index
		size_t	numMovedBefore = PmergeMe::countSmallerPending(insertionOrder, itOrder, pendIdx);

		// locate the start of the pending block in the main list
		std::list<int>::iterator	startIt = lst.begin();
		std::advance(startIt, posPending + (pendIdx - 1 - numMovedBefore) * blockSize);

		// locate the end of the pending block
		std::list<int>::iterator	blockEndIt = startIt;
		std::advance(blockEndIt, blockSize);

		int		k = computeK(pendIdx, jacSeq);
		size_t	usefulMainElements = computeUsefulMainEnd(k, posPending, blockSize);

		// iterator to last element of pending block
		std::list<int>::iterator	lastPendIt = blockEndIt;
		--lastPendIt;

		// find insertion point in main chain
		std::list<int>::iterator	insertIt =	(pendIdx != 1)
												? binaryInsertBlockList(lst, *lastPendIt, blockSize, usefulMainElements, numComp)
												: lst.begin(); // first pending element (b1) can be inserted right away to top of main chain

		if (insertIt != startIt) // move the block if needed
			lst.splice(insertIt, lst, startIt, blockEndIt); // move the whole pending block

		posPending += blockSize;
	}
}

/**
Finds the insertion position for a pending block in a main chain of blocks.

Uses binary search to locate the position of the pending block based on its
last element, comparing it only with the last element of each main chain block.
Counts comparisons in `numComp`.

 @param lst			List containing main chain blocks (assumed sorted by last element of each block).
 @param value		The representative value of the pending block (last element).
 @param blockSize	Number of elements per block.
 @param numBlocks	Number of useful main chain blocks to consider for insertion.
 @param numComp		Counter for the number of comparisons made.
 @return			Iterator pointing to the position in `lst` where the pending block should be inserted.
*/
std::list<int>::iterator	PmergeMe::binaryInsertBlockList(std::list<int>& lst, int value,
								int blockSize, size_t numBlocks, int& numComp)
{
	// Use block indices instead of block number
	size_t left = 0;			// inclusive
	size_t right = numBlocks;	// exclusive

	while (left < right)
	{
		size_t mid = (left + right) / 2;

		// move an iterator to the last element of the mid-block
		std::list<int>::iterator	midIt = lst.begin();
		std::advance(midIt, (blockSize - 1) + mid*blockSize);

		++numComp;
		if (value < *midIt)
			right = mid;
		else
			left = mid + 1;
	}

	// Now left * blockSize is the correct insertion position
	std::list<int>::iterator	insertPos = lst.begin();
	std::advance(insertPos, left * blockSize);

	return insertPos;
}

////////////
// HELPER //
////////////

// Builds a list from command line arguments
static std::list<int>	buildListFromArgs(int argc, char** argv)
{
	std::list<int>	lst;
	
	for (int i = 1; i < argc; ++i)
		lst.push_back(std::atoi(argv[i]));

	return lst;
}
