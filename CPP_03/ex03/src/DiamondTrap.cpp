/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:43:15 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/05 19:08:49 by aschenk          ###   ########.fr       */
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

DiamondTrap::DiamondTrap() 
	:	ClapTrap("NoName_clap_name"),	// Initialize ClapTrap with default name
		_name("NoName") { 				// Set _name specifically for DiamondTrap
	this->_name = "NoName";
	this->_hitPoints = FragTrap::_hitPoints; // Pull from FragTrap / ScavTrap defaults
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "DiamondTrap" << RESET 
	<< " default constructor called.\n";
}

DiamondTrap::DiamondTrap(std::string name)
	:	ClapTrap(name + "_clap_name"),	// Initialize ClapTrap with modified name
		ScavTrap(name),					// Initialize ScavTrap
		FragTrap(name),					// Initialize FragTrap
		_name(name) {					// Set _name specifically for DiamondTrap
	this->_hitPoints = FragTrap::_hitPoints;  // Pull from FragTrap
	this->_energyPoints = ScavTrap::_energyPoints; // Pull from ScavTrap
	this->_attackDamage = FragTrap::_attackDamage;  // Pull from FragTrap

	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "DiamondTrap" << RESET
	<< " parameterized constructor called.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	:	ClapTrap(other), ScavTrap(other), FragTrap(other)					// Copy FragTrap
		 {					// Copy DiamondTrap's own name
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "DiamondTrap" << RESET 
	<< " copy constructor called.\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {  // Self-assignment check
		ClapTrap::operator=(other);  // Copy the ClapTrap part
		FragTrap::operator=(other);  // Copy the FragTrap part
		ScavTrap::operator=(other);  // Copy the ScavTrap part

		this->_name = other._name;  // Copy DiamondTrap's specific name
		this->_hitPoints = other._hitPoints;   // Copy hitPoints
		this->_energyPoints = other._energyPoints; // Copy energyPoints
		this->_attackDamage = other._attackDamage; // Copy attackDamage
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
	std::cout << "💎 " << BLUE << _name << RESET << ": " << "My " << GREEN << "DiamondTrap" << RESET 
	<< " name is: '" << YELLOW << _name << RESET << "'.\n";
	std::cout << "💎 " << BLUE << _name << RESET << ": " << "My " << GREEN << "ClapTrap" << RESET 
	<< " name is:    '" << YELLOW << ClapTrap::_name << RESET << "'.\n";
}
