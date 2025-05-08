/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:40:08 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/08 18:10:52 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Cat.hpp"

Cat::Cat() : AAnimal()
{
	type_ = "Cat";
	brain_ = new Brain(); // Allocate a new Brain for the Cat
	std::cout	<< "🐱 [Cat] default constructor called.\n";
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	brain_ = new Brain(*other.brain_); // Deep copy of the Brain
	std::cout	<< "🐱 [Cat] copy constructor called.\n";
}

Cat::~Cat()
{
	delete brain_; // Free the allocated Brain
	std::cout	<< "🐱 [Cat] destructor called.\n";
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain_; // Free this object's old Brain
		brain_ = new Brain(*other.brain_); // Deep copy for this object's new Brain
	}
	std::cout	<< "🐱 [Cat] copy assignment operator called.\n";
	return *this;
}

// MEMBER FUNCTIONS //

void	Cat::makeSound() const
{
	std::cout	<< "🐱 [Cat] meows.\n";
}

// GETTERS //

Brain*	Cat::getBrain() const
{
	return brain_;
}
