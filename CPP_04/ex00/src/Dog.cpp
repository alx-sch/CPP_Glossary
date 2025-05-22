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
