/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:46:56 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/08 19:00:33 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Dog.hpp"

Dog::Dog() : AAnimal()
{
	type_ = "Dog";
	brain_ = new Brain(); // Allocate a new Brain for the Dog
	std::cout	<< "🐶 [Dog] default constructor called.\n";
}
Dog::Dog(const Dog& other) : AAnimal(other)
{
	brain_ = new Brain(*other.brain_); // Deep copy of the Brain
	std::cout	<< "🐶 [Dog] copy constructor called.\n";
}
Dog::~Dog()
{
	std::cout	<< "🐶 [Dog] destructor called.\n";
	delete brain_; // Free the allocated Brain
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain_; // Free this object's old Brain
		brain_ = new Brain(*other.brain_); // Deep copy for this object's new Brain
	}
	std::cout	<< "🐶 [Dog] copy assignment operator called.\n";
	return *this;
}

// MEMBER FUNCTIONS //

void	Dog::makeSound() const
{
	std::cout	<< "🐶 [Dog] barks.\n";
}

// GETTERS //
Brain*	Dog::getBrain() const
{
	return brain_;
}
