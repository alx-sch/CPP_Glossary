#include "Account.hpp"

#include <fstream>	// for std::ofstream
#include <ctime>	// for std::time_t, std::time, std::localtime, std::strftime


/****************************************/
/* UTILITY FCTS (NOT PART OF THE CLASS) */
/****************************************/

/**
Gets the current time in seconds (std::time_t) since epoch.

 @return `std::time_t`: 	The current time in seconds since epoch.
*/
static std::time_t	getCurrentTime( void )
{
	std::time_t	now;

	std::time(&now);	// Get current time in seconds since epoch
	return now;
}

/**
Opens a log file with a timestamped filename in the format "YYYYMMDD_HHMMSS.log".

The log file is opened only once during the program's execution, ensuring that
subsequent calls to this function return the same output file stream.

 @return `std::ofstream&`: 	A reference to the output file stream for writing to the log file.
*/
static std::ofstream&	getLogFile( void )	// std::ofstream is a class to write on files
{
	static std::ofstream	logFile;				// static variable -> retains value between function calls
	static bool 			initialized = false;	// static: prevents the file from being opened multiple times
	std::time_t				currentTime;
	char					filename[20];			// 20 chars needed for the filename: YYYYMMDD_HHMMSS.log (19) + '\0'

	if (!initialized)
	{
		currentTime = getCurrentTime();

		// std::strftime is used to format date and time information into a string.
		// check `man strftime` for info on specifiers
		// std::localtime converts the time_t value to a tm struct representing the local time
		std::strftime(filename, sizeof(filename), "%Y%m%d_%H%M%S.log", std::localtime(&currentTime));
		logFile.open(filename);
		initialized = true;
	}

	return logFile;
}

/******************/
/* PUBLIC MEMBERS */
/******************/

// Returns the number of accounts
int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

// Returns the total amount of all accounts
int Account::getTotalAmount( void )
{
	return _totalAmount;
}

// Returns the total number of deposits
int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

// Returns the total number of withdrawals
int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

// Logs information about all accounts to the log file
void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	getLogFile()	<< "accounts:" << getNbAccounts()
					<< ";total:" << getTotalAmount()
					<< ";deposits:" << getNbDeposits()
					<< ";withdrawals:" << getNbWithdrawals()
					<< std::endl;
}

/**
Constructor for the `Account` class.
Logs account creation information to the log file for each account instance.

 @param initial_deposit 	Initial deposit amount for the account.
*/
Account::Account( int initial_deposit ) :	_accountIndex(_nbAccounts++),	// Initialize `_nbAccounts` with `_accountIndex` and then increment `_nbAccounts`
											_amount(initial_deposit),		// Initialize `_amount` with `initial_deposit`
											_nbDeposits(0),
											_nbWithdrawals(0)
{
	_totalAmount += initial_deposit;

	// Initial logging for account creation
	_displayTimestamp();
	getLogFile()	<< "index:" << _accountIndex
					<< ";amount:" << _amount
					<< ";created" << std::endl;
}

/**
Destructor for the `Account` class.
Logs account balance and closure information to the log file for each account instance.
*/
Account::~Account( void )
{
	_displayTimestamp();
	getLogFile()	<< "index:" << _accountIndex
					<< ";amount:" << _amount
					<< ";closed" << std::endl;
}

/**
Deposit money into the account.
Logs deposit information to the log file for each deposit made.

 @param deposit 	Amount to deposit into the account.
*/
void Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	getLogFile()	<< "index:" << _accountIndex
					<< ";p_amount:" << _amount - deposit	// Previous amount before deposit
					<< ";deposit:" << deposit
					<< ";amount:" << _amount
					<< ";nb_deposits:" << _nbDeposits
					<< std::endl;
}

/**
Withdraw money from the account.
Logs withdrawal information to the log file for each withdrawal made.

 @param withdrawal 	Amount to withdraw from the account.

 @return 			`true` if the withdrawal was successful;
 					`false` if the withdrawal was refused.
*/
bool Account::makeWithdrawal( int withdrawal )
{
	if (_amount < withdrawal)	// Refuse withdrawal if account balance is insufficient
	{
		_displayTimestamp();
		getLogFile()	<< "index:" << _accountIndex
						<< ";p_amount:" << _amount
						<< ";withdrawal:refused" << std::endl;

		return false;
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	_displayTimestamp();
	getLogFile()	<< "index:" << _accountIndex
					<< ";p_amount:" << _amount + withdrawal	// Previous amount before withdrawal
					<< ";withdrawal:" << withdrawal
					<< ";amount:" << _amount
					<< ";nb_withdrawals:" << _nbWithdrawals
					<< std::endl;

	return true;
}

// Returns the current balance of the account
int Account::checkAmount( void ) const
{
	return _amount;
}

// Logs the status of the account to the log file
void Account::displayStatus( void ) const
{
	_displayTimestamp();
	getLogFile()	<< "index:" << _accountIndex
					<< ";amount:" << checkAmount()
					<< ";deposits:" << _nbDeposits
					<< ";withdrawals:" << _nbWithdrawals
					<< std::endl;
}

/*******************/
/* PRIVATE MEMBERS */
/*******************/

// Initialize static members

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
Logs the current timestamp in the format "[YYYYMMDD_HHMMSS] " to the log file.
*/
void	Account::_displayTimestamp( void )
{
	std::time_t	now;
	char		timestamp[19];	// 19 chars needed for the timestamp: "[YYYYMMDD_HHMMSS] " (18) + '\0'

	now = getCurrentTime();
	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S] ", std::localtime(&now));
	getLogFile() << timestamp;	// Write timestamp to log file
}

// Default constructor (private), should not be used
Account::Account( void ) :	_accountIndex(0),
							_amount(0),
							_nbDeposits(0),
							_nbWithdrawals(0)
{}
