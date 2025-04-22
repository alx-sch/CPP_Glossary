/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:12:20 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/22 16:48:39 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates a new zombie with `name` on the heap.
Zombie	*newZombie( std::string name ) {
	Zombie* z = new Zombie( name );
	return z;
}
