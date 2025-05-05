/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:02:54 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/05 14:46:10 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <ClapTrap.hpp>

class FragTrap : public ClapTrap {
	private:
		static const unsigned int	_DEFAULT_HIT_POINTS;
		static const unsigned int	_DEFAULT_ENERGY_POINTS;
		static const unsigned int	_DEFAULT_ATTACK_DAMAGE;

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();

		void	highFivesGuys(); // new ability
};
