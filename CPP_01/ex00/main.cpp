/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:57:49 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 13:51:48 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main() {
	Zombie*	z = newZombie("Heap");

	z->announce();
	randomChump("Stack");
	delete z;

	return 0;
}
