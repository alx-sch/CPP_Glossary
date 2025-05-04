/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:39:30 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/04 19:17:45 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

template <typename T>
void	getStatus(const T& unit) {
	std::cout << "\nName: " << BLUE << unit.getName() << RESET << "\n";
	std::cout << "HP:   " << YELLOW << unit.getHitPoints() << RESET << "\n";
	std::cout << "EP:   " << YELLOW << unit.getEnergyPoints() << RESET << "\n";
	std::cout << "ATT:  " << YELLOW << unit.getAttackDamage() << RESET << "\n\n";
}

int	main() {

	{
		std::cout << YELLOW << "\n =================== \n";
		std::cout << " == ClapTrap Test == \n";
		std::cout << YELLOW << " =================== \n\n" << RESET;

		ClapTrap	clappy("Clappy");
		getStatus(clappy);

		ClapTrap	candy(clappy);
		getStatus(candy);

		ClapTrap	noName;
		getStatus(noName);
		
		noName = candy;
		getStatus(noName);

		clappy.attack("Evil Foe");
		getStatus(clappy);
		clappy.takeDamage(4);
		getStatus(clappy);
		clappy.beRepaired(2);
		getStatus(clappy);
		clappy.takeDamage(99);
		getStatus(clappy);
		clappy.attack("End Boss");
		clappy.beRepaired(999);
	}

	return 0;
}
