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

////////////////////////////////
// Consructors and Destructor //
////////////////////////////////

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

// Validates the input and database files by checking if they are readable,
// have the correct headers, and if the database file is valid.
void	BitcoinExchange::validateFiles() const
{
	isReadable(_inputFile);
	isReadable(_dbFile);
	checkHeader(_inputFile, HEADER_INPUT);
	checkHeader(_dbFile, HEADER_DB);
}

// Checks format of the database file and parses it into the internal map '_db'.
// Exptected line format: "YYYY-MM-DD,exchange_rate";
// date must be valid and exchange rate must be a positive float (e.g., 7, 7.000, 7.111, etc.)
void	BitcoinExchange::parseDb()
{
	std::ifstream		file(_dbFile.c_str());
	std::string			line;
	int					lineCount = 0; // Line counter for error reporting
	size_t				comma; // Position of the comma in the line
	std::ostringstream	oss; // For error messages, line number: int to str
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
		comma = line.find(',');
		if (comma == std::string::npos || comma == 0 || comma == line.length() - 1) {
			throw std::runtime_error("Invalid format in '" + _dbFile + "', line " + oss.str() + ": '" + line + "'. Use: 'YYYY-MM-DD,exchange_rate'");
		}

		date = line.substr(0, comma);
		rateStr = line.substr(comma + 1);

		if (!isValidDate(date)) {
			throw std::runtime_error("Invalid date in '" + _dbFile + "', line " + oss.str() + ": '" + date + "'. Use valid 'YYYY-MM-DD'");
		}

		// Validate exchange rate
		char*	end;
		rate = std::strtod(rateStr.c_str(), &end);
		if (end == rateStr.c_str() || *end != '\0' || rate < 0) { // Just whitespace or invalid characters "3.14abc"
			throw std::runtime_error("Invalid exchange rate in '" + _dbFile + "', line " + oss.str() + ": '" + rateStr + "'");
		}

		_db[date] = rate; // Store date and rate in the map
	}
}

/////////////
// Utility //
/////////////

// Check if the file can be opened and is not empty.
// Throws 'std::runtime_error' if the file cannot be opened or is empty.
void	BitcoinExchange::isReadable(const std::string& filepath) const
{
	std::ifstream	file(filepath.c_str());

	if (!file) {
		if (filepath.empty()) {
			throw std::runtime_error("Empty file path. Set file paths in the BitcoinExchange constructor or via setters.");
		}
		throw std::runtime_error("Failed to open '" + filepath + "': " + std::strerror(errno));
	}
	if (file.peek() == std::ifstream::traits_type::eof()) {
		throw std::runtime_error("File is empty: '" + filepath + "'");
	}
}

// Checks if the file starts with the expected header.
// Throws 'std::runtime_error' if the header is missing, empty, or does not match the expected header.
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

/////////////
// Setters //
/////////////

void	BitcoinExchange::setInputFile(const std::string& inputFile)
{
	_inputFile = inputFile;
}
void	BitcoinExchange::setDbFile(const std::string& dbFile)
{
	_dbFile = dbFile;
}
