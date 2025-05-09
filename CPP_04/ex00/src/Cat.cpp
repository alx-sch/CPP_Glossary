/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:40:08 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/08 15:08:19 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
	type_ = "Cat";
	std::cout	<< "🐱 [Cat] default constructor called.\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout	<< "🐱 [Cat] copy constructor called.\n";
}

Cat::~Cat()
{
	std::cout	<< "🐱 [Cat] destructor called.\n";
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout	<< "🐱 [Cat] copy assignment operator called.\n";
	return *this;
}

// MEMBER FUNCTIONS //

void	Cat::makeSound() const
{
	std::cout	<< "🐱 [Cat] meows.\n";
}
