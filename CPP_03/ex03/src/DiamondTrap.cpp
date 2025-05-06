/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:43:15 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/06 11:37:22 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../include/DiamondTrap.hpp"
#include "../include/colors.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(DEFAULT_NAME + "_clap_name")
{
	this->name_ = DEFAULT_NAME;
	this->hitPoints_ = FragTrap::DEFAULT_HIT_POINTS;
	this->energyPoints_ = ScavTrap::DEFAULT_ENERGY_POINTS;
	this->attackDamage_ = FragTrap::DEFAULT_ATTACK_DAMAGE;
	
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "DiamondTrap"
				<< RESET << " default constructor called.\n";
}

DiamondTrap::DiamondTrap(std::string name) :ClapTrap(name + "_clap_name")
{
	this->name_ = name;
	this->hitPoints_ = FragTrap::DEFAULT_HIT_POINTS;
	this->energyPoints_ = ScavTrap::DEFAULT_ENERGY_POINTS;
	this->attackDamage_ = FragTrap::DEFAULT_ATTACK_DAMAGE;
	
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "DiamondTrap"
				<< RESET << " parameterized constructor called.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	:	ClapTrap(other),
		ScavTrap(other),
		FragTrap(other)
{
	name_ = other.name_;
	
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "DiamondTrap"
				<< RESET << " copy constructor called.\n";
}

/**
No need to call ScavTrap/FragTrap copy assignment operators:
All data members to be updated (states) are already inherited from ClapTrap.
Special abilities are already present in instance to be re-assigned.
*/
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
		name_ = other.name_;
	}

	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "DiamondTrap"
				<< RESET << " copy assignment operator called.\n";
	
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout	<< "🏁 " << BLUE << name_ << RESET << ": " << GREEN << "DiamondTrap"
				<< RESET << " destructor called.\n";
}

/// GAME FUNCTIONS //

/**
DiamondTrap's special ability: it can tell its own name and the name of its base class (ClapTrap).
It costs 1 energy point to use this ability. If the unit has no hit points or energy points,
it cannot use this ability.
*/
void	DiamondTrap::whoAmI()
{
	if (hitPoints_ > 0 && energyPoints_ > 0) {
		std::cout	<< "💎 " << BLUE << name_ << RESET << ": " << "My " << GREEN << "DiamondTrap"
					<< RESET << " name is: '" << YELLOW << name_ << RESET << "'.\n"
					<< "💎 " << BLUE << name_ << RESET << ": " << "My " << GREEN << "ClapTrap"
					<< RESET << " name is:    '" << YELLOW << ClapTrap::name_ << RESET << "'.\n";
		energyPoints_ -= 1;
	}
	else {
		std::cout	<< "☠️  " << BLUE << name_ << RESET << " is kaputt! It doesn't even know who it is.\n";
	}
}

// GETTERS //

/**
Returns the DiamondTrap's own name instead of the inherited ClapTrap name.

This override is necessary because ClapTrap also has a name_ member, and its
name() returns the base class member (name_ = "<name>_clap_name").
*/
std::string	DiamondTrap::name() const {
	return name_;
}
