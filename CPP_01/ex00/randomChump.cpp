/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:14:30 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 10:41:32 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" 

// Creates a new zombie with `name` on the stack, let it announce, 
// and zombie is then destroyed, going out of scope.
void	randomChump(std::string name) {
	Zombie z(name); 
	z.announce();
} 
