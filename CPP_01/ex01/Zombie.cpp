/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:02:49 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 17:04:58 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::~Zombie() {
	std::cout << name << " is destroyed.\n";
}

void	Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string zombieName) {
	name = zombieName;
}
