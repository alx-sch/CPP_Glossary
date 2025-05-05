/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:43:15 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/05 19:29:01 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
ClapTrap is the base class.
FragTrap and ScavTrap inherit from ClapTrap.
DiamondTrap inherits from both FragTrap and ScavTrap.
*/

#include <iostream>
#include "DiamondTrap.hpp"
#include "colors.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(_DEFAULT_NAME + "_clap_name") { // Passing custom name to ClapTrap; calling ScavTrap/FragTrap constructor is optional
	this->_name = _DEFAULT_NAME; // DiamondTrap's own name

	// Pull from FragTrap / ScavTrap defaults
	this->_hitPoints = FragTrap::_DEFAULT_HIT_POINTS;
	this->_energyPoints = ScavTrap::_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = FragTrap::_DEFAULT_ATTACK_DAMAGE;
	
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "DiamondTrap" << RESET 
	<< " default constructor called.\n";
}

DiamondTrap::DiamondTrap(std::string name) :ClapTrap(name + "_clap_name") { // Passing custom name to ClapTrap; calling ScavTrap/FragTrap constructor is optional
	this->_name = name;  // DiamondTrap's own name

	// Pull from FragTrap / ScavTrap defaults
	this->_hitPoints = FragTrap::_DEFAULT_HIT_POINTS;
	this->_energyPoints = ScavTrap::_DEFAULT_ENERGY_POINTS;
	this->_attackDamage = FragTrap::_DEFAULT_ATTACK_DAMAGE;
	
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "DiamondTrap" << RESET
	<< " parameterized constructor called.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	:	ClapTrap(other),
		ScavTrap(other),
		FragTrap(other) {
	_name = other._name;  // Assign DiamondTrap-specific name
	
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "DiamondTrap" << RESET 
	<< " copy constructor called.\n";
}

// No need to call ScavTrap/FragTrap copy assignment operators:
// All data members to be updated (states) are already inherited from ClapTrap.
// Special abilities are already present in instance to be re-assigned (other than _name).
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {  // Self-assignment check
		ClapTrap::operator=(other);  // Copy the ClapTrap part
		_name = other._name;  // Assign DiamondTrap-specific name
	}
	
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "DiamondTrap" << RESET 
	<< " copy assignment operator called.\n";
	
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "🏁 " << BLUE << _name << RESET << ": " << GREEN << "DiamondTrap" << RESET
	<< " destructor called.\n";
}

/// GAME FUNCTIONS //

// Displays the DiamondTrap's own name (_name) and the inherited ClapTrap name (ClapTrap::_name).
void	DiamondTrap::whoAmI() {
	if (_hitPoints > 0) {
		std::cout << "💎 " << BLUE << _name << RESET << ": " << "My " << GREEN << "DiamondTrap" << RESET 
		<< " name is: '" << YELLOW << _name << RESET << "'.\n";
		std::cout << "💎 " << BLUE << _name << RESET << ": " << "My " << GREEN << "ClapTrap" << RESET 
		<< " name is:    '" << YELLOW << ClapTrap::_name << RESET << "'.\n";
	}
	else {
		std::cout << "☠️  " << BLUE << _name << RESET << " is kaputt! It doesn't even know who it is.\n";
	}
}

// GETTERS //

/**
Returns the DiamondTrap's own name (_name) instead of the inherited ClapTrap name.

This override is necessary because ClapTrap also has a _name member, and its
getName() returns that base class member (_name = "<name>_clap_name"). Without
 overriding, any call to getName() (e.g., in getStatus()) would return the ClapTrap
name instead of DiamondTrap's actual name.
*/
std::string	DiamondTrap::getName() const {
	return this->_name;
}
