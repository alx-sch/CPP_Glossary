#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <cstddef>	// size_t

class	PmergeMe
{
	public:
		// PmergeMeVec.cpp

		static std::vector<int>	sortVec(int argc, char** argv, int& numComp);
		static int				sortPairsRecursivelyVec(std::vector<int>& vec, int& numComp, int recDepth);
		static int				rearrangeVec(std::vector<int>& vec, int blockSize);
		static void				insertPendingBlocksVec(std::vector<int>& vec, int blockSize, int numPending,
									const std::vector<int>& jacSeq, int& numComp);
		static size_t			binaryInsertBlockVec(const std::vector<int>& vec, int value,
									size_t blockSize, size_t numBlocks, int& numComp);

		// PmergeMeList.cpp

		static std::list<int>	sortList(int argc, char** argv, int& numComp);
		static int				sortPairsRecursivelyList(std::list<int>& lst, int& numComp, int recDepth);
		static int				rearrangeList(std::list<int>& lst, int blockSize);
		static void				insertPendingBlocksList(std::list<int>& lst, int blockSize, int numPending,
									const std::list<int>& jacSeq, int& numComp);
		static std::list<int>::iterator	binaryInsertBlockList(std::list<int>& lst, int value, int blockSize,
											size_t numBlocks, int& numComp);

		// PmergeMeUtils.cpp

		static void				checkArgs(int argc, char** argv);
		static int				getNumPending(int numBlocks);
		static bool				isMainChain(int index, int blockSize, int totalSize);
		static size_t			computeUsefulMainEnd(int k, size_t posPending, size_t blockSize);

		// PmergeMe.tpp

		template<typename Container>
		static Container		buildJacobsthalSeq(int numPending);

		template<typename Container>
		static Container		buildInsertOrder(int numPending, const Container& jacSeq);

		template<typename Container>
		static size_t			countSmallerPending(const Container& insertionOrder,
									typename Container::const_iterator endIt, int pendIdx);

		template<typename Container>
		static int				computeK(int pendIdx, const Container& jacSeq);

	private:
		// Private as to prevent instantiation --> PmergeMe is pure utility / static class
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
};

# include "PmergeMe.tpp"

#endif
