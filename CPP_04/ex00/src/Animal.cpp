/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:18:02 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/06 15:27:38 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Animal.hpp"

Animal::Animal() : type_("Unknown")
{
	std::cout	<< "✨ [Animal] default constructor called.\n";
}

Animal::Animal(const Animal& other)
{
	std::cout	<< "✨ [Animal] copy constructor called.\n";
	*this = other;
}

Animal::~Animal()
{
	std::cout	<< "✨ [Animal] destructor called.\n";
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other) {
		type_ = other.type_;
	}
	std::cout	<< "✨ [Animal] copy assignment operator called.\n";
	return *this;
}

// MEMBER FUNCTIONS //

void	Animal::makeSound() const
{
	std::cout	<< "✨ [Animal] makes a sound.\n";
}

// GETTERS //

std::string	Animal::getType() const
{
	return type_;
}
