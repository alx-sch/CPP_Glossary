/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:11:36 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/08 17:16:51 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "../include/Animal.hpp"
# include "../include/Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	brain_;

	public:
		Cat();
		Cat(const Cat& other);
		~Cat();

		Cat&	operator=(const Cat& other);

		void	makeSound() const;	// Override Animal's makeSound()

		Brain*	getBrain() const;
};

#endif
