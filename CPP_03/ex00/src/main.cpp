/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:39:30 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/05 21:08:03 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

// Prints the name, HP, EP, and attack damage of a unit.
// The unit must have getName(), getHitPoints(), getEnergyPoints(), and getAttackDamage().
template <typename T>
void	getStatus(const T& unit) {
	std::cout << "Name: " << BLUE << unit.getName() << RESET << "\n";
	std::cout << "HP:   " << YELLOW << unit.getHitPoints() << RESET << "\n";
	std::cout << "EP:   " << YELLOW << unit.getEnergyPoints() << RESET << "\n";
	std::cout << "ATT:  " << YELLOW << unit.getAttackDamage() << RESET << "\n";
}

int	main() {

	{ // ClapTrap Test
		std::cout << MAGENTA << "\n=================== \n";
		std::cout << "== ClapTrap Test == \n";
		std::cout << "=================== \n\n" << RESET;

		std::cout << YELLOW << "-- CONSTRUCTION --\n\n" << RESET;
		
		std::cout << GREY << "ClapTrap clappy(\"Clappy\");\n" << RESET;
		ClapTrap	clappy("Clappy");
		std::cout << GREY << "\ngetStatus(clappy);\n" << RESET;
		getStatus(clappy);

		std::cout << GREY << "\nclappy.takeDamage(4);\n" << RESET;
		clappy.takeDamage(4);

		std::cout << GREY << "\nClapTrap candy(clappy);\n" << RESET;
		ClapTrap	candy(clappy);
		std::cout << GREY << "\ngetStatus(candy);\n" << RESET;
		getStatus(candy);

		std::cout << GREY << "\ncandy.takeDamage(4);\n" << RESET;
		candy.takeDamage(4);

		std::cout << GREY << "\nClapTrap noName;\n" << RESET;
		ClapTrap	noName;
		std::cout << GREY << "\ngetStatus(noName);\n" << RESET;
		getStatus(noName);
		
		std::cout << GREY << "\nnoName = candy;\n" << RESET;
		noName = candy;
		std::cout << GREY << "\ngetStatus(noName);\n" << RESET;
		getStatus(noName);

		std::cout << YELLOW << "\n-- ACTIONS --\n\n" << RESET;

		std::cout << GREY << "ClapTrap 'clappy' in battle:\n" << RESET;
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

		std::cout << YELLOW << "\n-- DECONSTRUCTION --\n\n" << RESET;
	}

	return 0;
}
