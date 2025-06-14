
#include  "../include/utils.hpp"

// Prints a formatted error message to std::cerr
void	printError(const std::string &message)
{
	std::cerr << RED << BOLD << "Error: " << message << RESET << std::endl;
}

// Checks if exactly one argument is provided and if the input file can be opened
void	checkInput(int argc, char **argv)
{
	// Exactly one arg provided?
	if (argc != 2)
		throw std::runtime_error("Expected exactly one argument. Usage: '" + std::string(argv[0]) + " <filename>'");

	// Open txt file 
	std::ifstream	file(argv[1]);
	if (!file)
		throw std::runtime_error("Failed to open '" + std::string(argv[1]) + "': " + std::strerror(errno));
	file.close();
}
