/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:40:40 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/04 17:22:54 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ClapTrap.hpp>

class ScavTrap : virtual public ClapTrap {
	protected:
		const static unsigned int _hitPointsInit = 100;
		const static unsigned int _energyPointsInit = 50;
		const static unsigned int _attackDamageInit = 20;
		
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();

		void	attack(const std::string& target); // Override inherited attack fct
		void	guardGate(); // new ability
};
