/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:39:35 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/29 16:23:54 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

// ORTHODOX CANONICAL FORM //

ClapTrap::ClapTrap() 
	:	_name("NoName"),
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(10) {}

ClapTrap::ClapTrap(std::string name)
	:	_name(name),
		_hitPoints(10),
		_energyPoints(10),
		_attackDamage(10) {}

ClapTrap::ClapTrap(const ClapTrap& other) 
	:	_name(other._name),
		_hitPoints(other._hitPoints),
		_energyPoints(other._energyPoints),
		_attackDamage(other._attackDamage) {}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Deconstr contr called\n";
}
