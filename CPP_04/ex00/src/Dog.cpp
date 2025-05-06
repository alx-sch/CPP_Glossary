/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:46:56 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/06 15:47:26 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
	type_ = "Dog";
	std::cout	<< "🐶 [Dog] default constructor called.\n";
}
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout	<< "🐶 [Dog] copy constructor called.\n";
	*this = other;
}
Dog::~Dog()
{
	std::cout	<< "🐶 [Dog] destructor called.\n";
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout	<< "🐶 [Dog] copy assignment operator called.\n";
	return *this;
}

// MEMBER FUNCTIONS //

void	Dog::makeSound() const
{
	std::cout	<< "🐶 [Dog] barks.\n";
}
