/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:26:10 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 10:51:55 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

// HumanB may not alywas has a weapon.  
class HumanB {
	public:
		HumanB(std::string name);
		~HumanB();

		void		attack();
		void		setWeapon(Weapon &weapon);

	private:
		std::string	name;
		Weapon		*weapon; // Pointer allows for "no weapon" case (nullptr)
};

#endif
