/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:39:27 by codespace         #+#    #+#             */
/*   Updated: 2025/04/20 20:24:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie( void ) {}

Zombie::~Zombie( void ) {
    std::cout << this->name << " is destroyed." << std::endl;
}

void    Zombie::announce( void ) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName( std::string name ) {
    this->name = name;
}

Zombie* newZombie( std::string name ) {
    Zombie* z = new Zombie();   // Create a new Zombie on the heap
    z->setName(name);
    return z;
}

void    randomChump( std::string name ) {
    Zombie z;       // Create a Zombie on the stack
    z.setName(name);
    z.announce();
} // Goes out of scope and is destroyed automatically
