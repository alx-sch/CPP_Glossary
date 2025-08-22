#include <string>
#include <cstdlib>		// strtol()
#include <climits>		// INT_MAX
#include <cerrno>		// errno, ERANGE
#include <stdexcept>	// runtime_error()
#include <vector>		// for Jacobsthal sequence, insertion order
#include <algorithm>	// for std::find()

#include "../include/PmergeMe.hpp"
#include "../include/utils.hpp" // DEBUG

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
Generates a vector containing the Jacobsthal sequence indices less than
the given number of pending elements (excl. duplicate `1`).
-> `[0, 1, 3, 5, 11, 21, ...]`

The Jacobsthal sequence is defined as:
J(0) = 0, J(1) = 1, J(n) = J(n-1) + 2 * J(n-2) for n > 1
*/
const std::vector<int> PmergeMe::buildJacobsthalSeq(int numPending)
{
	std::vector<int>	jacSeq;

	if (numPending <= 0)
		return jacSeq;

	int	j1 = 0, j2 = 1; // first and second Jacobsthal numbers

	if (j1 < numPending) jacSeq.push_back(j1); // adds 0
	if (j2 < numPending) jacSeq.push_back(j2); // adds 1

	while (true)
	{
		int	jNext = j2 + 2 * j1; // J(n) = J(n-1) + 2*J(n-2)
		if (jNext >= numPending)
			break;
		jacSeq.push_back(jNext);
		j1 = j2;
		j2 = jNext;
	}

	// Remove duplicate '1'
	if (jacSeq.size() > 2)
		jacSeq.erase(jacSeq.begin() + 1);

	return jacSeq;
}

#include <iostream>

/**
Generates the insertion order for pending elements (indices) based on the
Jacobsthal sequence, minimizing the number of comparisons

For 9 pending elements, the Jacobsthal sequence is `[0, 1, 1, 3, 5]`.
Ignoring `0` and duplicate `1` gives `[1, 3, 5]`.
Filling the gaps between these numbers in a way that a Jacobsthal number comes
first, and then any remaining elements that are smaller than that Jacobsthal number:
`[1, 3, 2, 5, 4]`.
Finally, appending any remaining elements in descending order:
`[1, 3, 2, 5, 4, 9, 8, 7, 6]`.
This represents the insertion order in terms of the n-th pending element.

In this implementation, `b1` is already part of the main chain (`b1 < a1 < a2 < …`),
so the first element can be skipped: `[3, 2, 5, 4, 9, 8, 7, 6]`.

Since the skipped element is not part of the pending elements,
we adjust the n-th positions by subtracting 1, giving `[2, 1, 4, 3, 8, 7, 6, 5]`.
Finally, converting these to 0-based indices for array access
results in the final insertion order: `[1, 0, 3, 2, 7, 6, 5, 4]`.

 @param numPending	Number of pending elements
 @param jacSeq		Precomputed Jacobsthal sequence (no duplicates)
 @return			Vector with optimal insertion order (indices of pending elements)
*/
const std::vector<int> PmergeMe::buildInsertOrder(int numPending, const std::vector<int>& jacSeq)
{
	std::vector<int>	order;

	if (numPending <= 0 || jacSeq.empty())
		return order;

	++numPending; // Adjust for already inserted 'b1'

	// Step 1: collect Jacobsthal numbers
	for (size_t i = 0; i < jacSeq.size() && jacSeq[i] <= numPending; ++i)
	{
		if (jacSeq[i] > 0) // skip JT number '0'
			order.push_back(jacSeq[i]);
	}
 
	// Step 2: fill gaps between JT numbers in a descending way
	std::vector<int>	expanded;
	int					prev = 0;

	for (size_t i = 0; i < order.size(); ++i)
	{
		int	j = order[i];
		expanded.push_back(j);

		// fill gaps between JT numbers
		for (int k = j - 1; k > prev; --k)
			expanded.push_back(k);

		prev = j;
	}

	// Step 3: Append any remaining pending elements in descending order
	for (int i = numPending; i > 1; --i)
	{
		std::cout << "i :" << i << std::endl;
		if (std::find(expanded.begin(), expanded.end(), i) == expanded.end())
			expanded.push_back(i);
	}

	// Step 4: skip first entry (b1 already included in main chain)
	expanded.erase(expanded.begin());

	// Step 5: adjust indices (skip b1: -1; 0-based index: -1 again)
	for (size_t i = 0; i < expanded.size(); ++i)
		expanded[i] -= 2;

	return expanded;
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

Layout: [b1][a1][b2][a2]...<leftover>;
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
	return static_cast<int>(jacSeq.size()); // last group
}
