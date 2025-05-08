/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:14:13 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/08 18:05:21 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "../include/AAnimal.hpp"
# include "../include/Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain*	brain_;

	public:
		Dog();
		Dog(const Dog& other);
		~Dog();

		Dog&	operator=(const Dog& other);

		void	makeSound() const;

		Brain*	getBrain() const;
};	

#endif
