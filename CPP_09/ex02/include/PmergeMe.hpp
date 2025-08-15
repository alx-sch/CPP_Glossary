#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class	PmergeMe
{
	private:
		// Private as to prevent instantiation --> PmergeMe is pure utility / static class
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

	public:
		static void	checkArgs(int argc, char** argv);
		static void	sort(int argc, char** argv);
};
#endif
