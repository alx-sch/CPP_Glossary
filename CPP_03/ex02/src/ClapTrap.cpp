/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:39:35 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/05 19:27:21 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

// ORTHODOX CANONICAL FORM //

ClapTrap::ClapTrap() 
	:	_name(_DEFAULT_NAME),
		_hitPoints(_DEFAULT_HIT_POINTS),
		_energyPoints(_DEFAULT_ENERGY_POINTS),
		_attackDamage(_DEFAULT_ATTACK_DAMAGE) {
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "ClapTrap" << RESET 
	<< " default constructor called.\n";
}

ClapTrap::ClapTrap(std::string name)
	:	_name(name),
		_hitPoints(_DEFAULT_HIT_POINTS),
		_energyPoints(_DEFAULT_ENERGY_POINTS),
		_attackDamage(_DEFAULT_ATTACK_DAMAGE) {
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "ClapTrap" << RESET
	<< " parameterized constructor called.\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) 
	:	_name(other._name),
		_hitPoints(other._hitPoints),
		_energyPoints(other._energyPoints),
		_attackDamage(other._attackDamage) {
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "ClapTrap" << RESET 
	<< " copy constructor called.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "ClapTrap" << RESET 
	<< " copy assignment operator called.\n";
	
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "🏁 " << BLUE << _name << RESET << ": " << GREEN << "ClapTrap" << RESET
	<< " destructor called.\n";
}

/// GAME FUNCTIONS //

// ClapTrap attacks the `target` (testing, not an interactive object) and causes
// `_attackDamage`, costing 1 `_energyPoint`.
// ClapTrap remains inactive if no `_hitPoints` or `_energyPoints` are left (0).
void	ClapTrap::attack(const std::string& target) {
	// HP and energy left?
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "⚔️  " << BLUE << _name << RESET << " attacks " << RED << target << RESET << 
		", causing " << YELLOW << _attackDamage << " damage" << RESET << "!\n";
		_energyPoints -= 1;
	}
	else { // NO HP or energy left! 
		std::cout << "☠️  " << BLUE << _name << RESET << " is kaputt! It can't attack.\n";
	}
}

// ClapTrap takes `amount` of damage, reducing its `_hitPoints`.
// If `amount` >= `_hitPoints`, ClapTrap is rendered inactive with 0 HP.
void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "🩸 " << BLUE << _name << RESET << " takes " << YELLOW << amount << " damage" << RESET <<"!\n";
	
	// Amount of damage less than current HP.
	if (amount < _hitPoints) {
		_hitPoints -= amount;	// Reduce HP by damage amount
		std::cout << "ℹ️  " << BLUE << _name << RESET << " got " << YELLOW << _hitPoints 
		<< " HP" << RESET " left.\n";
	}
	else { // Damage is greater than or equal to current HP -> dead!
		_hitPoints = 0;	// Set HP to 0, as it can't go negative.
		std::cout << "☠️  " << BLUE << _name << RESET << " got " << YELLOW << _hitPoints
		<< " HP" << RESET << " left. It's kaputt!\n";
	}
}

// ClapTrap restores `amount` of `_hitPoints`, costing 1 `_energyPoint`.
// Cannot repair if it has 0 `_hitPoints` or `_energyPoints`.
void	ClapTrap::beRepaired(unsigned int amount) {
	// HP and energy left?
	if (_hitPoints > 0 && _energyPoints > 0) {
		_hitPoints += amount;
		_energyPoints -= 1;
		std::cout << "💉 " << BLUE << _name << RESET << " repairs itself and gains " << YELLOW << amount
		<< " HP" << RESET << "!\n";
		std::cout << "ℹ️  " << BLUE << _name << RESET << " now has " << YELLOW << _hitPoints << " HP" << RESET << ".\n";
	}
	else { // NO HP or energy left! 
		std::cout << "☠️  " << BLUE << _name << RESET << " is kaputt! It can't repair itself.\n";
	}
}

// GETTERS //

std::string		ClapTrap::getName() const {
	return _name;
}

unsigned int	ClapTrap::getHitPoints() const {
	return _hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

unsigned int	ClapTrap::getAttackDamage() const {
	return _attackDamage;
}
