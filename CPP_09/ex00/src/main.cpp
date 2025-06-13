#include "../include/BitcoinExchange.hpp"
#include "../include/utils.hpp" // also incl. <stdexcept> for std::runtime_error

#define DATABASE_FILE	"assets/data.csv"

int	main(int argc, char **argv)
{
	try
	{
		// Load the Bitcoin exchange rates from the CSV file into object
		BitcoinExchange	exchange(DATABASE_FILE);

		// Check passed arguments and if input file can be opened
		checkArgs(argc, argv);
	}
	catch (const std::exception &e)
	{
		printError(e.what());
		return 1;
	}

	return 0;
}
