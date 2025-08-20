#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define HEADER_DB		"date,exchange_rate"
# define HEADER_INPUT	"date | value"

# include <map>		// for map
# include <string>	// for string

/** 
'map' is used to store the database of exchange rates.
The key is a date in the format "YYYY-MM-DD" (string),
and the value is the corresponding exchange rate (double).

The 'BitcoinExchange' class manages the input file and database file,
validates them, and parses the database into a map for easy access.

Note: 'double' is used for exchange rates instead of 'float' to avoid precision issues.
*/
class	BitcoinExchange
{
	private:
		std::string						_inputFile;	// Path to input file, provided by user via command line
		std::string						_dbFile;	// Path to database file, set in main.cpp
		std::map<std::string, double>	_db;		// map<date, exchange rate>

		// Utility methods

		void	isReadable(const std::string& filepath) const;
		void	checkHeader(const std::string& filepath, const std::string& expectedHeader) const;
		void	getClosestDateAndRate(std::string& date, double& rate) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& dbFile, const std::string& inputFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void		parseDb();
		void		processInput() const;

		void		setInput(const std::string& inputFile);
		void		setDb(const std::string& dbFile);
};

#endif
