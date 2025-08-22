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
		// PmergeMe.cpp

		static void				checkArgs(int argc, char** argv);
		static std::vector<int>	buildJacobsthalSeq(int numPending);
		static std::vector<int>	buildInsertOrder(int numPending, std::vector<int> jacSeq);
		static int				getNumPending(int numBlocks);
		static bool				isMainChain(int index, int blockSize, int totalSize);

		// PmergeMeVec.cpp

		static std::vector<int>	sortVec(int argc, char** argv, int& numComp);
		static std::vector<int>	rearrangeVec(const std::vector<int>& vec, int blockSize);
		static void				binaryInsertVec(std::vector<int>& vec, int value, int pos, int& numComp);

		// PmergeMeLst.cpp

		static std::list<int>	sortLst(int argc, char** argv, int& numComp);
};

#endif
