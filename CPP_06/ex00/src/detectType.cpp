#include "../include/ScalarConverterUtils.hpp"

// Checks if s is a pseudo-literal (like "nan", "inf", etc.)
bool	isPseudoLiteral(const std::string& s)
{
	return (
		s == "nan" || s == "nanf" ||
		s == "+nan" || s == "+nanf" ||
		s == "-nan" || s == "-nanf" ||
		s == "inf" || s == "inff" ||
		s == "+inf" || s == "+inff" ||
		s == "-inf" || s == "-inff"
	);
}

// Checks if s is a float pseudo-literal (like "nanf", "inff", etc.)
bool	isFloatPseudoLiteral(const std::string& s)
{
	return (
		s == "nanf" || s == "+nanf" || s == "-nanf" ||
		s == "inff" || s == "+inff" || s == "-inff"
	);
}

// Checks if s is a valid int literal (no trailing chars)
bool	isIntLiteral(const std::string& s)
{
	errno = 0;
	char* endptr;

	long val = std::strtol(s.c_str(), &endptr, 10);
	if (errno == ERANGE || *endptr != '\0')
		return false;

	if (val < INT_MIN || val > INT_MAX)
		return false;

	return true;
}

// Checks if s is a valid long literal (no trailing chars)
bool	isFloatLiteral(const std::string& s)
{
	size_t len = s.size();

	 // Reject if too short, doesn't end with 'f', or no decimal point
	if (len < 3 || s[len -1] != 'f' || s.find('.') == std::string::npos)
		return false;

	std::string core = s.substr(0, len - 1); // Remove trailing 'f'

	errno = 0;
	char* endptr;

	std::strtof(core.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0')
		return false;

	return true;
}

// Checks if s is a valid double literal (no trailing chars)
bool	isDoubleLiteral(const std::string& s)
{
	errno = 0;
	char* endptr;

	std::strtod(s.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0')
		return false;

	return true;
}

// Checks if s is a valid char literal (single printable ASCII character)
bool	isCharLiteral(const std::string& s)
{
	if (s.size() != 1)
		return false;

	char c = s[0];
	return (c >= 32 && c <= 126); // Printable ASCII range
}
