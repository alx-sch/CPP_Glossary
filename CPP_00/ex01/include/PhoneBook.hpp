/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:49:38 by aschenk           #+#    #+#             */
/*   Updated: 2024/11/06 16:46:07 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
