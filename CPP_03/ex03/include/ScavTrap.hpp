#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "../include/ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		static const unsigned int	DEFAULT_HIT_POINTS;
		static const unsigned int	DEFAULT_ENERGY_POINTS;
		static const unsigned int	DEFAULT_ATTACK_DAMAGE;
		
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();

		ScavTrap&	operator=(const ScavTrap& other);

		// GAME FUNCTIONS

		void	attack(const std::string& target); // Override ClapTrap's attack()
		void	guardGate(); // new ability

		// GETTERS

		unsigned int	getMaxHitPoints() const;
};

#endif
