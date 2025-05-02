/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:39:35 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/02 14:53:46 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

// ORTHODOX CANONICAL FORM //

ClapTrap::ClapTrap() 
	:	_name("NoName"),
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(0) {
	std::cout << _name << ": Default constructor called.\n";
}

ClapTrap::ClapTrap(std::string name)
	:	_name(name),
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(0) {
	std::cout << _name << ": Parameterized (name) constructor called.\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) 
	:	_name(other._name),
		_hitPoints(other._hitPoints),
		_energyPoints(other._energyPoints),
		_attackDamage(other._attackDamage) {
	std::cout << _name << ": Copy constructor called.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	std::cout << _name << ": Copy assignment operator called.\n";
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << _name << ": Destructor called.\n";
}

/// GAME FUNCTIONS //

// ClapTrap attacks the `target` (testing, not an interactive object) and causes
// `_attackDamage`, costing 1 `_energyPoint`.
// ClapTrap remains inactive if no `_hitPoints` or `_energyPoints` are left (0).
void	ClapTrap::attack(const std::string& target) {
	// HP and energy left?
	if (_hitPoints > 0 && _energyPoints > 0) {
		_energyPoints -= 1;
		std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!\n";
	}
	else { // NO HP or energy left! 
		std::cout << "ClapTrap " << _name << " is kaputt! It can't attack.\n";
	}
}

// ClapTrap takes `amount` of damage, reducing its `_hitPoints`.
// If `amount` >= `_hitPoints`, ClapTrap is rendered inactive with 0 HP.
void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!\n";
	
	// Amount of damage less than current HP.
	if (amount < _hitPoints) {
		_hitPoints -= amount;	// Reduce HP by damage amount
		std::cout << "ClapTrap " << _name << " still got " << _hitPoints
		<< " hit points left.\n";
	}
	else { // Damage is greater than or equal to current HP -> dead!
		_hitPoints = 0;	// Set HP to 0, as it can't go negative.
		std::cout << "ClapTrap " << _name << " has no more hit points left and is kaputt!\n";
	}
}

// ClapTrap restores `amount` of `_hitPoints`, costing 1 `_energyPoint`.
// Cannot repair if it has 0 `_hitPoints` or `_energyPoints`.
void	ClapTrap::beRepaired(unsigned int amount) {
	// HP and energy left?
	if (_hitPoints > 0 && _energyPoints > 0) {
		_hitPoints += amount;
		_energyPoints -= 1;
		std::cout << "ClapTrap " << _name << " repairs itself and gains " << amount
		<< " hit points!\n";
		std::cout << "ClapTrap " << _name << " now has " << _hitPoints << " hit points.\n";
	}
	else { // NO HP or energy left! 
		std::cout << "ClapTrap " << _name << " is kaputt! It can't repair itself.\n";
	}
}
