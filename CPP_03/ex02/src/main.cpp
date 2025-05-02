/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:35:51 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/02 15:32:58 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <FragTrap.hpp>

int	main() {
	FragTrap	noName;
	FragTrap	fraggy("Fraggy");
	FragTrap	fraggyCpy(fraggy);

	noName.attack("Evil Foe");
	fraggy.attack("Another Foe");

	fraggy.highFivesGuys();
	fraggy.takeDamage(4);
	fraggy.beRepaired(2);
	fraggy.takeDamage(99);
	fraggy.attack("End Boss");
	fraggy.beRepaired(999);
	fraggy.highFivesGuys();

	return 0;
}

