/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:40:31 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/05 08:26:04 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ScavTrap.hpp>
#include <colors.hpp>

// ORTHODOX CANONICAL FORM //

ScavTrap::ScavTrap() : ClapTrap() { // Initialize base class ClapTrap with default name
	_hitPoints = 100; // Re-define base values
	_energyPoints = 50;
	_attackDamage = 20;
	
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "ScavTrap" << RESET 
	<< " default constructor called.\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100; // Re-define base values
	_energyPoints = 50;
	_attackDamage = 20;
	
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "ScavTrap" << RESET
	<< " parameterized constructor called.\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) { // Delegate copy constructor to ClapTrap
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "ScavTrap" << RESET 
	<< " copy constructor called.\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other); // Delegate copy assignment to ClapTrap
	}
	
	std::cout << "🐣 " << BLUE << _name << RESET << ": " << GREEN << "ScavTrap" << RESET 
	<< " copy assignment operator called.\n";
	
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "🏁 " << BLUE << _name << RESET << ": " << GREEN << "ScavTrap" << RESET
	<< " destructor called.\n";
}

/// GAME FUNCTIONS //

// ScavTrap attacks the `target` (testing, not an interactive object) and causes
// `_attackDamage`, costing 1 energy point.
// Cannot attack if it has 0 `_hitPoints` or `_energyPoints`.
void	ScavTrap::attack(const std::string& target) {
	// HP and energy left?
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "👀 " << BLUE << _name << RESET << " stares at " << RED << target << RESET << 
		" intensively, causing " << YELLOW << _attackDamage << " damage" << RESET << "!\n";
		_energyPoints -= 1;
	}
	else { // NO HP or energy left! 
		std::cout << "☠️  " << BLUE << _name << RESET << " is kaputt! It can't attack.\n";
	}
}

// ScavTrap enters Gate Keeper mode.
// It can only be used if it has more than 0 `_hitPoints`.
void	ScavTrap::guardGate() {
	if (_hitPoints > 0) {
		std::cout << "🛡️  " << BLUE << _name << RESET " is guarding the gate!\n";;
	}
	else {
		std::cout << "☠️  " << BLUE << _name << RESET << " is kaputt! It can't guard anything.\n";
	}
}


