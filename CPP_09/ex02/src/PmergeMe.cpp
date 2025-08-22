#include <string>
#include <cstdlib>		// strtol()
#include <climits>		// INT_MAX
#include <cerrno>		// errno, ERANGE
#include <stdexcept>	// runtime_error()
#include <vector>		// for Jacobsthal sequence, insertion order
#include <algorithm>	// for std::find()

#include "../include/PmergeMe.hpp"

// Checks if the provided arguments are valid integers.
// Throws exceptions for non-numeric values, non-positive numbers,
// and integers exceeding INT_MAX.
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
Generates a vector containing the Jacobsthal sequence indices less than
the given number of pending elements.

The Jacobsthal sequence is defined as:
J(0) = 0, J(1) = 1, J(n) = J(n-1) + 2 * J(n-2) for n > 1
*/
std::vector<int> PmergeMe::buildJacobsthalSeq(int numPending)
{
	std::vector<int>	jacSeq;

	if (numPending <= 0)
		return jacSeq;

	int	j1 = 0, j2 = 1; // first and second Jacobsthal numbers

	if (j1 < numPending) jacSeq.push_back(j1);
	if (j2 < numPending) jacSeq.push_back(j2);

	while (true)
	{
		int	jNext = j2 + 2 * j1; // J(n) = J(n-1) + 2*J(n-2)
		if (jNext >= numPending)
			break;
		jacSeq.push_back(jNext);
		j1 = j2;
		j2 = jNext;
	}

	return jacSeq;
}

/**
Generates the insertion order for pending elements based on Jacobsthal sequence,
which minimizes the number of comparisons.

First, indices are taken from the Jacobsthal sequence.
Then, the remaining indices are filled in reverse order, skipping duplicates.

E.g. for numPending = 8 (indices 0..7) -> Jacobsthal sequence: [0, 1, 3, 5];
then fill remaining indices in reverse: [7, 6, 4, 2]
-> result: [0, 1, 3, 5, 7, 6, 4, 2]

 @param numPending	Number of pending elements
 @param jacSeq		Precomputed Jacobsthal sequence
 @return			Vector with the optimal insertion order
*/
std::vector<int> PmergeMe::buildInsertOrder(int numPending, std::vector<int> jacSeq)
{
	std::vector<int>	order;

	if (numPending <= 0 || jacSeq.empty())
		return order;

	// Insert Jacobsthal indices (skip duplicates and >= numPending)
	for (size_t i = 0; i < jacSeq.size(); ++i)
	{
		if (jacSeq[i] < numPending && std::find(order.begin(), order.end(), jacSeq[i]) == order.end())
			order.push_back(jacSeq[i]);
	}

	// Fill remaining indices in reverse order, avoiding duplicates
	for (int i = numPending - 1; i >= 0; --i)
	{
		if (std::find(order.begin(), order.end(), i) == order.end())
			order.push_back(i);
	}

	return order;
}

/**
 Computes the number of pending 'b' blocks in the Ford–Johnson sorting algorithm.

 - Blocks are paired as (a, b).
 - All 'b' blocks except the first one (b1) are considered pending.
 - If the total number of blocks is odd, there is a leftover 'b' without
   a corresponding 'a', which is also counted as pending.
*/
int PmergeMe::getNumPending(int numBlocks)
{
	if (numBlocks <= 2) // two blocks -> 'b1 < a1'; no pending blocks
		return 0;

	int	numPending = (numBlocks / 2) - 1; // all 'paired' b blocks ('a' in main chain); excl. b1
	if (numBlocks % 2 != 0)	// leftover 'b' with no corresponding 'a'
		++numPending;

	return numPending;
}

/**
Checks whether an element belongs to the main chain in the interleaved block layout.

Layout: [b1][a1][b2][a2]...[leftover];
The first b-block (b1) is always part of the main chain as well as all a-blocks.

 @param index		Index of the element in the sequence (starting with 0)
 @param blockSize	Number of elements per block.
 @param totalSize	Total number of elements in the sequence
 @return			`true` if the element is in the main chain, `false` if not (pending/leftover)
*/
bool	PmergeMe::isMainChain(int index, int blockSize, int totalSize)
{
	if (index < blockSize) // first 'b1' block always in main chain
		return true;

	int	blockNum = index / blockSize;  // which block this element belongs to

	// If this block goes past the end -> leftover -> not main chain
	if ((blockNum + 1) * blockSize > totalSize)
		return false;

	// Main chain blocks: odd blockNum = 'a' blocks
	if (blockNum % 2 == 1)
		return true;

	return false;	// remaining b blocks and leftover
}
