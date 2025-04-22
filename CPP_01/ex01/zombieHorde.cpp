/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:25:13 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/22 16:50:13 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates `N` zombies in an array (all the same `name`) 
// and returns pointer to the first entry.
Zombie	*zombieHorde( int N, std::string name ) {
	Zombie* horde = new Zombie[N]; // Cannot use list init here -> setter fct used
	
	for (int i = 0; i < N; ++i) {
		horde[i].setName(name);
	}

	return horde;
}
