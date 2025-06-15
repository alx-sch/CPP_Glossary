#ifndef UTILS_HPP
# define UTILS_HPP

# define RED	"\033[31m"
# define BOLD	"\033[1m"
# define RESET	"\033[0m"

# include <algorithm> 	// for std::remove_if
# include <cctype>		// for std::isspace
# include <cerrno>		// for errno
# include <cstring>		// for strerror
# include <fstream>		// for std::ifstream
# include <iostream>	// for std::cerr
# include <stdexcept>	// for std::runtime_error
# include <string>		// for std::string

void	printError(const std::string &message);
void	checkArgs(int argc, char **argv);
void	open_nonempty_file(std::ifstream& file, const std::string& filepath);
void	checkHeader(std::ifstream &file, const std::string& filepath, const std::string &expectedHeader);

#endif
