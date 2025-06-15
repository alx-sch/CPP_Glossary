#include "../include/utils.hpp"

// Prints a formatted error message to std::cerr.
void	printError(const std::string &message)
{
	std::cerr << RED << BOLD << "Error: " << message << RESET << std::endl;
}

// Checks if the number of command line arguments is exactly 2.
// Throws 'std::runtime_error' with usage information if the check fails.
void	checkArgs(int argc, char **argv)
{
	if (argc != 2) {
		throw std::runtime_error("Expected exactly one argument. Usage: '" + std::string(argv[0]) + " <filename>'");
	}
}

// Opens the file at 'filepath' using the provided ifstream reference.
// Throws 'std::runtime_error' if the file cannot be opened or is empty.
// The file stream is left open and ready for reading if successful.
void	open_nonempty_file(std::ifstream& file, const std::string& filepath)
{
	file.open(filepath.c_str());
	if (!file){
		throw std::runtime_error("Failed to open '" + filepath + "': " + std::strerror(errno));
	}
	if (file.peek() == std::ifstream::traits_type::eof()) {
		throw std::runtime_error("File is empty: '" + filepath + "'");
	}
}

// Returns true if c is a whitespace character, safely handling signed chars.
static bool	is_space(char c)
{
	return std::isspace(static_cast<unsigned char>(c));
}

// Removes all whitespace characters from the given string using iterators and std::remove_if.
// Handles potential signed char issues by casting to unsigned char before passing to std::isspace.
static void	remove_whitespace(std::string &line)
{
	line.erase(
		std::remove_if(line.begin(), line.end(), is_space),
		line.end()
	);
}

/**
Checks if the file starts with the expected header.
Throws 'std::runtime_error' if the header is missing, empty, or does not match the expected header.

 @param file 			The input file stream to check.
 @param filepath 		The path to the file, used for error messages.
 @param expectedHeader 	The expected header string; whitespace will be ignored.
*/
void	checkHeader(std::ifstream &file, const std::string& filepath, const std::string &expectedHeader)
{
	std::string	header;

	// Read the first line of the file
	if (!std::getline(file, header)) {
		throw std::runtime_error("Failed to read header line from '" + filepath + "'");
	}

	// Check if first line is empty / just whitespace
	std::string	headerCpy = header;
	remove_whitespace(headerCpy);
	if (headerCpy.empty()) {
		throw std::runtime_error("Header line is empty in '" + filepath + "'. Expected: '" 
			+ expectedHeader + "'\nMake sure to put the header on the first line.");
	}

	// Compare header with expected header, ignoring whitespace
	if (header != expectedHeader) {
		throw std::runtime_error("Header mismatch in '" + filepath + "'. Expected: '" + expectedHeader + "'");
	}
}
