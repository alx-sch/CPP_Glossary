/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:00:39 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 10:11:07 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie {
	public: 
		Zombie();
		~Zombie();

		void		announce();
		void		setName (std::string name);

	private:
		std::string	name;
};

#endif
