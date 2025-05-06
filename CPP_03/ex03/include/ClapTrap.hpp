/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:39:32 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/06 19:54:12 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	private:
		static const unsigned int	DEFAULT_HIT_POINTS;
		static const unsigned int	DEFAULT_ENERGY_POINTS;
		static const unsigned int	DEFAULT_ATTACK_DAMAGE;

	protected:
		std::string		name_;
		unsigned int	hitPoints_;
		unsigned int	energyPoints_;
		unsigned int	attackDamage_;

		static const std::string	DEFAULT_NAME;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		virtual ~ClapTrap();	// virtual: Correct destructor is called when deleting via a base class pointer.
								// Not super necessary here, but good practice.

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
