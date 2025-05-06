/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:03:15 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/06 16:38:59 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../include/FragTrap.hpp"
#include "../include/colors.hpp"

// Initialize default values

const unsigned int	FragTrap::DEFAULT_HIT_POINTS	= 100;
const unsigned int	FragTrap::DEFAULT_ENERGY_POINTS	= 100;
const unsigned int	FragTrap::DEFAULT_ATTACK_DAMAGE	= 30;

// ORTHODOX CANONICAL FORM //

FragTrap::FragTrap() : ClapTrap()
{
	hitPoints_ = DEFAULT_HIT_POINTS;
	energyPoints_ = DEFAULT_ENERGY_POINTS;
	attackDamage_ = DEFAULT_ATTACK_DAMAGE;
	
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "FragTrap"
				<< RESET << " default constructor called.\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints_ = DEFAULT_HIT_POINTS;
	energyPoints_ = DEFAULT_ENERGY_POINTS;
	attackDamage_ = DEFAULT_ATTACK_DAMAGE;
	
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "FragTrap"
				<< RESET << " parameterized constructor called.\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "FragTrap"
				<< RESET << " copy constructor called.\n";
}

FragTrap::~FragTrap()
{
	std::cout	<< "🏁 " << BLUE << name_ << RESET << ": " << GREEN << "FragTrap"
				<< RESET << " destructor called.\n";
}

FragTrap&	FragTrap::operator=(const FragTrap &other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "FragTrap"
				<< RESET << " copy assignment operator called.\n";
	
	return *this;
}

/// GAME FUNCTIONS //

/**
FragTrap's special ability: high five!
It costs 1 energy point, can only be used if unit has any hit points and energy points.
*/
void	FragTrap::highFivesGuys()
{
	if (hitPoints_ > 0 && energyPoints_ > 0) {
		energyPoints_ -= 1;
		std::cout	<< "✋ " << BLUE << name_ << RESET " requests a high five! *SMACK*\n";
	}
	else {
		std::cout	<< "☠️  " << BLUE << name_ << RESET << " is kaputt! It can't lift a finger.\n";
	}
}

// GETTERS //

unsigned int	FragTrap::getMaxHitPoints() const {
	return DEFAULT_HIT_POINTS;
}
