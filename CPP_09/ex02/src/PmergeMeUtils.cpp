#include <string>
#include <cstdlib>		// strtol()
#include <climits>		// INT_MAX
#include <cerrno>		// errno, ERANGE
#include <stdexcept>	// runtime_error()

#include "../include/PmergeMe.hpp"

// Checks if the provided arguments are valid integers.
// Throws exceptions for non-numeric values, non-positive numbers,
// and integers exceeding `INT_MAX`.
void	PmergeMe::checkArgs(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		errno = 0; // Reset errno before call to strtol()
		char*		endptr;
		std::string	arg(argv[i]); // Convert C-style string (const char*) to std::string
		long		val = strtol(argv[i], &endptr, 10); // Convert to long (base 10); might set errno

		if (errno == ERANGE || val > INT_MAX)
			throw std::runtime_error("Integer overflow: value exceeds INT_MAX: " + arg);

		if (*argv[i] == '\0' || *endptr != '\0')
			throw std::runtime_error("Invalid input, not an integer: '" + arg + "'");

		if (val < 0)
			throw std::runtime_error("Only positive integers are allowed [0, INT_MAX]: " + arg);
	}
}

/**
 Computes the number of pending 'b' blocks in the Ford–Johnson sorting algorithm.

 - Blocks are paired as (a, b).
 - All 'b' blocks are considered pending.
 - If the total number of blocks is odd, there is a leftover 'b' without
   a corresponding 'a', which is also counted as pending.
*/
int PmergeMe::getNumPending(int numBlocks)
{
	int	numPending = (numBlocks / 2); // each pair contributes one 'b'
	if (numBlocks % 2 != 0)	// if odd number of blocks, leftover 'b' also pending
		++numPending;

	return numPending;
}

/**
Checks whether an element belongs to the main chain in the interleaved block layout.

Layout: [b1][a1][b2][a2]...<leftover>;
-> Main chain -> all 'a' blocks

 @param index		Index of the element in the sequence
 @param blockSize	Number of elements per block.
 @param totalSize	Total number of elements in the sequence
 @return			`true` if the element is in the main chain, `false` if not (pending/leftover)
*/
bool	PmergeMe::isMainChain(int index, int blockSize, int totalSize)
{
	int	blockNum = index / blockSize;  // which block does this element belong to

	// leftover -> not main chain
	if ((blockNum + 1) * blockSize > totalSize)
		return false;

	// main chain: odd-numbered blocks (a-blocks)
	if (blockNum % 2 == 1)
		return true;

	return false;	// all b-blocks and leftover
}

/**
Computes the "insertion group" `k` for a given pending element index.

`pendIdx` is the 1-based index of the pending element (starting from `b1`).
The maximum number of comparisons needed to insert this element into the
main chain is `(2^k) - 1`.

Special case: if `pendIdx == 1` (`b1`), it can be inserted with 0 comparisons.
*/
int	PmergeMe::computeK(int pendIdx, const std::vector<int>& jacSeq)
{
	for (size_t i = 0; i < jacSeq.size(); ++i)
	{
		if (pendIdx <= jacSeq[i])
			return static_cast<int>(i + 1); // JT sequence is 1-based for k
	}
	// Should never happen (as cap is included in JT seq), but here to make compiler happy
	return static_cast<int>(jacSeq.size());
}

/**
Computes the number of useful main chain blocks for a pending block.
Uses Jacobsthal-based `k` to limit the search range.

 @param k			insertion group from `computeK()`
 @param posPending	number of elements currently in main chain
 @param blockSize	size of each block
 @return			number of blocks to consider in binary search
*/
size_t	PmergeMe::computeUsefulMainEnd(int k, size_t posPending, size_t blockSize)
{
	size_t	maxElements = (1u << k) - 1; // 2^k - 1 elements allowed
	if (maxElements > posPending)
		maxElements = posPending;

	size_t	numBlocks = maxElements / blockSize;
	if (maxElements % blockSize != 0)
		++numBlocks;

	return numBlocks;

	// size_t maxBlocks = (1u << k) - 1;               // 2^k - 1 blocks allowed
	// size_t availableBlocks = posPending / blockSize;
	// if (posPending % blockSize != 0)
	// 	++availableBlocks;                          // account for remainder

	// if (maxBlocks > availableBlocks)
	// 	maxBlocks = availableBlocks;

	// return maxBlocks;
}
