#include "../include/utils.hpp"

// Trims leading and trailing whitespace from a string
static	std::string	trim(const std::string& s)
{
	size_t	start = 0;
	while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
		++start;

	size_t	end = s.size();
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		--end;

	return s.substr(start, end - start);
}

// Converts a string to lowercase
static std::string	toLower(const std::string& s)
{
	std::string	result = s;
	for (size_t i = 0; i < result.size(); ++i)
		result[i] = std::tolower(static_cast<unsigned char>(result[i]));
	return result;
}

// Processes the input string by trimming whitespace and converting to lowercase
std::string	process(const std::string& s)
{
	return toLower(trim(s));
}
