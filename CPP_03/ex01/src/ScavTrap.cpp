/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:40:31 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/02 14:55:18 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ScavTrap.hpp>

// ORTHODOX CANONICAL FORM //

ScavTrap::ScavTrap() : ClapTrap() { // Initialize base class ClapTrap with default name
	_hitPoints = 100; // Re-define base values
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << ": Default constructor called.\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100; // Re-define base values
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << ": Parameterized (name) constructor called.\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap " << _name << ": Copy constructor called.\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap " << _name << ": Copy assignment operator called.\n";
	if (this != &other) {
		ClapTrap::operator=(other); // Call base class assignment operator
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << ": Destructor called.\n";
}

/// GAME FUNCTIONS //

// ScavTrap attacks the `target` (testing, not an interactive object) and causes
// `_attackDamage`, costing 1 energy point.
// Cannot attack if it has 0 `_hitPoints` or `_energyPoints`.
void	ScavTrap::attack(const std::string& target) {
	// HP and energy left?
	if (_hitPoints > 0 && _energyPoints > 0) {
		_energyPoints -= 1;
		std::cout << "ScavTrap " << _name << " stares at " << target
		<< " intensively, causing " << _attackDamage << " points of damage!\n";
	}
	else { // NO HP or energy left! 
		std::cout << "ClapTrap " << _name << " is kaputt! It can't attack.\n";
	}
}

// ScavTrap enters Gate Keeper mode.
// It can only be used if it has more than 0 `_hitPoints`.
void	ScavTrap::guardGate() {
	if (_hitPoints > 0) {
		std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode.\n";
	}
	else {
		std::cout << "ScavTrap " << _name << " is kaputt and can't guard anything anymore!\n";
	}
}


