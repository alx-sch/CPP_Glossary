#include <iostream>
#include "../include/ScalarConverter.hpp"

// Trims leading and trailing whitespace from a string
static	std::string trim(const std::string& s)
{
	size_t	start = 0;
	while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
		++start;

	size_t	end = s.size();
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		--end;

	return s.substr(start, end - start);
}

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <value>\n";
		return 1;
	}

	std::string input = trim(argv[1]);
	ScalarConverter::convert(input);

	return 0;
}
