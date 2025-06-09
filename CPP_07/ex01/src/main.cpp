#include <iostream>
#include <string>
#include "../include/iter.hpp"

// Function to print elements of the array
template <typename T>
void	print(const T& x)
{
	std::cout << x << std::endl;
}

// // Plain function to print elements of the array
// void	print(int& x)
// {
// 	std::cout << x << std::endl;
// }

// Functor to increment elements of the array
void	increment(int& x)
{
	x++;
}

int	main()
{
	int		arr[] = {1, 2, 3, 4, 5};
	size_t	size = sizeof(arr) / sizeof(arr[0]);

	// Non-const array - can modify elements
	std::cout << "Original int array: \n";
	iter(arr, size, print<int>); // Pass type in order to pass the correct function and not template to 'iter'; instantiate function here
	std::cout << std::endl;

	iter(arr, size, increment);

	std::cout << "Incremented int array: \n";
	iter(arr, size, print<int>);
	std::cout << std::endl;

	// Const array - cannot modify elements, so function must take const ref
	const int	constArr[] = {10, 20, 30, 40};
	size = sizeof(constArr) / sizeof(constArr[0]);

	std::cout << "Const int array: \n";
	iter(constArr, size, print<int>);
	std::cout << std::endl;
	//iter(constArr, size, increment);

	//String const array example
	const std::string	strArr[] = {"apple", "banana", "cherry"};
	size = sizeof(strArr) / sizeof(strArr[0]);

	std::cout << "Const string array: \n";
	iter(strArr, size, print<std::string>);
	std::cout << std::endl;

	return 0;
}
