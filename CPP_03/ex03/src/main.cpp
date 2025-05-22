#include <iostream>
#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"
#include "../include/colors.hpp"

/**
Prints the name, HP, EP, and attack damage of a unit.
The unit must have name(), hitPoints(), energyPoints(), and attackDamage().
*/
template <typename T>
void	getStatus(const T& unit)
{
	std::cout << "Name: " << BLUE << unit.name() << RESET << "\n";
	std::cout << "HP:   " << YELLOW << unit.hitPoints() << RESET << "\n";
	std::cout << "EP:   " << YELLOW << unit.energyPoints() << RESET << "\n";
	std::cout << "ATT:  " << YELLOW << unit.attackDamage() << RESET << "\n";
}

int	main()
{
	{ // ClapTrap Test
		std::cout		<< MAGENTA << "\n=================== \n"
						<< "== ClapTrap Test == \n"
						<< "=================== \n\n" << RESET;
		std::cout		<< YELLOW << "-- CONSTRUCTION --\n\n" << RESET;

		ClapTrap	clappy("Clappy");
		getStatus(clappy);
		clappy.takeDamage(2);

		ClapTrap	candy(clappy);
		getStatus(candy);
		candy.takeDamage(2);

		ClapTrap	noName;
		getStatus(noName);
		noName = candy;
		getStatus(noName);

		std::cout		<< YELLOW << "\n-- ACTIONS --\n\n" << RESET;

		noName.attack("Evil Foe");
		getStatus(noName);
		noName.takeDamage(4);
		getStatus(noName);
		noName.beRepaired(2);
		noName.beRepaired(99);
		noName.beRepaired(99);
		getStatus(noName);
		noName.takeDamage(99);
		getStatus(noName);
		noName.attack("End Boss");
		noName.beRepaired(999);

		std::cout		<< YELLOW << "\n-- DECONSTRUCTION --\n\n" << RESET;
	}	
	{ // ScavTrap Test
		std::cout		<< MAGENTA << "\n=================== \n"
						<< "== ScavTrap Test == \n"
						<< "=================== \n\n" << RESET;
		std::cout		<< YELLOW << "-- CONSTRUCTION --\n\n" << RESET;

		ScavTrap	scavvy("Scavvy");
		getStatus(scavvy);
		scavvy.takeDamage(2);

		ScavTrap	sandy(scavvy);
		getStatus(sandy);
		sandy.takeDamage(2);

		ScavTrap	noName;
		getStatus(noName);
		noName = sandy;
		getStatus(noName);

		std::cout		<< YELLOW << "\n-- ACTIONS --\n\n" << RESET;

		noName.attack("Evil Foe");
		getStatus(noName);
		noName.guardGate();
		noName.takeDamage(4);
		getStatus(noName);
		noName.beRepaired(2);
		noName.beRepaired(99);
		noName.beRepaired(99);
		getStatus(noName);
		noName.takeDamage(999);
		getStatus(noName);
		noName.attack("End Boss");
		noName.beRepaired(999);
		noName.guardGate();

		std::cout		<< YELLOW << "\n-- DECONSTRUCTION --\n\n" << RESET;
	}
	{ // FragTrap Test
		std::cout		<< MAGENTA << "\n=================== \n"
						<< "== FragTrap Test == \n"
						<< "=================== \n\n" << RESET;
		std::cout		<< YELLOW << "-- CONSTRUCTION --\n\n" << RESET;

		FragTrap	fraggy("Fraggy");
		getStatus(fraggy);
		fraggy.takeDamage(2);

		FragTrap	fanny(fraggy);
		getStatus(fanny);
		fanny.takeDamage(2);

		FragTrap	noName;
		getStatus(noName);
		noName = fanny;
		getStatus(noName);

		std::cout		<< YELLOW << "\n-- ACTIONS --\n\n" << RESET;

		noName.attack("Evil Foe");
		getStatus(noName);
		noName.takeDamage(4);
		getStatus(noName);
		noName.highFivesGuys();
		noName.beRepaired(2);
		noName.beRepaired(99);
		noName.beRepaired(99);
		getStatus(noName);
		noName.takeDamage(999);
		getStatus(noName);
		noName.attack("End Boss");
		noName.beRepaired(999);
		noName.highFivesGuys();

		std::cout		<< YELLOW << "\n-- DECONSTRUCTION --\n\n" << RESET;
	}
	{ // DiamondTrap Test
		std::cout		<< MAGENTA << "\n====================== \n"
						<< "== DiamondTrap Test == \n"
						<< "====================== \n\n" << RESET;
		std::cout		<< YELLOW << "-- CONSTRUCTION --\n\n" << RESET;

		DiamondTrap	dimmy("Dimmy");
		getStatus(dimmy);
		dimmy.takeDamage(2);

		DiamondTrap	danny(dimmy);
		getStatus(danny);
		danny.takeDamage(2);

		DiamondTrap	noName;
		getStatus(noName);
		noName = danny;
		getStatus(noName);

		std::cout		<< YELLOW << "\n-- ACTIONS --\n\n" << RESET;

		noName.attack("Evil Foe");
		getStatus(noName);
		noName.guardGate();
		noName.highFivesGuys();
		noName.whoAmI();
		noName.takeDamage(4);
		getStatus(noName);
		noName.beRepaired(2);
		noName.beRepaired(99);
		noName.beRepaired(99);
		getStatus(noName);
		noName.takeDamage(999);
		getStatus(noName);
		noName.attack("End Boss");
		noName.beRepaired(999);
		noName.guardGate();
		noName.highFivesGuys();
		noName.whoAmI();

		std::cout		<< YELLOW << "\n-- DECONSTRUCTION --\n\n" << RESET;
	}

	return 0;
}
