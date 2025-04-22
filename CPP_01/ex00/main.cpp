/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:57:49 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/22 13:47:08 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main( void ) {
	Zombie*	z = newZombie("Heap");

	z->announce();
	randomChump("Stack");
	delete z;

	return 0;
}
