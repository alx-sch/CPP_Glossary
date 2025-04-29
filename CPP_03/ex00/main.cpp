/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:39:30 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/29 17:29:16 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main() {
	ClapTrap	noName;
	ClapTrap	clappy("Clappy");
	ClapTrap	clappyCpy(clappy);

	noName.attack("Evil Foe");
	clappy.attack("Another Foe");

	clappyCpy.takeDamage(4);
	clappyCpy.beRepaired(2);
	clappyCpy.takeDamage(99);
	clappyCpy.attack("End Boss");
	clappyCpy.beRepaired(999);

	return 0;
}
