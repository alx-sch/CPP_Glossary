#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>	// for std::cerr
# include <fstream>		// for std::ofstream
# include <stdexcept>	// for std::runtime_error
# include <cerrno>		// for errno
# include <cstring>		// for strerror

# define RED	"\033[31m"
# define BOLD	"\033[1m"
# define RESET	"\033[0m"

void	printError(const std::string &message);
void	checkArgs(int argc, char **argv);

#endif
