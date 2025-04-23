/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:29:01 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 10:11:23 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main() {
	int		N = 5;
	Zombie	*horde = zombieHorde(N, "Horde");

	for (int i = 0; i < N; ++i) {
		std::cout << i << ": ";
		horde[i].announce();
	}
	delete[] horde;

	return 0;
}
