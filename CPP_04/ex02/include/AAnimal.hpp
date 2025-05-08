/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:11:15 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/08 18:10:26 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal
{
	protected:
		std::string	type_;

	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		virtual ~AAnimal();

		AAnimal&	operator=(const AAnimal& other);

		virtual void	makeSound() const = 0;	// Pure virtual → abstract class
		std::string		getType() const;
};

#endif
