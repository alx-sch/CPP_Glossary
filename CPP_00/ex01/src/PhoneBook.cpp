/**
Implementation of the `PhoneBook` class, managing contact storage and display.
*/

#include "main.hpp"

PhoneBook::PhoneBook( void ) :	_nrContacts(0) {}
PhoneBook::~PhoneBook( void ) {}	// Empty / default

/**
Adds a new contact to the phonebook.
If the phonebook has space (up to 8 contacts), it stores the contact at the next available index.
If the phonebook is full, it overwrites the oldest entry.

 @note 	The available indices range from 0 to 7 in the implementation,
		but represent entries 1 to 8 in the phonebook.
*/
void	PhoneBook::addContact( void )
{
	int	index;

	index = this->_nrContacts % 8;
	this->_contacts[index].addContact();
	this->_nrContacts++;
}

/**
Prints an overview of the contacts stored in the phonebook.

 @param nrContacts 	The number of contacts to display.
 @param contacts 	The array of contacts to display.
*/
static void	printContactList( int nrContacts, Contacts contacts[8] )
{
	int	index;

	std::cout << IDX_TABLE << std::endl;
	index = 0;
	while(index < nrContacts && index < 8)
	{
		contacts[index].printContactOverview(index);
		index++;
	}
	std::cout << std::endl;
}

/**
Prints the prompt for selecting a contact from the phonebook.

 @param	nrContacts 	The number of contacts in the phonebook.
*/
static void	printSelectionPrompt( int nrContacts )
{
	if (nrContacts == 1)
	{
		std::cout << SEL_CONTACT_1;
	}
	else
	{
		std::cout << SEL_CONTACT << YELLOW << std::min(nrContacts, 8) << "): " RESET;
	}
}

/**
Handles user input for selecting a contact from the phonebook.

 @return 	The index of the selected contact (zero-based);
			`-1` if the user input is empty;
			`-2` if the user input is '0' or not a number.
*/
static int getContactIndex( void )
{
	std::string	input;
	long 		indexSelect;
	char		*endPtr;

	std::getline(std::cin, input);

	// Check for EOF in user input (CTRL + D)
	if (std::cin.eof())
	{
		exitEOF();
	}

	// Check if input is empty (user pressed Enter without typing anything)
	if (input.empty())
	{
		return -1;
	}

	indexSelect = strtol(input.c_str(), &endPtr, 10);	// Convert input to `long`
	indexSelect -= 1;	// Adjust for zero-based index

	std::cout << "Index select is " << indexSelect << std::endl;

	// Check for invalid input
	if (*endPtr != '\0'			// Input contains non-numeric characters after the number
		|| indexSelect == -1)	// Input is '0' or starts with non-numeric chars (to distinguish return from empty input)
	{
		return -2;
	}

	return indexSelect;
}

/**
Prompts user to select a contact from the phonebook and displays respective
contact details.

 @param nrContacts 	The number of contacts in the phonebook.
 @param contacts 	The array of contacts in the phonebook.
*/
void selectAndDisplayContact( int nrContacts, Contacts contacts[8] )
{
	int indexSelect;

	while (true)
	{
		printSelectionPrompt(nrContacts);

		indexSelect = getContactIndex();

		if (indexSelect == -1)	// User input is empty
		{
			return ;
		}

		if (indexSelect >= 0 && indexSelect < nrContacts && indexSelect < 8) // Valid selection
		{
			contacts[indexSelect].printContactDetails();
			return ;
		}
		else	// Invalid selection -> select again
		{
			std::cout << INV_IDX << std::endl;
		}
	}
}

/**
Displays the list of contacts in the phonebook.

This function shows an overview of contacts (up to 8) stored in the phonebook
and prompts the user to select one by entering the corresponding index number.

The function handles invalid input and selection, providing appropriate feedback
to the user.
*/
void	PhoneBook::showContacts( void )
{
	// If there are no contacts added yet
	if (this->_nrContacts == 0)
	{
		std::cout << IDX_TABLE << std::endl << std::endl;
		std::cout << NO_CONTACTS << std::endl;
		return ;
	}

	printContactList(this->_nrContacts, this->_contacts);
	selectAndDisplayContact(this->_nrContacts, this->_contacts);
}
