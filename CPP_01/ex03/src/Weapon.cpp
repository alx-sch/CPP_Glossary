/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:13:52 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 17:04:36 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>

Weapon::Weapon(std::string typeProvided) : type(typeProvided) {}
Weapon::~Weapon() {}

std::string	Weapon::getType() {
	return type;
}

void	Weapon::setType(std::string newType) {
	type = newType;
}
