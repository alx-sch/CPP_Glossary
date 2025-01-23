/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:42 by aschenk           #+#    #+#             */
/*   Updated: 2024/11/06 17:27:51 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
Implementation of the `Contacts` class, which manages individual contact information
within a phonebook.
*/

#include "main.hpp"

Contacts::Contacts( void ) {}	// Empty / default
Contacts::~Contacts( void ) {}	// Empty / default

/**
Truncates the input string to 10 chars, if need be, and prints the string,
right-aligned with a width of 10 chars.

 @param str 	The string to be truncated and printed.
*/
static void truncAndRightAlign( const std::string& str )
{
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".";	// Print the first 9 chars followed by a dot
	}
	else
	{
		std::cout << std::setw(10) << str;		// Print entire string right-aligned with width of 10 chars.
	}
}

/**
Prints an overview of the contact at the specified index in a formatted table row.

Each field is 10 chars wide, truncated if necessary and right-aligned.

 @param index 	The index of the contact in the phonebook, adjusted for display (1-based).
*/
void	Contacts::printContactOverview( int index ) const
{
	std::ostringstream oss; // Type of output stream that holds its data in a string buffer (Output String Stream)

	oss << (index + 1); // Conversion into a string format and stored in the internal buffer of oss

	// Print contact overview into SEARCH table
	std::cout << PIPE;
	truncAndRightAlign(oss.str());
	std::cout << PIPE;
	truncAndRightAlign(this->_firstName);
	std::cout << PIPE;
	truncAndRightAlign(this->_lastName);
	std::cout << PIPE;
	truncAndRightAlign(this->_nickname);
	std::cout << PIPE;
	std::cout << std::endl;
}

// Prints all contact information fields for this specific contact instance.
void	Contacts::printContactDetails( void ) const
{
	std::cout << std::setw(16) << "First name: " << BOLD << this->_firstName << RESET << std::endl;
	std::cout << std::setw(16) << "Last name: " << BOLD <<  this->_lastName << RESET << std::endl;
	std::cout << std::setw(16) << "Nickname: " << BOLD << this->_nickname << RESET << std::endl;
	std::cout << std::setw(16) << "Phone number: " << BOLD << this->_phoneNumber << RESET << std::endl;
	std::cout << std::setw(16) << "Darkest secret: " << BOLD << this->_darkestSecret << RESET << std::endl;
}

/**
Checks if a given string is empty or contains only whitespace characters.

 @param str 	The string to be checked.

 @return 		`1` if the string is empty or contains only whitespace characters;
				`0` if the string contains any non-whitespace characters.
*/
static int isEmptyOrWhitespace( const std::string& str )
{
	size_t	i;

	if (str.empty())
	{
		return (1); // The string is empty.
	}

	for (i = 0; i < str.length(); ++i)
	{
		if (!std::isspace(static_cast<unsigned int>(str[i]))) // C++-style casting, safter than C-style casting: (unsigned char)(str[i])
		{
			return (0); // Found a non-whitespace character
		}
	}

	return (1); // The string contains only whitespace
}

/**
Validates a phone number string.

This function checks if the provided phone number contains only valid characters,
including digits (0-9), spaces, and specific allowed punctuation characters
such as '+', '-', '(', and ')'.

 @param phoneNumber 	String representing the phone number to validate.

 @return 				`1` if the phone number is valid;
						`0` if it contains any invalid characters.
*/
static int isValidPhoneNumber( const std::string& phoneNumber )
{
	size_t	i;
	char 	c;

	// Check if the phone number contains only digits, spaces, and allowed characters
	for (i = 0; i < phoneNumber.length(); ++i)
	{
		c = phoneNumber[i];
		if  (!std::isdigit(static_cast<unsigned int>(c)) &&
			c != ' ' && c != '+' && c != '-' && c != '(' && c != ')')
		{
			return (0); // Invalid character found
		}
	}

	return (1); // Valid phone number
}

/**
Prompts the user to input a value for a specified contact field.

 @param contactField 	The string that will store the valid input.
 @param prompt 			A string used to prompt the user for the desired input.
 @param phoneNr 		A flag indicating whether to validate the input as a phone number (1 to validate, 0 otherwise).
*/
static void	setContactField( std::string& contactField, const std::string prompt, int phoneNr )
{
	std::string	input;

	while(true)
	{
		std::cout << ADD << std::setw(20) << prompt; //

		std::getline (std::cin,input);

		// Check for EOF in user input (CTRL + D)
		if (std::cin.eof())
		{
			exitEOF();
		}

		// Check if input is empty (user pressed Enter without typing anything)
		if (isEmptyOrWhitespace(input))
		{
			std::cout << EMPTY_FIELD << std::endl;
			continue; // Loop again to get a valid input
		}

		 // Validate phone number if the flag is set
		if (phoneNr && !isValidPhoneNumber(input))
		{
			std::cout << INV_PHONE_NR << std::endl;
			continue; // Loop again to get a valid input
		}

		contactField = input; // Set the contact field
		return ;
	}
}

/**
Prompts the user to enter and store the details of a new contact.

This function sequentially requests input for the first name, last name,
nickname, phone number, and darkest secret of the contact.
*/
void	Contacts::addContact()
{
	setContactField(this->_firstName, "[First name] > ", 0);
	setContactField(this->_lastName, "[Last name] > ", 0);
	setContactField(this->_nickname, "[Nickname] > ", 0);
	setContactField(this->_phoneNumber, "[Phone number] > ", 1);
	setContactField(this->_darkestSecret, "[Darkest secret] > ", 0);
}
