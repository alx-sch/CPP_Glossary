/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:01:16 by aschenk           #+#    #+#             */
/*   Updated: 2024/11/06 17:09:33 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
The primary inclusion point for the program, containing all necessary headers and utility functions.
*/

# include <stdlib.h>	// for exit(), atoi()
# include <iostream>	// for std::cout, std::cin
# include <iomanip>		// for std:setw()
# include <sstream>		// for std::ostringstream

# include "config.hpp"
# include "PhoneBook.hpp"
# include "Contacts.hpp"

// utils.cpp

void	exitEOF( void );
