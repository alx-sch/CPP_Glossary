#include <cerrno>	// for errno
#include <cstdlib>	// for std::stof

#include "../include/ScalarConverter.hpp"

// No need to dfine private constructors or destructors as there is no instantiation of ScalarConverter
// Use default behavior

static bool	isPseudoLiteral(const std::string& s)
{
	return (
		s == "nan" || s == "nanf" ||
		s == "+inf" || s == "-inf" ||
		s == "+inff" || s == "-inff"
	);
}

static bool	isIntLiteral(const std::string& s)
{
	size_t len = s.length();

	// Reject if too short or doesn't end with 'f'
	if (len < 2 || s[len - 1] != 'f')
		return false;

	std::string core = s.substr(0, len - 1); // Remove trailing 'f'

	errno = 0;
	char* endptr;

	long val = std::strtol(core.c_str(), &endptr, 10);
	if (errno == ERANGE || *endptr != '\0') // Check for overflow/underflow or leftover characters
		return false;

	return true;
}

static bool	isFloatLiteral(const std::string& s)
{
	size_t len = s.length();

	 // Reject if too short, doesn't end with 'f', or no decimal point
	if (len < 3 || s[len -1] != 'f' || s.find('.') == std::string::npos)
		return false;

	std::string core = s.substr(0, len - 1); // Remove trailing 'f'

	errno = 0;
	char* endptr;

	float val = std::strtof(core.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0') // Check for overflow/underflow or leftover characters
		return false;

	return true;
}

void ScalarConverter::convert(const std::string& input) {
	// Conversion logic goes here

}
