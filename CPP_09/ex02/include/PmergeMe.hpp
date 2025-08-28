#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>

class	PmergeMe
{
	private:
		// Private as to prevent instantiation --> PmergeMe is pure utility / static class
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

	public:
		// PmergeMeVec.cpp

		static std::vector<int>	sortVec(int argc, char** argv, int& numComp);
		static int				sortPairsRecursivelyVec(std::vector<int>& vec, int& numComp, int recDepth);
		static int				rearrangeVec(std::vector<int>& vec, int blockSize);
		static void				insertPendingBlocksVec(std::vector<int>& vec, int blockSize, int numPending,
									const std::vector<int>& jacSeq, int& numComp);
		static size_t			binaryInsertBlockVec(const std::vector<int>& vec, int value,
									size_t blockSize, size_t numBlocks, int& numComp);

		// PmergeMeLst.cpp

		static std::list<int>	sortLst(int argc, char** argv, int& numComp);

		// PmergeMeUtils.cpp

		static void				checkArgs(int argc, char** argv);
		static int				getNumPending(int numBlocks);
		static bool				isMainChain(int index, int blockSize, int totalSize);
		static int				computeK(int pendIdx, const std::vector<int>& jacSeq);
		static size_t			computeUsefulMainEnd(int k, size_t posPending, size_t blockSize);

		// PmergeMe.tpp

		template<typename Container>
		static Container		buildJacobsthalSeq(int numPending);

		template<typename Container>
		static Container		buildInsertOrder(int numPending, const Container& jacSeq);

		template<typename Container>
		static size_t			countSmallerPending(const Container& insertionOrder, size_t idx, int pendIdx);
};

# include "PmergeMe.tpp"

#endif
