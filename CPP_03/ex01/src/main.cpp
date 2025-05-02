/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:35:51 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/02 14:45:26 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>

int	main() {
	ScavTrap	noName;
	ScavTrap	scavvy("Scavvy");
	ScavTrap	scavvyCpy(scavvy);

	noName.attack("Evil Foe");
	scavvy.attack("Another Foe");

	scavvyCpy.guardGate();
	scavvyCpy.takeDamage(4);
	scavvyCpy.beRepaired(2);
	scavvyCpy.takeDamage(99);
	scavvyCpy.attack("End Boss");
	scavvyCpy.beRepaired(999);
	scavvyCpy.guardGate();

	return 0;
}

