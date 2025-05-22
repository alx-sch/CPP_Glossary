#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include "main.hpp"

class	Contacts
{
	public:

		Contacts( void );
		~Contacts( void );

		void	addContact( void );							// Add a contact
		void	printContactOverview( int index ) const;	// Print an overview for this contact
		void	printContactDetails( void ) const;				// Print details for this contact

	private:

		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif
