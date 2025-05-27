#include "../include/utils.hpp"

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
	char*	endptr;
	long	val = std::strtol(s.c_str(), &endptr, 10);

	if (errno == ERANGE || *endptr != '\0')
		return false;
	if (val < INT_MIN || val > INT_MAX)
		return false;

	return true;
}

// Checks if `s` is a valid float literal in decimal notation ending with `f`
bool	isFloatLiteral(const std::string& s)
{
	size_t	len = s.size();

	if (len < 3 || s[len -1] != 'f') // Reject if too short or doesn't end with 'f'
		return false;

	std::string core = s.substr(0, len - 1); // Remove trailing 'f'

	char*	endptr;

	errno = 0;
	std::strtof(core.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0')
		return false;

	return true;
}

// Checks if s is a valid double literal (no trailing chars)
bool	isDoubleLiteral(const std::string& s)
{
	char*		endptr;
	size_t		len = s.size();
	std::string	core;

	if (s[len -1] == 'f') // In case out of bound "float" literal
		core = s.substr(0, len - 1); 
	else
		core = s;

	errno = 0;
	std::strtod(core.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0')
		return false;

	return true;
}

// Checks if s is a valid char literal (printable ASCII character)
bool	isCharLiteral(const std::string& s)
{
	if (s.size() == 1)
		return (s[0] >= 32 && s[0] <= 126);

	return false;
}
