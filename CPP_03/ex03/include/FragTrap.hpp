/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:02:54 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/04 17:22:33 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ClapTrap.hpp>

class FragTrap : virtual public ClapTrap {
	protected:
		const static unsigned int _hitPointsInit = 100;
		const static unsigned int _energyPointsInit = 100;
		const static unsigned int _attackDamageInit = 30;
		
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();

		void	highFivesGuys(); // new ability
};
