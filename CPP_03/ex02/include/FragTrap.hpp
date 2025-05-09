/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:02:54 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/06 16:30:32 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "../include/ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
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
