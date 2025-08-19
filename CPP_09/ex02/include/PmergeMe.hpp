#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>

class	PmergeMe
{
	private:
		// Private as to prevent instantiation --> PmergeMe is pure utility / static class
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

	public:
		static void				checkArgs(int argc, char** argv);
		static std::vector<int>	sortVec(int argc, char** argv);
};

#endif
