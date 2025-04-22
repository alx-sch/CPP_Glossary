/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:25:05 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/22 17:01:34 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class	HumanA {
	public:
		HumanA(const std::string &nameProvided, Weapon &initial_weapon );
		~HumanA( void );

		void		attack( void ) const; // const as attacks only prints and doesn't modify

	private:
		std::string	name;
		Weapon		&weapon; // Reference as there is always a weapon
};

#endif
