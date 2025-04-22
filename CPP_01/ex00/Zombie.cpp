/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:02:49 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/22 16:53:55 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string zombie_name ) : name( zombie_name ) {}

Zombie::~Zombie( void ) {
	std::cout << this->name << " is destroyed." << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
