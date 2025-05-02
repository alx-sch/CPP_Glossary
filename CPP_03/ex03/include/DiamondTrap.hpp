/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:42:52 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/02 16:43:03 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
ClapTrap is the base class.
FragTrap and ScavTrap inherit from ClapTrap.
DiamondTrap inherits from both FragTrap and ScavTrap.
*/

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap {
	private:
		std::string	_name; // same name as ClapTrap

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap();

		void	whoAmI(); // new ability
};
