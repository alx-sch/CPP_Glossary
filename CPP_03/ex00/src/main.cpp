#include <iostream>
#include "../include/ClapTrap.hpp"
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

	return 0;
}
