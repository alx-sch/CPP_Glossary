/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:10:23 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/22 17:01:51 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string &nameProvided, Weapon &initial_weapon ) : name(nameProvided), weapon(initial_weapon) {}
HumanA::~HumanA( void ) {}

void HumanA::attack( void ) const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
