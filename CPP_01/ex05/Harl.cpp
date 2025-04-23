/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:13:08 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 17:14:28 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

void	Harl::debug() {
	std::cout << MAGENTA << "[DEBUG] " << RESET << "This is debug output.\n";
}

void	Harl::info() {
	std::cout << BLUE << "[INFO] " << RESET << "This is info output.\n";
}

void	Harl::warning() {
	std::cerr << YELLOW << "[WARNING] " << RESET << "This is warning output.\n";
}

void	Harl::error() {
	std::cerr << RED << "[ERROR] " << RESET << "This is error output.\n";
}

void	Harl::complain(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};  // Fixed array of strings, representing the levels of complaints.

	// Array of pointers to member functions of `Harl`
    // `::*` tells the compiler that the function ptr is a member of `Harl`
	void (Harl::*function_ptrs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	// Calculate the number of levels dynamically
	size_t	levelCount = sizeof(levels) / sizeof(levels[0]);

	bool	levelFound = false; // Flag to check if the level is valid

	for (size_t i = 0; i < levelCount; ++i) {
		if(level == levels[i]) {
			// `this` is used to call the member function
            // Calls the member function pointed by `function_ptrs[i]` using the `this` pointer
			(this->*function_ptrs[i])(); // Dereferences the pointer to the member function and calls it
			levelFound = true;
			break;
		}
	}

	if (!levelFound){
		std::cerr << RED << "Invalid level: " << level << RESET << std::endl;
	}
}
