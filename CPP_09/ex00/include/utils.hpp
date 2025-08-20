#ifndef UTILS_HPP
# define UTILS_HPP

# include <algorithm>	// for remove_if()
# include <cctype>		// for isspace(), isdigit()
# include <cstdlib>		// for atoi()
# include <string>		// for string
# include <sys/stat.h>  // for stat()

bool	isRegularFile(const std::string& path);
void	removeWhitespace(std::string& line);
bool	isValidDate(const std::string& date);

#endif
