/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:18:02 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/08 18:11:43 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/AAnimal.hpp"

AAnimal::AAnimal() : type_("Unknown")
{
	std::cout	<< "👻 [Abstract Animal] default constructor called.\n";
}

AAnimal::AAnimal(const AAnimal& other) : type_(other.type_)
{
	std::cout	<< "👻 [Abstract Animal] copy constructor called.\n";
}

AAnimal::~AAnimal()
{
	std::cout	<< "👻 [Abstract Animal] destructor called.\n";
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	if (this != &other) {
		type_ = other.type_;
	}
	std::cout	<< "👻 [Abstract Animal] copy assignment operator called.\n";
	return *this;
}

// MEMBER FUNCTIONS //

void	AAnimal::makeSound() const
{
	std::cout	<< "👻 [Abstract Animal] makes a sound.\n";
}

// GETTERS //

std::string	AAnimal::getType() const
{
	return type_;
}
