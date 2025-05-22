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
