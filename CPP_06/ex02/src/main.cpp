#include <iostream>
#include <cstdlib>	// for std::rand(), std::srand()
#include <ctime>	// for std::time()
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

// Randomly instantiates A, B, or C and returns the instance as a Base pointer
Base*	generate()
{
	std::srand(static_cast<unsigned int>(std::time(0))); // std::time returns long int, cast to unsigned int for srand
	int	r = std::rand() % 3; // Generate a random number between 0 and 2

	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	else
		return new C;
}

// Prints the actual type of the object pointed to by p: "A", "B", or "C".
// 'dynamic_cast' converts a pointer/reference to a base class into a pointer/reference to a derived class at runtime.
// Returns 'NULL' if the object is not of the requested type, which is why we check for it.
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "Unknown type\n";
}

// Prints the actual type of the object pointed to by p: "A", "B", or "C".
// 'dynamic_cast' throws an exception (std::bad_cast) if the object is not of the requested type -> try/catch blocks are used.
// (std::bad_cast is part of the 'typeinfo' library; cannot be used).
void	identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	} catch (...) {} // Do nothing if the cast throws any exception

	try {
		dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	} catch (...) {}

	try {
		dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	} catch (...) {}
	
	std::cout << "Unknown type\n";
}

int	main()
{
	Base*	p = generate();

	std::cout << "Using pointer: ";
	identify(p); // calls identify(Base* p)

	std::cout << "Using reference: ";
	identify(*p); // calls identify(Base& p)

	delete p;
	return 0;
}
