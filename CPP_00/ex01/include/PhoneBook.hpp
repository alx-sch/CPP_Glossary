#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class PhoneBook
{
	public:

		PhoneBook( void );
		~PhoneBook( void );

		void		addContact( void );		// Add a contact to the phonebook
		void		showContacts( void );	// Show contacts in the phonebook

	private:

		int			_nrContacts;			// Number of contacts in the phonebook
		Contacts	_contacts[8];			// Array of contacts
};

#endif
