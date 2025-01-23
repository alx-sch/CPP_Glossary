// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once 			// Ensures that header is only included once during compilation
#ifndef __ACCOUNT_H__	// Safeguards are actually redundant with `#pragma once`
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t; 					// Define a type `t` alias for the Account class

	static int	getNbAccounts( void ); 		// Returns the number of accounts
	static int	getTotalAmount( void );		// Returns the total amount of all accounts
	static int	getNbDeposits( void );		// Returns the total number of deposits
	static int	getNbWithdrawals( void );	// Returns the total number of withdrawals
	static void	displayAccountsInfos( void );	// Displays the number of accounts, total amount, total number of deposits, and total number of withdrawals

	Account( int initial_deposit );			// Constructor with initial deposit
	~Account( void );						// Destructor

	void		makeDeposit( int deposit );		// Deposit money into the account
	bool		makeWithdrawal( int withdrawal );	// Withdraw money from the account
	int			checkAmount( void ) const;		// Check the current balance of the account
	void		displayStatus( void ) const;	// Display the status of the account


private:

	static int	_nbAccounts;				// Number of accounts
	static int	_totalAmount;				// Total amount of all accounts
	static int	_totalNbDeposits;			// Total number of deposits
	static int	_totalNbWithdrawals;		// Total number of withdrawals

	static void	_displayTimestamp( void );	// Display the current timestamp

	int			_accountIndex;				// Account index
	int			_amount;					// Account balance
	int			_nbDeposits;				// Number of deposits
	int			_nbWithdrawals;				// Number of withdrawals

	Account( void );						// Private default constructor

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
