#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	private:
		static const std::string	DEFAULT_NAME;
		static const unsigned int	DEFAULT_HIT_POINTS;
		static const unsigned int	DEFAULT_ENERGY_POINTS;
		static const unsigned int	DEFAULT_ATTACK_DAMAGE;

	protected:
		std::string		name_;
		unsigned int	hitPoints_;
		unsigned int	energyPoints_;
		unsigned int	attackDamage_;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();
		
		ClapTrap&	operator=(const ClapTrap& other);

		// GAME FUNCTIONS

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// GETTERS

		std::string				name() const;
		unsigned int			hitPoints() const;
		unsigned int			energyPoints() const;
		unsigned int			attackDamage() const;
		virtual unsigned int	getMaxHitPoints() const; // Virtual to allow derived classes return
														 // their own max HP in beRepaired().
};

#endif
