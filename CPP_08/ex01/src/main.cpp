#include <iostream>
#include <cstddef>	// for std::size_t
#include <climits>	// for INT_MAX, INT_MIN
#include <cstdlib>	// for std::rand and std::srand
#include <ctime>	// for std::time
#include "../include/Span.hpp"	// also incl. <stdexcept> for std::exception

# define RED	"\033[31m"
# define BOLD	"\033[1m"
# define RESET	"\033[0m"

int	main()
{
	{	// Testing addNumber()
		Span	span(5);

		try
		{
			span.addNumber(INT_MIN);
			span.addNumber(INT_MAX);
			span.addNumber(3);
			span.addNumber(-99);
			span.addNumber(7);
			
			std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
			std::cout << "Longest span: " << span.longestSpan() << std::endl;

			// The next line will throw an exception, Span is already full
			span.addNumber(3); // This will throw std::length_error
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << BOLD << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl;

	{	// Testing addNumbers() and many numbers
		Span	span(10001);

		try
		{
			// Add a single number to start with
			span.addNumber(0);

			// Throws exception as at least two numbers are needed to calculate a span
			span.shortestSpan();
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << BOLD << "Exception: " << e.what() << RESET << std::endl;
		}

		try
		{		
			// Add 9999 numbers at once
			std::vector<int>	manyRandomNumbers(10000);
			std::srand(std::time(0)); // Seed the random number generator
			// Fill the vector with random numbers:
			for (size_t i = 0; i < manyRandomNumbers.size(); ++i) {
				manyRandomNumbers[i] = std::rand();
				if (manyRandomNumbers[i] % 2 == 0)  // Make some numbers negative
					manyRandomNumbers[i] *= -1;
			}

			// Add the range of numbers to the span
			span.addNumbers(manyRandomNumbers.begin(), manyRandomNumbers.end());
			
			std::cout << "Shortest span in many numbers: " << span.shortestSpan() << std::endl;
			std::cout << "Longest span in many numbers: " << span.longestSpan() << std::endl;

			// The next line will throw an exception, Span is already full
			span.addNumber(1001); // This will throw std::length_error

		}
		catch (const std::exception& e)
		{
			std::cerr << RED << BOLD << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	return 0;
}
