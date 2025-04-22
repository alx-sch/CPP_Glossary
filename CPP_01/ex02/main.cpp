/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:48:04 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/22 16:50:55 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void ) {
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string	&stringREF = string;

	// Print address
	std::cout << "string address is:   '" << &string << "'" << std::endl;
	std::cout << "stringPTR points to: '" << stringPTR << "'" << std::endl;
	std::cout << "stringREF refers to: '" << &stringREF << "'" << std::endl;

	std::cout << std::endl;

	// Print value
	std::cout << "string value is:     '" << string << "'" << std::endl;
	std::cout << "value via stringPTR: '" << *stringPTR << "'" << std::endl;
	std::cout << "value via stringREF: '" << stringREF << "'" << std::endl;

	return 0;
}
