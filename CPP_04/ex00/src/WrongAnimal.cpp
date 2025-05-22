#include <iostream>
#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("Unknown")
{
	std::cout	<< "❌❓ [WrongAnimal] default constructor called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type_(other.type_)
{
	std::cout	<< "❌❓ [WrongAnimal] copy constructor called.\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout	<< "❌❓ [WrongAnimal] destructor called.\n";
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other) {
		type_ = other.type_;
	}
	std::cout	<< "❌❓ [WrongAnimal] copy assignment operator called.\n";
	return *this;
}

// MEMBER FUNCTIONS //

void	WrongAnimal::makeSound() const
{
	std::cout	<< "❌❓ [WrongAnimal] makes a sound.\n";
}

// GETTERS //

std::string	WrongAnimal::getType() const
{
	return type_;
}
