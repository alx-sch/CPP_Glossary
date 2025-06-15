#include "../include/BitcoinExchange.hpp"
#include "../include/utils.hpp"

#define DB_FILE			"assets/data.csv"
#define DB_HEADER		"date,exchange_rate"
#define INPUT_HEADER	"date | value"

int	main(int argc, char **argv)
{
	std::ifstream	inputFile;

	try
	{
		checkArgs(argc, argv);

		BitcoinExchange::checkInputFile(inputFile, argv[1], INPUT_HEADER);

		BitcoinExchange	exchange(DB_FILE, argv[1]); // Load DB and input file into BitcoinExchange object

		// Check passed arguments and if input file can be opened
	}
	catch (const std::exception &e)
	{
		printError(e.what());
		return 1;
	}

	return 0;
}
