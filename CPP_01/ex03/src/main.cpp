/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:12:15 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 13:03:31 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <HumanA.hpp>
#include <HumanB.hpp>
#include <Weapon.hpp>

int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("super bloody club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("super bloody club");
		jim.attack();
	}

	return 0;
}
