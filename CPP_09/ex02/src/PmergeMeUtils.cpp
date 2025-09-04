#include "../include/PmergeMe.hpp"

#include <string>
#include <cstddef>		// size_t
#include <cstdlib>		// strtol()
#include <climits>		// INT_MAX
#include <cerrno>		// errno, ERANGE
#include <stdexcept>	// runtime_error()

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
Computes the number of main chain blocks that should be considered when inserting
a pending block.

The number of blocks in the main chain to be used during insertion is defined by
the insertion group `k` (`2^k - 1`), and cannot exceed the number of blocks currently
available in the main chain.

 @param k			Insertion group index, also the number of comparisons allowed
 @param posPending	Number of elements currently in main chain
 @param blockSize	Size of each block
 @return			Number of "useful" blocks to consider in binary search
*/
size_t	PmergeMe::computeUsefulMainEnd(int k, size_t posPending, size_t blockSize)
{
	size_t	usefulEnd = (1u << k) - 1; // 2^k - 1 blocks allowed according to FJ
	size_t	availableBlocks = posPending / blockSize; // blocks in main chain

	if (usefulEnd > availableBlocks)
		usefulEnd = availableBlocks;

	return usefulEnd;
}
