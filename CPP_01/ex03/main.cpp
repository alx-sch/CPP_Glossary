/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:12:15 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/22 16:32:17 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main() {
	Weapon	club = Weapon("crude spiked club");

	HumanA	bob("Bob", club);

	bob.attack();
	club.setType("super bloody club");
	bob.attack();

	HumanB	pete("Pete");
	pete.attack();
	pete.setWeapon(club);
	pete.attack();
	
	
	return 0;
}
