#ifndef UTILS_HPP
# define UTILS_HPP

# include <algorithm>	// for remove_if()
# include <cctype>		// for isspace(), isdigit()
# include <cstdlib>		// for atoi()
# include <string>		// for string

void	removeWhitespace(std::string &line);
bool	isValidDate(const std::string& date);

#endif
