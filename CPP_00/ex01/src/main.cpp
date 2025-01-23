/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:48 by aschenk           #+#    #+#             */
/*   Updated: 2024/11/06 17:19:23 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/**
Entry point of the PhoneBook application.

This function initializes the PhoneBook application, displays the title,
and enters a loop to process user commands. The user can enter commands
to add a contact, search for contacts, or exit the application.

Commands:
 - "ADD":		Adds a new contact to the phonebook.
 - "SEARCH":	Displays the list of contacts and allows the user to search for a contact.
 - "EXIT":		Exits the application.

 @return		`0` upon successful completion.
*/
int	main( void )
{
	PhoneBook		Phonebook;
	std::string 	input;

	std::cout << TITLE << std::endl;

	while (true)
	{
		std::cout << std::endl << PROMPT << std::endl;

		std::getline(std::cin, input);

		// Check for EOF in user input (CTRL + D)
		if (std::cin.eof())
		{
			exitEOF();
		}

		// Check user input
		else if (input == "ADD")
		{
			Phonebook.addContact();
		}
		else if (input == "SEARCH")
		{
			Phonebook.showContacts();
		}
		else if (input == "EXIT")
		{
			std::cout << BYE << std::endl;
			break ;	// Exit loop and end program
		}
		else	// Invalid command, continue loop and prompt user again
		{
			std::cout << ERR_NOT_FOUND << std::endl;
		}
	}

	return 0;
}
