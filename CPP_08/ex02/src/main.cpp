#include <iostream>
#include <exception> // for std::exception
#include "../include/MutantStack.hpp"

int	main()
{
	{ // subject's main()
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl; // Print top element (should be 17)
		
		mstack.pop(); // Remove top element (17)

		std::cout << mstack.size() << std::endl; // Print size of stack (should be 1)

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl; // Print each element in the stack, from bottom to top (should be 5, 3, 737, 5, 0)
			++it;
		}
		std::stack<int>	s(mstack); // Copy mstack to a standard stack

		// Bonus: Change iterator (as non const), and print the value
		*it = 815;
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{ // More tests! -> string MutantStack and const reverse iterator
		MutantStack<std::string>	mstack;

		mstack.push("Hello");
		mstack.push("World");
		mstack.push("!");

		MutantStack<std::string>::const_reverse_iterator	it = mstack.rbegin();
		MutantStack<std::string>::const_reverse_iterator	ite = mstack.rend();

		while (it != ite)
		{
			std::cout << *it << " "; // Print each string in the stack
			++it;
		}
		std::cout << std::endl;

		//*it = "42"; // This line will not compile, as 'it' is a const iterator
	}
	return 0;
}
