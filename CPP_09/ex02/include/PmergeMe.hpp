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
		static void				insertPendingBlocksVec(std::vector<int>& vec, int blockSize, int& posPending, const std::vector<int>& insertionOrder);	
		static void				binaryInsertVec(std::vector<int>& vec, int value, size_t end, int& numComp);

		// PmergeMeLst.cpp

		static std::list<int>	sortLst(int argc, char** argv, int& numComp);

		// PmergeMeUtils.cpp

		static void				checkArgs(int argc, char** argv);
		static int				getNumPending(int numBlocks);
		static bool				isMainChain(int index, int blockSize, int totalSize);
		static int				computeK(int pendIdx, const std::vector<int>& jacSeq);

		// PmergeMeUtils.tpp

		template<typename Container>
		static Container		buildJacobsthalSeq(int numPending);

		template<typename Container>
		static Container		buildInsertOrder(int numPending, const Container& jacSeq);
};

# include "PmergeMe.tpp"

#endif
