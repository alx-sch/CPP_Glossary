// Implementing the Ford-Johnson algorithm in place was done following these articles:
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
// https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42

#include <cstdlib>		// atoi()
#include <list>
#include <vector>
#include <algorithm>	// std::rotate
#include <iterator>		// distance()

#include "../include/PmergeMe.hpp"

static std::list<int> buildListFromArgs(int argc, char** argv);

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
std::list<int> PmergeMe::sortList(int argc, char** argv, int& numComp)
{
	std::list<int> lst = buildListFromArgs(argc, argv);
	if (lst.size() <= 1) // Already sorted
		return lst;

	//int				recDepth = sortPairsRecursivelyList(lst, numComp, 1);
	int recDepth = 0;
	(void)numComp;
	//int				maxPending = lst.size() / 2 + 1; // '+1' to accommodate for potential leftover
	//std::list<int>	jacSeq = buildJacobsthalSeq<std::list<int> >(maxPending); // space between '> >' to avoid confusion with >> operator

	while (recDepth > 0)
	{
		int	blockSize = 1 << (recDepth - 1); // '1<<n' -> '2^n'; u makes 1 unsigned (safer)
		int	numBlocks = lst.size() / blockSize;
		int	numPending = getNumPending(numBlocks);

		if (numPending > 1) // no need to insert anything if there's only 1 pending element, already sorted! -> 'b1 < a1'
			//insertPendingBlocksList(lst, blockSize, numPending, jacSeq, numComp);

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
	int							i = 0;
	while (i + 2*blockSize - 1 < (int)lst.size())
	{
		// First block
		std::list<int>::iterator	firstBlockStart = it;
		std::list<int>::iterator	firstBlockEnd = it;
		std::advance(firstBlockEnd, blockSize); // one past last of first block

		// Second block
		std::list<int>::iterator	secondBlockStart = firstBlockEnd;
		std::list<int>::iterator	secondBlockEnd = secondBlockStart;
		std::advance(secondBlockEnd, blockSize); // one past last of second block

		// Compare the last element of the two blocks
		std::list<int>::iterator	lastOfFirst = firstBlockEnd;
		--lastOfFirst;

		std::list<int>::iterator	lastOfSecond = secondBlockEnd;
		--lastOfSecond;

		++numComp;
		if (*lastOfFirst > *lastOfSecond)
		{
			// Move first block after second block
			lst.splice(secondBlockEnd, lst, firstBlockStart, firstBlockEnd);
			// Now 'it' points to start of second block, so we need to reset for next iteration
			it = secondBlockEnd;
		}
		else
			it = secondBlockEnd; // No swap, move to next pair

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
int PmergeMe::rearrangeList(std::list<int>& lst, int blockSize)
{
	std::list<int>::iterator	it = lst.begin();
	int							idx = 0;
	int							posPending = 0;

	// Move non-main-chain elements to the end of the list
	while (it != lst.end())
	{
		std::list<int>::iterator	next = it;
		++next; // store next because we may splice

		if (!isMainChain(idx, blockSize, lst.size()))
			lst.splice(lst.end(), lst, it); // move 'it' to the end
		else
			++posPending; // main chain element, increment count

		it = next;
		++idx;
	}

	return posPending;
}

/**
Inserts pending blocks into the main chain within a vector.

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
	int							posPending = rearrangeList(lst, blockSize);
	std::list<int>				insertionOrder = buildInsertOrder(numPending, jacSeq);

	for (std::list<int>::iterator itOrder = insertionOrder.begin(); itOrder != insertionOrder.end(); ++itOrder)
	{
		int		pendIdx = *itOrder; // get current pending block index

		// compute how many pending blocks are smaller
		size_t	numMovedBefore = PmergeMe::countSmallerPending(insertionOrder, itOrder, pendIdx);

		// locate the start of the pending block in the main list
		std::list<int>::iterator	startIt = lst.begin();
		std::advance(startIt, posPending + (pendIdx - 1 - numMovedBefore) * blockSize);

		// locate the end of the pending block
		std::list<int>::iterator	blockEndIt = startIt;
		std::advance(blockEndIt, blockSize);

		int		k = computeK(pendIdx, jacSeq);
		size_t	numMainBlocks = computeUsefulMainEnd(k, posPending, blockSize);

		// iterator to last element of pending block
		std::list<int>::iterator	lastPendIt = blockEndIt;
		--lastPendIt;

		// find insertion point in main chain
		std::list<int>::iterator	insertIt =	(pendIdx != 1)
												? binaryInsertBlockList(lst, *lastPendIt, blockSize, numMainBlocks, numComp)
												: lst.begin(); // first pending element (b1) can be inserted right away to top of main chain

		if (insertIt != startIt) // move the block if needed
			lst.splice(insertIt, lst, startIt, ++blockEndIt	); // move the whole pending block

		posPending += blockSize;
	}
}

std::list<int>::iterator	PmergeMe::binaryInsertBlockList(std::list<int>& lst, int value,
								int blockSize, size_t numBlocks, int& numComp)
{
    std::list<int>::iterator left = lst.begin();
    std::list<int>::iterator right = lst.begin();
    std::advance(right, numBlocks * blockSize);

    while (std::distance(left, right) > 0)
    {
        std::list<int>::iterator mid = left;
        std::advance(mid, (std::distance(left, right) / blockSize / 2) * blockSize);
        std::list<int>::iterator midValueIt = mid;
        std::advance(midValueIt, blockSize - 1);

        ++numComp;
        if (value < *midValueIt)
            right = mid;
        else
            std::advance(left, std::distance(mid, left) + blockSize);
    }
    return left;
}

// Builds a list from command line arguments
static std::list<int>	buildListFromArgs(int argc, char** argv)
{
	std::list<int>	lst;
	
	for (int i = 1; i < argc; ++i)
		lst.push_back(std::atoi(argv[i]));

	return lst;
}
