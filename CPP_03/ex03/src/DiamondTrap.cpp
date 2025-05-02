/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:43:15 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/02 16:59:12 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
ClapTrap is the base class.
FragTrap and ScavTrap inherit from ClapTrap.
DiamondTrap inherits from both FragTrap and ScavTrap.
*/

#include <iostream>
#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap()
	:	ScavTrap("NoName_clap_name"), // To be passed to ClapTrap
		FragTrap("NoName_clap_name"),
		_name("NoName") {
	//this->_hitPoints = FragTrap::_hitPoints; // Pull from FragTrap / ScavTrap defaults
	//this->_energyPoints = ScavTrap::_energyPoints;
	//this->_attackDamage = FragTrap::_attackDamage;
	
	std::cout << "DiamondTrap " << _name << ": Default constructor called.\n";
}

// DiamondTrap::DiamondTrap(const std::string name)
// 	:	FragTrap(name), 
// 		ScavTrap(name),
// 		_name(name) {
// 	this->_hitPoints = FragTrap::_hitPoints;
// 	this->_energyPoints = ScavTrap::_energyPoints;
// 	this->_attackDamage = FragTrap::_attackDamage;

// 	std::cout << "DiamondTrap :" << name << ": Parameterized constructor called.\n";
// }

// DiamondTrap::DiamondTrap(const DiamondTrap& other)
// 	:	FragTrap(other),						// Copy FragTrap
// 		ScavTrap(other),						// Copy ScavTrap
// 		_name(other._name) {					// Copy DiamondTrap's own name
// 	this->_hitPoints = other._hitPoints;
// 	this->_energyPoints = other._energyPoints;
// 	this->_attackDamage = other._attackDamage;
	
// 	std::cout << "DiamondTrap " << _name << ": Copy constructor called.\n";
// }

// DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
// 	if (this != &other) {  // Self-assignment check
// 		ClapTrap::operator=(other);  // Copy the ClapTrap part
// 		FragTrap::operator=(other);  // Copy the FragTrap part
// 		ScavTrap::operator=(other);  // Copy the ScavTrap part

// 		this->_name = other._name;  // Copy DiamondTrap's specific name
// 		this->_hitPoints = other._hitPoints;   // Copy hitPoints
// 		this->_energyPoints = other._energyPoints; // Copy energyPoints
// 		this->_attackDamage = other._attackDamage; // Copy attackDamage

// 		std::cout << "DiamondTrap " << _name << ": Copy assignment operator called.\n";
// 	}
// 	return *this;
// }

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << ": Destructor called.\n";
}
