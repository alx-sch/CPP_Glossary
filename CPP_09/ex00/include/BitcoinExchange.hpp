#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>		// for std::map
# include <string>	// for std::string
# include <fstream>	// for std::ifstream

/** 
'map' is used to store key-value pairs, where the key is a date (string)
and the value is an exchange rate (double). 'double' is usded instead of 'float'
because float loses precision after ~6 significant digits.
Exchange rates like 47115.93 BTC/USD require at least 7 digits, and float
may introduce rounding errors.
*/

class	BitcoinExchange
{
	private:
		std::map<std::string, double>	_data;	// key: date; value: exchange rate

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& dbFile, const std::string& inputFile); // <- That's the important one: loads CSV and input file
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		static void		checkInputFile(std::ifstream& file, const std::string& filename, const std::string& expectedHeader);

		double			getRateForDate(const std::string& date) const;
		bool			isValidDate(const std::string& date) const;
		static bool		isValidValue(const std::string& valueStr, float& valueOut);
};

#endif
