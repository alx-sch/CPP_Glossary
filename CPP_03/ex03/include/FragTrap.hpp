#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "../include/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		static const unsigned int	DEFAULT_HIT_POINTS;
		static const unsigned int	DEFAULT_ENERGY_POINTS;
		static const unsigned int	DEFAULT_ATTACK_DAMAGE;

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap();

		FragTrap&	operator=(const FragTrap& other);

		// GAME FUNCTIONS

		void	highFivesGuys(); // new ability

		// GETTERS

		unsigned int	getMaxHitPoints() const;
};

#endif
