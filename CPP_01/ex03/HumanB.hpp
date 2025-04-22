/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:26:10 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/22 15:56:44 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB {
	public:
		HumanB( const std::string &name );
		~HumanB( void );

		void		attack( void ) const; // const as attacks only prints and doesn't modify
		void		setWeapon( Weapon &weapon );

	private:
		std::string	name;
		Weapon		*weapon; // Pointer allows for "no weapon" case (nullptr)
};

#endif
