/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:00:51 by aschenk           #+#    #+#             */
/*   Updated: 2024/11/04 18:19:20 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/**
Exits the program gracefully when an end-of-file (EOF) condition is detected in
user input (CTRL + D).
*/
void	exitEOF( void )
{
	std::cout << std::endl << "Exiting." << std::endl;
	std::cout << BYE << std::endl;

	exit(0);
}
