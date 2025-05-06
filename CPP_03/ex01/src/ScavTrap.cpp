/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:40:31 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/06 19:45:38 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../include/ScavTrap.hpp"
#include "../include/colors.hpp"

// Initialize default values

const unsigned int	ScavTrap::DEFAULT_HIT_POINTS	= 100;
const unsigned int	ScavTrap::DEFAULT_ENERGY_POINTS	= 50;
const unsigned int	ScavTrap::DEFAULT_ATTACK_DAMAGE	= 20;

// ORTHODOX CANONICAL FORM //

ScavTrap::ScavTrap() : ClapTrap()
{ 
	hitPoints_ = DEFAULT_HIT_POINTS;
	energyPoints_ = DEFAULT_ENERGY_POINTS;
	attackDamage_ = DEFAULT_ATTACK_DAMAGE;
	
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "ScavTrap"
				<< RESET << " default constructor called.\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints_ = DEFAULT_HIT_POINTS;
	energyPoints_ = DEFAULT_ENERGY_POINTS;
	attackDamage_ = DEFAULT_ATTACK_DAMAGE;
	
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "ScavTrap"
				<< RESET << " parameterized constructor called.\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "ScavTrap"
				<< RESET << " copy constructor called.\n";
}

ScavTrap::~ScavTrap()
{
	std::cout	<< "🏁 " << BLUE << name_ << RESET << ": " << GREEN << "ScavTrap"
				<< RESET << " destructor called.\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other) {
		ClapTrap::operator=(other); 
	}

	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "ScavTrap"
				<< RESET << " copy assignment operator called.\n";
	
	return *this;
}

/// GAME FUNCTIONS //

/**
SvacTrap's special attack: Staring!
Trap unit attacks the `target` (testing, not an interactive object) and causing
damage equal to its attack damage. It costs 1 energy point.
Trap unit remains inactive if no hit points or energy points are left (0).
*/
void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints_ > 0 && energyPoints_ > 0) {
		std::cout	<< "👀  " << BLUE << name_ << RESET << " starte at " << RED
					<< target << RESET << " intesively, causing " << YELLOW
					<< attackDamage_ << " damage" << RESET << "!\n";
		energyPoints_ -= 1;
	}
	else {
		std::cout	<< "☠️  " << BLUE << name_ << RESET << " is kaputt! It can't attack.\n";
	}
}

/**
Trap unit enters Gate Keeper mode.
It can only be used if it has hit points and energy points left. It costs 1 energy point.
*/
void	ScavTrap::guardGate() {
	if (hitPoints_ > 0 && energyPoints_ > 0) {
		energyPoints_ -= 1;
		std::cout << "🛡️  " << BLUE << name_ << RESET " is guarding the gate!\n";
	}
	else {
		std::cout << "☠️  " << BLUE << name_ << RESET << " is kaputt! It can't guard anything.\n";
	}
}

// GETTERS //

unsigned int	ScavTrap::getMaxHitPoints() const {
	return DEFAULT_HIT_POINTS;
}
