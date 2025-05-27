#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>
# include <cerrno>	// for errno
# include <cstdlib>	// for strtol, strtod, strtof
# include <climits>	// for INT_MAX, INT_MIN
# include <cmath>	// for std::floor
# include <sstream>	// for std::ostringstream

// detectType.cpp

bool		isCharLiteral(const std::string& s);
bool		isPseudoLiteral(const std::string& s);
bool		isFloatPseudoLiteral(const std::string& s);
bool		isIntLiteral(const std::string& s);
bool		isFloatLiteral(const std::string& s);
bool		isDoubleLiteral(const std::string& s);

// printType.cpp

void		printInt(double val);
void		printFloatDouble(double val);
void		printChar(double val);
void		printOther(const std::string& s);

// utils.cpp

std::string	process(const std::string& s);

#endif
