#include <iostream>		// for cout, endl
#include <iomanip>		// for setw() -> output formatting
#include <fstream>		// for ifstream()
#include <cerrno>		// for errno
#include <cstring>		// for strerror()
#include <cstddef>		// for size_t
#include <cstdlib>		// for strtod()
#include <stdexcept>	// for runtime_error()
#include <string>		// for string, getline()
#include <sstream>		// for stringstream -> int to string conversion

#include "../include/BitcoinExchange.hpp"
#include "../include/utils.hpp"	// for removeWhitespace(), isValidDate()

#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

/////////////////////////////////
// Constructors and Destructor //
/////////////////////////////////

BitcoinExchange::BitcoinExchange() : _inputFile(), _dbFile(), _db() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFile, const std::string& inputFile) : 
	_inputFile(inputFile), 
	_dbFile(dbFile), 
	_db()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : 
	_inputFile(other._inputFile),
	_dbFile(other._dbFile),
	_db(other._db)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other) {
		_inputFile = other._inputFile;
		_dbFile = other._dbFile;
		_db = other._db;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/////////////
// Methods //
/////////////

// Checks format of the database file and parses it into the internal map `_db`.
// Exptected line format: "YYYY-MM-DD,exchange_rate".
// Date must be valid and exchange rate must be a positive float (e.g., 7, 7.000, 7.111, etc.)
void	BitcoinExchange::parseDb()
{
	isReadable(_dbFile);
	checkHeader(_dbFile, HEADER_DB);

	std::ifstream		file(_dbFile.c_str());
	std::string			line;
	int					lineCount = 0; // Line counter for error reporting
	std::ostringstream	oss; // For error messages, line number: int to str
	size_t				delimPos; // Position of the delimiter (comma)
	std::string			date;
	std::string			rateStr;
	double				rate;

	std::getline(file, line); // Skip header line

	while (std::getline(file, line)) {
		++lineCount;
		oss.str(""); // Reset the stringstream for each line
		oss << lineCount;

		if (line.empty()) // Skip empty lines
			continue;

		// Comma present and not at the start or end of the line?
		delimPos = line.find(',');
		if (delimPos == std::string::npos || delimPos == 0 || delimPos == line.length() - 1) {
			throw std::runtime_error("Invalid format in '" + _dbFile + "', line " + oss.str() + ": '" + line + "'. Use: 'YYYY-MM-DD,exchange_rate'");
		}

		// Validate the date
		date = line.substr(0, delimPos);
		if (!isValidDate(date)) {
			throw std::runtime_error("Invalid date in '" + _dbFile + "', line " + oss.str() + ": '" + date + "'. Use valid 'YYYY-MM-DD'");
		}
		// Check if the date already exists in the map (duplicate entries are not allowed)
		if (_db.find(date) != _db.end()) {
			throw std::runtime_error("Duplicate entries in '" + _dbFile + "', line " + oss.str() + ": '" + date + "'");
		}

		// Validate exchange rate
		char*	end;
		rateStr = line.substr(delimPos + 1);
		rate = std::strtod(rateStr.c_str(), &end);
		if (end == rateStr.c_str() || *end != '\0' || rate < 0) { // Just whitespace, invalid characters (3.14abc) or negative value
			throw std::runtime_error("Invalid exchange rate in '" + _dbFile + "', line " + oss.str() + ": '" + rateStr + "'");
		}

		_db[date] = rate; // Store date and rate in the map
	}
}

// Processes the input file line by line and prints out the value for each date (USD)
// by multiplying the exchange rate (USD/BTC) from the database with the input value (amount of BTC).
// Works very much like `parseDb()`, but prints error messages to stdout instead of throwing exceptions.
// - Prints line in white, when the date is found in the database
// - Prints line in yellow, when the date is not found in the database, but a previous
// - Prints line in red, when an error occurs
void	BitcoinExchange::processInput() const
{
	isReadable(_inputFile);
	checkHeader(_inputFile, HEADER_INPUT);

	std::ifstream		file(_inputFile.c_str());
	std::string			line;
	int					lineCount = 0; // Line counter for error reporting
	std::ostringstream	oss; // For error messages, line number: int to str
	size_t				delimPos; // Position of the delimiter (comma)
	std::string			date;
	std::string			amountStr;
	double				amount;
	double				rate;
	bool				fallBack = false; // Flag to indicate if a previous date needed to be used -> colored output

	if (_db.empty()) {
		throw std::runtime_error("Database is empty. Please parse the database file first.");
	}

	std::getline(file, line); // Skip header line

	while (std::getline(file, line)) {
		++lineCount;
		oss.str(""); // Reset the stringstream for each line
		oss << lineCount;

		if (line.empty()) // Skip empty lines
			continue;

		// Bar present and not at the start or end of the line?
		delimPos = line.find('|');
		if (delimPos == std::string::npos || delimPos == 0 || delimPos == line.length() - 1) {
			std::cout << RED << "Error: Invalid format, line " + oss.str() + ": '" + line + "'. Use: 'date | value'" << RESET << std::endl; // The subject is IMO incorrect using 'value' here; should be 'amount'
			continue;
		}

		// Check if the bar is preceded and followed by a space (as subject requires "date | value")
		if (line[delimPos - 1] != ' ' || line[delimPos + 1] != ' ') {
			std::cout << RED << "Error: Invalid format, line " + oss.str() + ": '" + line + "'. Use: 'date | value'" << RESET << std::endl;
			continue;
		}

		// Validate the date
		date = line.substr(0, delimPos - 1); // Skip the space before the bar
		if (!isValidDate(date)) {
			std::cout << RED << "Error: Invalid date, line " + oss.str() + ": '" + date + "'. Use valid 'YYYY-MM-DD'" << RESET << std::endl;
			continue;
		}

		// Validate the amount ('value')
		char*	end;
		amountStr = line.substr(delimPos + 2); // Skip the space after the bar
		amount = std::strtod(amountStr.c_str(), &end);
		if (end == amountStr.c_str() || *end != '\0') { // Just whitespace or invalid characters (3.14abc)
			std::cout << RED << "Error: Invalid value, line " + oss.str() + ": '" + amountStr << "'" << RESET << std::endl;
			continue;
		}
		if (amount < 0 || amount > 1000) { // Amount must be [0, 1000]
			std::cout << RED << "Error: Invalid value, line " + oss.str() + ": '" + amountStr + "'. Must be in range [0, 1000]" << RESET << std::endl;
			continue;
		}

		// Get the (closest) exchange rate for the given date
		rate = getClosestRate(date, fallBack);
		if (rate < 0) { // No match or previous date found
			std::cout << RED << "Error: No exchange rate found for date, line " + oss.str() + ": '" + date << "'" << RESET << std::endl;
			continue;
		}
		
		// Everything is fine, print the result
		if (fallBack) {
			std::cout << YELLOW;
		}
		std::cout	<< date << " => " << std::left << std::setw(7) << amount << " BTC * " << std::left << std::setw(7) 
					<< rate << " USD/BTC = USD " << amount * rate << std::endl;
		if (fallBack) {
			std::cout << RESET;
			fallBack = false; // Reset the fallback flag for the next line
		}
	}
}

/////////////
// Utility //
/////////////

// Check if the file can be opened, is a regular file (not a folder, symbolic link, etc.) is not empty.
// Throws `std::runtime_error` if the check fails.
void	BitcoinExchange::isReadable(const std::string& filepath) const
{
	std::ifstream	file(filepath.c_str());

	if (!file) {
		if (filepath.empty()) {
			throw std::runtime_error("Empty file path: Please set both the database and input file paths via the BitcoinExchange constructor or setters.");
		}
		throw std::runtime_error("Failed to open '" + filepath + "': " + std::strerror(errno));
	}
	if (!isRegularFile(filepath)) {
		throw std::runtime_error("Not a regular file: '" + filepath + "'");
	}
	if (file.peek() == std::ifstream::traits_type::eof()) {
		throw std::runtime_error("File is empty: '" + filepath + "'");
	}
}

// Checks if the file starts with the expected header.
// Throws `std::runtime_error` if the header is missing, empty, or does not match the expected header.
void	BitcoinExchange::checkHeader(const std::string& filepath, const std::string &expectedHeader) const
{
	std::ifstream	file(filepath.c_str());
	std::string		header;

	// Read the first line of the file
	if (!std::getline(file, header)) {
		throw std::runtime_error("Failed to read header line from '" + filepath + "'");
	}

	// Check if first line is empty / just whitespace
	std::string	headerCpy = header;
	removeWhitespace(headerCpy);
	if (headerCpy.empty()) {
		throw std::runtime_error("Header line is empty in '" + filepath + "'. Expected: '" 
			+ expectedHeader + "'\nMake sure to put the header on the first line.");
	}

	// Compare header with expected header
	if (header != expectedHeader) {
		throw std::runtime_error("Header mismatch in '" + filepath + "'. Expected: '" + expectedHeader
			+ "', got: '" + header + "'");
	}
}

// Returns the exchange rate for the given date.
// If the date is not found, it returns the closest previous date's rate.
// If no previous date is found, it returns `-1`.
double	BitcoinExchange::getClosestRate(const std::string& date, bool& fallBack) const
{
	std::map<std::string, double>::const_iterator	it = _db.lower_bound(date); // Find the first date that is equal to or greater than the given date
	
	if (it != _db.end() && it->first == date) { // Exact match
		return it->second;
	}
	else if (it != _db.begin()) { // No exact match, but we can go back to the closest earlier date
		--it;
		fallBack = true; // Set the fallback flag to true, indicating we used a previous date
		return it->second;
	}
	else { // No exact match and no earlier date exists
		return -1;
	}
}

///////////////////////
// Setters & Getters //
///////////////////////

// Sets the input file path.
void	BitcoinExchange::setInput(const std::string& inputFile)
{
	_inputFile = inputFile;
}

// Sets the database file path.
void	BitcoinExchange::setDb(const std::string& dbFile)
{
	_dbFile = dbFile;
}
