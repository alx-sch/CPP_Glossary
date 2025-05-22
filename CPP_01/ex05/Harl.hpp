#pragma once

#include <string>

#define RED		"\033[1;31m"	// ERROR
#define YELLOW	"\033[1;33m"	// WARNING
#define BLUE	"\033[34m"		// INFO
#define MAGENTA	"\033[35m" 		// DEBUG
#define RESET	"\033[0m"

class	Harl {
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();

	public:
		void	complain(std::string level);
};
