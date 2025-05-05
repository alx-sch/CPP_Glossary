/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:03:15 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/05 02:33:02 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <FragTrap.hpp>
#include <colors.hpp>

// ORTHODOX CANONICAL FORM //

FragTrap::FragTrap() : ClapTrap() { // Initialize base class ClapTrap with default name
	_hitPoints = 100; // Re-define base values
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "FragTrap" << RESET 
	<< " default constructor called.\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100; // Re-define base values
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "FragTrap" << RESET
	<< " parameterized constructor called.\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "FragTrap" << RESET 
	<< " copy constructor called.\n";
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other); // Call base class assignment operator
	}
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "FragTrap" << RESET 
	<< " copy assignment operator called.\n";
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "🏁 " << BLUE << _name << RESET << ": " << GREEN << "FragTrap" << RESET
	<< " destructor called.\n";
}

/// GAME FUNCTIONS //

// FragTrap requests a high five from the user.
// It can only be used if it has more than 0 `_hitPoints`.
void	FragTrap::highFivesGuys() {
	if (_hitPoints > 0) {
		std::cout << "✋ " << BLUE << _name << RESET " requests a high five! *SMACK*\n";
	}
	else {
		std::cout << "☠️  " << BLUE << _name << RESET << " is kaputt! It can't lift a finger.\n";
	}
}
