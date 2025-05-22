#include <iostream>
#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type_ = "Cat";
	std::cout	<< "❌🐱 [WrongCat] default constructor called.\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout	<< "❌🐱 [WrongCat] copy constructor called.\n";
}

WrongCat::~WrongCat()
{
	std::cout	<< "❌🐱 [WrongCat] destructor called.\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout	<< "❌🐱 [WrongCat] copy assignment operator called.\n";
	return *this;
}

// MEMBER FUNCTIONS //

void	WrongCat::makeSound() const
{
	std::cout	<< "❌🐱 [WrongCat] meows.\n";
}
