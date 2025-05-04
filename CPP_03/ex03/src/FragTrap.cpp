/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:03:15 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/04 17:23:49 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <FragTrap.hpp>

// ORTHODOX CANONICAL FORM //

FragTrap::FragTrap() { // Initialize base class ClapTrap with default name
	_hitPoints = _hitPointsInit; // Re-define base values
	_energyPoints = _energyPoints;
	_attackDamage = _attackDamageInit;
	std::cout << "FragTrap " << _name << ": Default constructor called.\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name + "_clap_name"){
	(void)name; // Avoid unused variable warning
	_hitPoints = 100; // Re-define base values
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << ": Parameterized constructor called.\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << _name << ": Copy constructor called.\n";
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap " << _name << ": Copy assignment operator called.\n";
	if (this != &other) {
		ClapTrap::operator=(other); // Call base class assignment operator
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << ": Destructor called.\n";
}

/// GAME FUNCTIONS //

// FragTrap requests a high five from the user.
// It can only be used if it has more than 0 `_hitPoints`.
void	FragTrap::highFivesGuys() {
	if (_hitPoints > 0) {
		std::cout << "FragTrap " << _name << " requests a high five! ✋😄\n";
	}
	else {
		std::cout << "FragTrap " << _name << " is kaputt and can't lift it's hands anymore!\n";
	}
}
