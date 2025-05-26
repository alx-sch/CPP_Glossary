#ifndef SCALARCONVERTERUTILS_HPP
# define SCALARCONVERTERUTILS_HPP

# include <string>

# include <cerrno>	// for errno
# include <cstdlib>	// for strtol, strtod, strtof
# include <climits>	// for INT_MAX, INT_MIN, etc.

bool	isCharLiteral(const std::string& s);
bool	isPseudoLiteral(const std::string& s);
bool	isFloatPseudoLiteral(const std::string& s);
bool	isIntLiteral(const std::string& s);
bool	isFloatLiteral(const std::string& s);
bool	isDoubleLiteral(const std::string& s);

#endif
