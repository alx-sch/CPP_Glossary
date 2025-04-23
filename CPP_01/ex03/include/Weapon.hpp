/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:06:11 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 10:11:50 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon {
	public:
		Weapon(std::string typeProvided);
		~Weapon();

		std::string	getType();
		void		setType(std::string newType);

	private:
		std::string	type;
};

#endif
