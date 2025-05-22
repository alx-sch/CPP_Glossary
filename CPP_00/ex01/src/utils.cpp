#include "main.hpp"

/**
Exits the program gracefully when an end-of-file (EOF) condition is detected in
user input (CTRL + D).
*/
void	exitEOF( void )
{
	std::cout << std::endl << "Exiting." << std::endl;
	std::cout << BYE << std::endl;

	exit(0);
}
