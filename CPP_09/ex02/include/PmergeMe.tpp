#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include <algorithm> // for std::find()

/**
Generates the Jacobsthal sequence needed for insertion order
in the Ford–Johnson merge-insertion algorithm.
-> `[0, 1, 3, 5, 11, 21, ...]`

The Jacobsthal sequence is defined as:
J(0) = 0, J(1) = 1; J(n) = J(n-1) + 2 * J(n-2) for n > 1

It's probably an overkill to have the sequence dynamically computed,
just hardcoding the first few numbers would do the trick, but this is more fun ;)

 @param numPending	Number of pending elements
 @return			Container with Jacobsthal sequence (no duplicates)
*/
template <typename Container>
Container	PmergeMe::buildJacobsthalSeq(int numPending)
{
	Container	seq;
	if (numPending <= 0)
		return seq;

	int	j1 = 0, j2 = 1; // first and second Jacobsthal numbers
	if (j1 < numPending) seq.push_back(j1); // adds 0
	if (j2 < numPending) seq.push_back(j2); // adds 1

	while (true)
	{
		int	jNext = j2 + 2 * j1; // J(n) = J(n-1) + 2*J(n-2)
		seq.push_back(jNext);
		if (jNext >= numPending)
			break;
		j1 = j2;
		j2 = jNext;
	}

	if (seq.size() > 2) // Remove duplicate '1'
	{
		typename Container::iterator	it = seq.begin();
		++it;
		seq.erase(it);
	}
	return seq;
}

/**
Builds the optimal insertion order of pending elements for the
Ford–Johnson merge-insertion algorithm, based on a precomputed
Jacobsthal sequence.

The procedure works as follows:
 1.	Collect Jacobsthal numbers > 0 and <= numPending.
 2.	For each consecutive pair of Jacobsthal numbers, first add
	the larger one, then fill the gap below it in descending order.
 3.	Finally, append any remaining indices (those greater than the
 	last Jacobsthal number) in descending order.

Example: numPending = 9
	Jacobsthal sequence (cap included): [0, 1, 3, 5, 11]
	Step 1: [1, 3, 5]
 	Step 2: [1, 3, 2, 5, 4]
 	Step 3: [1, 3, 2, 5, 4, 9, 8, 7, 6]

The resulting vector represents the insertion order of the n-th
pending elements (b1, b3, b2, ...).

 @param numPending	Number of pending elements
 @param jacSeq		Precomputed Jacobsthal sequence (no duplicates)
 @return			Container with optimal insertion order (n-th pending element)
*/
template <typename Container>
Container	PmergeMe::buildInsertOrder(int numPending, const Container& jacSeq)
{
	Container	order;
	if (numPending <= 0 || jacSeq.empty())
		return order;

	// Step 1: collect JT numbers > 0
	for (typename Container::const_iterator it = jacSeq.begin(); it != jacSeq.end(); ++it)
	{
		int	j = *it;
		if (j > 0 && j <= numPending)
			order.push_back(j);
	}

	// Step 2: fill gaps between JT numbers in a descending way
	Container	expanded;
	int			prev = 0;

	for (typename Container::const_iterator it = order.begin(); it != order.end(); ++it)
	{
		int	j = *it;
		expanded.push_back(j);
		for (int k = j - 1; k > prev; --k) // fill gaps between JT numbers
			expanded.push_back(k);
		prev = j;
	}

	// Step 3: Append any remaining pending elements in descending order
	for (int i = numPending; i > 1; --i)
	{
		if (std::find(expanded.begin(), expanded.end(), i) == expanded.end())
			expanded.push_back(i);
	}

	return expanded;
}

// Counts how many elements in the insertion order are smaller than the pending element at pendIdx
template <typename Container>
size_t	PmergeMe::countSmallerPending(const Container& insertionOrder, typename Container::const_iterator endIt, int pendIdx)
{
	size_t	count = 0;

	for (typename Container::const_iterator it = insertionOrder.begin(); it != endIt; ++it)
	{
		if (*it < pendIdx)
			++count;
	}

	return count;
}

/**
Computes the "insertion group" `k` for a given pending element index.
This value is equivalent to the number of comparisons allowed by Ford-Johnson
for this element during the insertion process.

The maximum number of main chain elements that may need to be compared when
inserting this element is `(2^k) - 1`; this also defines the "useful main chain"
considered for binary search.

 @param pendIdx	1-based index of the pending element (starting from b1)
 @param jacSeq	Jacobsthal sequence (no duplicates, starting with 0: 0, 1, 3, 5, ...)
 @return		1-based index of the insertion group
*/
template <typename Container>
int	PmergeMe::computeK(int pendIdx, const Container& jacSeq)
{
	typename Container::const_iterator	it = jacSeq.begin();
	int									i = 0;

	for (; it != jacSeq.end(); ++it, ++i)
		if (pendIdx <= *it)
			return i;

	// fallback (should not happen)
	return i;
}

#endif
