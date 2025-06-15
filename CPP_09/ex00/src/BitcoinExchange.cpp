#include "../include/BitcoinExchange.hpp"
#include "../include/utils.hpp"

// Consructors and Destructors

BitcoinExchange::BitcoinExchange() : _data() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

////////

void	BitcoinExchange::checkInputFile(std::ifstream& file, const std::string& filename, const std::string& expectedHeader)
{
	open_nonempty_file(file, filename);
	checkHeader(file, filename, expectedHeader);
}


// Load exchange rates from a CSV file via parameterized constructor
// Assumes that the CSV file is formatted correctly (header line, valid dates and rates, no whitespace, etc.)
BitcoinExchange::BitcoinExchange(const std::string& filename, const std::string& inputFile)
{
	std::string		line;
	unsigned int	comma;
	std::string		date;
	std::string		rateStr;
	double			rate;
	std::ifstream	file(filename.c_str());

	(void)inputFile; // Unused parameter, but can be used for further input file processing if needed

	if (!file) {
		throw std::runtime_error("Failed to open DB file '" + filename + "': " + std::strerror(errno));
	}
	
	std::getline(file, line); // skip header

	while (std::getline(file, line)) {
		comma = line.find(',');
		if (comma != std::string::npos) {
			date = line.substr(0, comma);
			rateStr = line.substr(comma + 1);
			rate = std::strtod(rateStr.c_str(), NULL);
			_data[date] = rate; // Store date and rate in the map
		}
	}
	
	if (file.bad()) { // Is 'true' when std::getline() fails due to an error
		throw std::runtime_error("Error reading from file '" + filename + "': " + std::strerror(errno));
	}
}
