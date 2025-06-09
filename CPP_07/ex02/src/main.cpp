#include <iostream>
#include <string>
#include "../include/Array.hpp"

#define RED		"\033[31m"
#define BOLD	"\033[1m"
#define RESET	"\033[0m"

int main()
{
	try
	{
		// Test default constructor (empty array)
		Array<int> arr1;
		std::cout << "arr1 size: " << arr1.size() << std::endl;

		// Test constructor with size
		Array<int> arr2(5);
		std::cout << "arr2 size: " << arr2.size() << std::endl;
		std::cout << "arr2[0]: " << arr2[0] << std::endl;

		// Assign values to arr2
		for (unsigned int i = 0; i < arr2.size(); ++i)
			arr2[i] = (i + 1) * 10;

		std::cout << "arr2 is: ";
		for (unsigned int i = 0; i < arr2.size(); ++i)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;

		// Test copy constructor
		Array<int> arr3(arr2);
		std::cout << "arr3 (copy of arr2) is: ";
		for (unsigned int i = 0; i < arr3.size(); ++i)
			std::cout << arr3[i] << " ";
		std::cout << std::endl;

		// Modify arr3 and show arr2 remains unchanged
		arr3[0] = 999;
		std::cout << "After modifying arr3[0]: " << std::endl;
		std::cout << "arr3[0]: " << arr3[0] << std::endl;
		std::cout << "arr2[0]: " << arr2[0] << " (should be unchanged)" << std::endl;

		// Test assignment operator
		Array<int> arr4;
		arr4 = arr2;
		std::cout << "arr4 (assigned from arr2) is: ";
		for (unsigned int i = 0; i < arr4.size(); ++i)
			std::cout << arr4[i] << " ";
		std::cout << std::endl;

		// Test const operator[]
		const Array<int> constArrCopy(arr2);
		std::cout << "constArrCopy (assigned from arr2) is: ";
		for (unsigned int i = 0; i < constArrCopy.size(); ++i)
			std::cout << constArrCopy[i] << " ";
		std::cout << std::endl;

		// Now test with std::string
		Array<std::string>	arrStr(3);

		arrStr[0] = "Hello";
		arrStr[1] = "World";
		arrStr[2] = "!";

		std::cout << "arrStr is: ";
		for (unsigned int i = 0; i < arrStr.size(); ++i)
			std::cout << '"' << arrStr[i] << "\" ";
		std::cout << std::endl;

		// Trying to modify a const array should not compile
		// constArrCopy[0] = 100;

		// Test out-of-bounds exception
		std::cout << "Attempting out-of-bounds access..." << std::endl;
		std::cout << arr4[10] << std::endl;  // This should throw
	}
	catch (const Array<int>::OutOfBoundsException& e)
	{
		std::cerr << RED << BOLD << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << BOLD << "Exception: " << e.what() << RESET << std::endl;
	}

	return 0;
}
