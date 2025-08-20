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

		// PmergeMeVec.cpp

		static std::vector<int>	sortVec(int argc, char** argv, int& numComp);

		// PmergeMeLst.cpp

		static std::list<int>	sortLst(int argc, char** argv, int& numComp);
};

#endif
