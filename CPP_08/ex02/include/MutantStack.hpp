#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

// Stacks do not have iterators by default. Stacks use 'deque' as their underlying container.
// A deque (double-ended queue) is a sequence container that allows fast insertion and deletion at both ends.
// Below implementation uses deque's iterators to provide custom iterators for the MutantStack class.
// more info: https://en.cppreference.com/w/cpp/container/stack.html

template <typename T>
class MutantStack : public std::stack<T>	// Inherit all of std::stack's functionality
{
	public:
		// Constructors and destructor
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack	&operator=(const MutantStack &other);
		~MutantStack();

		// Custom Iterators
		// 'container_type' is a typedef / type alias refering to the underlying container type of the stack (deque)
		// deque's got the following iterators:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin();
		iterator				end();

		const_iterator			begin() const; 
		const_iterator 			end() const;

		reverse_iterator		rbegin();
		reverse_iterator		rend();

		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

# include "MutantStack.tpp"

#endif
