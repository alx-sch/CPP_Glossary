#include "../include/utils.hpp"

// Check if the given path is a regular file (and not, for example, a directory or symlink).
// `stat()` retrieves information about the file, directory etc. specified by `path`.
bool	isRegularFile(const std::string& path)
{
	struct stat	s;
	if (stat(path.c_str(), &s) != 0) {
		// stat failed (file doesn't exist or can't be accessed)
		return false;
	}
	return S_ISREG(s.st_mode); // true if it's a regular file
}

// Returns true if `c` is a whitespace character, safely handling signed chars.
static bool	isWhitespace(char c)
{
	return std::isspace(static_cast<unsigned char>(c));
}

// Removes all whitespace characters from the given string using iterators and `std::remove_if`.
// Handles potential signed char issues by casting to unsigned char before passing to `std::isspace`.
void	removeWhitespace(std::string& line)
{
	line.erase(
		std::remove_if(line.begin(), line.end(), isWhitespace),
		line.end()
	);
}

// A year is a leap year if it is divisible by 4,
// except for end-of-century years, which must be divisible by 400.
static bool	isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Validates a date string in the format 'YYYY-MM-DD'.
// Checks for valid range of year, month, and day, taking leap years into account.
bool	isValidDate(const std::string& date)
{
	// Basic date validation: 'YYYY-MM-DD' format
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	// Check if the year, month, and day are valid integers
	for (size_t i = 0; i < date.length(); ++i) {
		if (i == 4 || i == 7) // Skip dashes
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	// Days in each month (index 0 = Jan, 1 = Feb, ..., 11 = Dec)
	int	daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear(year)) {
		daysInMonth[1] = 29;
	}

	// Check day range for given month
	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}	
