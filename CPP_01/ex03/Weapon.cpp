/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:13:52 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/22 16:58:06 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Contructor with weapon provided
Weapon::Weapon( std::string typeProvided ) : type( typeProvided ) {}

Weapon::~Weapon( void ) {}

std::string	Weapon::getType( void ) {
	return type;
}

void	Weapon::setType( std::string newType ) {
	type = newType;
}
