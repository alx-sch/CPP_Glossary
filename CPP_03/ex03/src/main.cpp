/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:35:51 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/05 08:43:23 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ClapTrap.hpp>
#include <ScavTrap.hpp>
#include <FragTrap.hpp>
#include <DiamondTrap.hpp>
#include <colors.hpp>

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

		std::cout << YELLOW << "CONSTRUCTION\n\n" << RESET;
		
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

		std::cout << YELLOW << "\nACTIONS\n\n" << RESET;

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

		std::cout << YELLOW << "\nDECONSTRUCTION\n\n" << RESET;
	}	
	{ // ScavTrap Test
		std::cout << MAGENTA << "\n=================== \n";
		std::cout << "== ScavTrap Test == \n";
		std::cout << "=================== \n\n" << RESET;

		std::cout << YELLOW << "CONSTRUCTION\n\n" << RESET;
		
		std::cout << GREY << "ScavTrap scavvy(\"Scavvy\");\n" << RESET;
		ScavTrap	scavvy("Scavvy");
		std::cout << GREY << "\ngetStatus(scavvy);\n" << RESET;
		getStatus(scavvy);

		std::cout << GREY << "\nscavvy.takeDamage(4);\n" << RESET;
		scavvy.takeDamage(4);

		std::cout << GREY << "\nScavTrap scavvyCpy(scavvy);\n" << RESET;
		ScavTrap	scavvyCpy(scavvy);
		std::cout << GREY << "\ngetStatus(scavvyCpy);\n" << RESET;
		getStatus(scavvyCpy);

		std::cout << GREY << "\nscavvyCpy.takeDamage(4);\n" << RESET;
		scavvyCpy.takeDamage(4);

		std::cout << GREY << "\nScavTrap noName;\n" << RESET;
		ScavTrap	noName;
		std::cout << GREY << "\ngetStatus(noName);\n" << RESET;
		getStatus(noName);
		
		std::cout << GREY << "\nnoName = scavvy;\n" << RESET;
		noName = scavvy;
		std::cout << GREY << "\ngetStatus(noName);\n" << RESET;
		getStatus(noName);

		std::cout << YELLOW << "\nACTIONS\n\n" << RESET;

		scavvy.attack("Evil Foe");
		getStatus(scavvy);
		scavvy.takeDamage(4);
		getStatus(scavvy);
		scavvy.beRepaired(2);
		getStatus(scavvy);
		scavvy.guardGate();
		scavvy.takeDamage(99);
		getStatus(scavvy);
		scavvy.attack("End Boss");
		scavvy.guardGate();
		scavvy.beRepaired(999);

		std::cout << YELLOW << "\nDECONSTRUCTION\n\n" << RESET;
	}
	{ // FragTrap Test
		std::cout << MAGENTA << "\n=================== \n";
		std::cout << "== FragTrap Test == \n";
		std::cout << "=================== \n\n" << RESET;

		std::cout << YELLOW << "CONSTRUCTION\n\n" << RESET;
		
		std::cout << GREY << "FragTrap fraggy(\"Fraggy\");\n" << RESET;
		FragTrap	fraggy("Fraggy");
		std::cout << GREY << "\ngetStatus(fraggy);\n" << RESET;
		getStatus(fraggy);

		std::cout << GREY << "\nfraggy.takeDamage(4);\n" << RESET;
		fraggy.takeDamage(4);

		std::cout << GREY << "\nFragTrap fraggyCpy(fraggy);\n" << RESET;
		FragTrap	fraggyCpy(fraggy);
		std::cout << GREY << "\ngetStatus(fraggyCpy);\n" << RESET;
		getStatus(fraggyCpy);

		std::cout << GREY << "\nfraggyCpy.takeDamage(4);\n" << RESET;
		fraggyCpy.takeDamage(4);

		std::cout << GREY << "\nFragTrap noName;\n" << RESET;
		FragTrap	noName;
		std::cout << GREY << "\ngetStatus(noName);\n" << RESET;
		getStatus(noName);
		
		std::cout << GREY << "\nnoName = fraggy;\n" << RESET;
		noName = fraggy;
		std::cout << GREY << "\ngetStatus(noName);\n" << RESET;
		getStatus(noName);

		std::cout << YELLOW << "\nACTIONS\n\n" << RESET;

		fraggy.attack("Evil Foe");
		getStatus(fraggy);
		fraggy.takeDamage(4);
		getStatus(fraggy);
		fraggy.beRepaired(2);
		getStatus(fraggy);
		fraggy.highFivesGuys();
		fraggy.takeDamage(99);
		getStatus(fraggy);
		fraggy.attack("End Boss");
		fraggy.highFivesGuys();
		fraggy.beRepaired(999);

		std::cout << YELLOW << "\nDECONSTRUCTION\n\n" << RESET;
	}
	{ // DiamondTrap Test
		std::cout << MAGENTA << "\n====================== \n";
		std::cout << "== DiamondTrap Test == \n";
		std::cout << "====================== \n\n" << RESET;

		std::cout << YELLOW << "CONSTRUCTION\n\n" << RESET;
		
		std::cout << GREY << "DiamondTrap diamondy(\"Diamondy\");\n" << RESET;
		DiamondTrap	diamondy("Diamondy");
		std::cout << GREY << "\ngetStatus(diamondy);\n" << RESET;
		getStatus(diamondy);

		diamondy.whoAmI();

		std::cout << GREY << "\ndiamondy.takeDamage(4);\n" << RESET;
		diamondy.takeDamage(4);

		std::cout << GREY << "\nDiamondTrap diamondyCpy(diamondy);\n" << RESET;
		DiamondTrap	diamondyCpy(diamondy);
		std::cout << GREY << "\ngetStatus(diamondyCpy);\n" << RESET;
		getStatus(diamondyCpy);

		std::cout << GREY << "\ndiamondyCpy.takeDamage(4);\n" << RESET;
		diamondyCpy.takeDamage(4);

		std::cout << GREY << "\nDiamondTrap noName;\n" << RESET;
		DiamondTrap	noName;
		std::cout << GREY << "\ngetStatus(noName);\n" << RESET;
		getStatus(noName);
		
		std::cout << GREY << "\nnoName = diamondy;\n" << RESET;
		noName = diamondy;
		std::cout << GREY << "\ngetStatus(noName);\n" << RESET;
		getStatus(noName);

		std::cout << YELLOW << "\nACTIONS\n\n" << RESET;

		diamondy.attack("Evil Foe");
		getStatus(diamondy);
		diamondy.takeDamage(4);
		getStatus(diamondy);
		diamondy.beRepaired(2);
		getStatus(diamondy);
		diamondy.guardGate();
		getStatus(diamondy);

		
	}
	return 0;
}

