#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "../include/FragTrap.hpp"
# include "../include/ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	name_;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap();

		DiamondTrap&	operator=(const DiamondTrap& other);

		// GAME FUNCTIONS

		void	whoAmI(); // new ability
		using ScavTrap::attack; // Use ScavTrap's attack function

		// GETTERS

		std::string		name() const; // Override ClapTrap's getName()
		unsigned int	getMaxHitPoints() const;
};

#endif
