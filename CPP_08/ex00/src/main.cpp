#include <iostream>
#include <vector>
#include <list>
#include <iterator>	// for std::distance
#include "../include/easyfind.hpp"

#define RED		"\033[31m"
#define BOLD	"\033[1m"
#define RESET	"\033[0m"

int	main()
{
	{	// Testing VECTOR
		std::vector<int>	vec;
		vec.push_back(1);
		vec.push_back(42);
		vec.push_back(-99);
		vec.push_back(3);

		try
		{
			std::vector<int>::iterator	it = easyfind(vec, 42);
			std::cout	<< "Value '" << *it << "' found at vec["
						<< std::distance(vec.begin(), it) << "]." << std::endl;
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << RED << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
		}

		try
		{
			std::vector<int>::iterator	it = easyfind(vec, 123);
			std::cout	<< "Value '" << *it << "' found at vec["
						<< std::distance(vec.begin(), it) << "]." << std::endl;
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << RED << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	{	// Testing LIST
		std::list<int>	lst;
		lst.push_back(-1);
		lst.push_back(-42);
		lst.push_back(99);
		lst.push_back(-3);

		try
		{
			std::list<int>::iterator	it = easyfind(lst, -99);
			std::cout	<< "Value '" << *it << "' found at lst["
						<< std::distance(lst.begin(), it) << "]." << std::endl;
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << RED << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
		}

		try
		{
			std::list<int>::iterator	it = easyfind(lst, 1234);
			std::cout	<< "Value '" << *it << "' found at lst["
						<< std::distance(lst.begin(), it) << "]." << std::endl;
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << RED << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	return 0;
}
