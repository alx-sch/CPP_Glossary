#include <iostream>
#include "../include/BitcoinExchange.hpp"

// Path to the database file containing exchange rates
#define DB_FILE	"assets/data.csv"

#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define BOLD	"\033[1m"
#define RESET	"\033[0m"

int	main(int argc, char **argv)
{
	// Input file path provided by the user?
	if (argc != 2)
	{
		std::cerr << YELLOW << BOLD << "Usage: " << argv[0] << " <input_file>" << RESET << std::endl;
		return 1;
	}

	// Create a BitcoinExchange instance with the database and input file
	// Either use the default constructor and set the files later, or use the parameterized constructor

	BitcoinExchange	bitcoinExchange(DB_FILE, argv[1]);

	// Alternative: 
	// BitcoinExchange bitcoinExchange;
	// bitcoinExchange.setDbFile(DB_FILE);
	// bitcoinExchange.setInputFile(argv[1]);

	try
	{
		bitcoinExchange.validateFiles();
		bitcoinExchange.parseDb();



	}
	catch (const std::exception &e)
	{
		std::cerr << RED << BOLD << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}
