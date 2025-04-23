/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:37:44 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 14:49:49 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <HumanB.hpp>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}
HumanB::~HumanB() {}

void	HumanB::attack() {
	if (!weapon)
		std::cout << name << " tries to attack but has no weapon!\n";
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon) {
	weapon =  &new_weapon;
}
