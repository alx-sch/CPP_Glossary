/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:39:27 by codespace         #+#    #+#             */
/*   Updated: 2025/04/21 08:40:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name) {}

Zombie::~Zombie( void ) {
    std::cout << this->name << " is destroyed." << std::endl;
}

void    Zombie::announce( void ) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
