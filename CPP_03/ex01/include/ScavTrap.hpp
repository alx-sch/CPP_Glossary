/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:40:40 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/05 20:43:57 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		static const unsigned int	_DEFAULT_HIT_POINTS;
		static const unsigned int	_DEFAULT_ENERGY_POINTS;
		static const unsigned int	_DEFAULT_ATTACK_DAMAGE;
		
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();

		void	attack(const std::string& target); // Override ClapTrap's attack()
		void	guardGate(); // new ability
};

#endif
