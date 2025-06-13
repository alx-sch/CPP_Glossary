#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>		// for std::map
# include <string>	// for std::string

class	BitcoinExchange
{
	private:
		std::map<std::string, double>	_data; // key: date; value: exchange rate -- double for precision

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& filename); // <- That's the important one: loads the CSV file
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		float		getRateForDate(const std::string& date) const;
		bool		isValidDate(const std::string& date) const;
		static bool	isValidValue(const std::string& valueStr, float& valueOut);
};

#endif
