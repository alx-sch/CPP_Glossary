/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:13:29 by codespace         #+#    #+#             */
/*   Updated: 2025/04/20 20:21:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
public:
    Zombie( void );
    ~Zombie( void );

    void        announce( void );
    void        setName( std::string name );
    
private:
    std::string name; 
};

Zombie*         newZombie( std::string name );
void            randomChump( std::string name );

#endif