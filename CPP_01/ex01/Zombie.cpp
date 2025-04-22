/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:02:49 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/22 14:21:40 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void ) {}

Zombie::~Zombie( void ) {
	std::cout << this->name << " is destroyed." << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string zombie_name ) {
	this->name = zombie_name;
}
