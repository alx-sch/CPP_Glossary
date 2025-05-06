/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:39:35 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/06 19:58:37 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../include/ClapTrap.hpp"
#include "../include/colors.hpp"

// Initialize default values

const std::string	ClapTrap::DEFAULT_NAME			= "NoName";
const unsigned int	ClapTrap::DEFAULT_HIT_POINTS	= 10;
const unsigned int	ClapTrap::DEFAULT_ENERGY_POINTS	= 10;
const unsigned int	ClapTrap::DEFAULT_ATTACK_DAMAGE	= 0;

// ORTHODOX CANONICAL FORM //

ClapTrap::ClapTrap() 
	:	name_(DEFAULT_NAME),
		hitPoints_(DEFAULT_HIT_POINTS),
		energyPoints_(DEFAULT_ENERGY_POINTS),
		attackDamage_(DEFAULT_ATTACK_DAMAGE)
{
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "ClapTrap"
				<< RESET << " default constructor called.\n";
}

ClapTrap::ClapTrap(std::string name)
	:	name_(name),
		hitPoints_(DEFAULT_HIT_POINTS),
		energyPoints_(DEFAULT_ENERGY_POINTS),
		attackDamage_(DEFAULT_ATTACK_DAMAGE)
{
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "ClapTrap"
				<< RESET << " parameterized constructor called.\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) 
	:	name_(other.name_),
		hitPoints_(other.hitPoints_),
		energyPoints_(other.energyPoints_),
		attackDamage_(other.attackDamage_)
{
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "ClapTrap"
				<< RESET << " copy constructor called.\n";
}

ClapTrap::~ClapTrap()
{
	std::cout	<< "🏁 " << BLUE << name_ << RESET << ": " << GREEN << "ClapTrap"
				<< RESET << " destructor called.\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other) {
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "ClapTrap"
				<< RESET << " copy assignment operator called.\n";
	
	return *this;
}

/// GAME FUNCTIONS //

/**
Trap unit attacks the `target` (testing, not an interactive object) and causing
damage equal to its attack damage. It costs 1 energy point.
Trap unit remains inactive if no hit points or energy points are left (0).
*/
void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints_ > 0 && energyPoints_ > 0) {
		std::cout	<< "⚔️  " << BLUE << name_ << RESET << " attacks " << RED << target
					<< RESET << ", causing " << YELLOW << attackDamage_ << " damage"
					<< RESET << "!\n";
		energyPoints_ -= 1;
	}
	else {
		std::cout	<< "☠️  " << BLUE << name_ << RESET << " is kaputt! It can't attack.\n";
	}
}

/**
Trap unit takes damage equal to `amount`, reducing its hit points accordingly.
If the damage is greater than or equal to its current hit points,it is rendered inactive with 0 HP.
*/
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout	<< "🩸 " << BLUE << name_ << RESET << " takes " << YELLOW << amount
				<< " damage" << RESET <<"!\n";
	
	if (amount < hitPoints_) {
		hitPoints_ -= amount;
		std::cout	<< "ℹ️  " << BLUE << name_ << RESET << " got " << YELLOW << hitPoints_ 
					<< " HP" << RESET " left.\n";
	}
	else {
		hitPoints_ = 0;
		std::cout	<< "🚫 " << BLUE << name_ << RESET << " got " << YELLOW << hitPoints_
					<< " HP" << RESET << " left. It's kaputt!\n";
	}
}

/**
Trap unit restores its hit points by `amount`, costing 1 energy point.
If the unit is already at max HP, it does not restore any hit points.
Cannot restore hit points if no hit points or energy points are left (0).
*/
void	ClapTrap::beRepaired(unsigned int amount)
{
	bool	fullRepair = false;
	if (hitPoints_ > 0 && energyPoints_ > 0) {
		if (hitPoints_ == getMaxHitPoints()) {
			std::cout	<< "💉 " << BLUE << name_ << RESET << " is already at max HP. No repair needed!\n";
			return ;
		}
		if (hitPoints_ + amount >= getMaxHitPoints()) {
			amount = getMaxHitPoints() - hitPoints_;
			fullRepair = true;
		}
		hitPoints_ += amount;
		energyPoints_ -= 1;

		if (fullRepair) {
			std::cout	<< "💉 " << BLUE << name_ << RESET << " repairs itself " << GREEN
						<< "completely" << RESET << " and gains " << YELLOW << amount
						<< " HP" << RESET << "!\n";
		}
		else {
			std::cout	<< "💉 " << BLUE << name_ << RESET << " repairs itself and gains "
						<< YELLOW << amount << " HP" << RESET << "!\n";
		}
		std::cout		<< "ℹ️  " << BLUE << name_ << RESET << " now has " << YELLOW << hitPoints_ 
						<< " HP" << RESET << ".\n";
	}
	else { 
		std::cout	<< "☠️  " << BLUE << name_ << RESET << " is kaputt! It can't repair itself.\n";
	}
}

// GETTERS //

std::string		ClapTrap::name() const {
	return name_;
}

unsigned int	ClapTrap::hitPoints() const {
	return hitPoints_;
}

unsigned int	ClapTrap::energyPoints() const {
	return energyPoints_;
}

unsigned int	ClapTrap::attackDamage() const {
	return attackDamage_;
}

unsigned int	ClapTrap::getMaxHitPoints() const {
	return DEFAULT_HIT_POINTS;
}
