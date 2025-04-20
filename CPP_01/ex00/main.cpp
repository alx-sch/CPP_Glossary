/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:37:54 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/20 21:36:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main( void ) {
    Zombie* z = newZombie("Heap");
    
    z->announce();  
    randomChump("Stack"); 
    delete z;
     
    return 0;
}   
