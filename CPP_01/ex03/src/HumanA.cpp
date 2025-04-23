/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:22:40 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 17:05:16 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <HumanA.hpp>

HumanA::HumanA(std::string nameProvided, Weapon &initialWeapon)
	: name(nameProvided), weapon(initialWeapon) {}
HumanA::~HumanA() {}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
