#include <iostream>
#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout	<< "🐱 [Cat] default constructor called.\n";
	type_ = "Cat";
	brain_ = new Brain(); // Allocate a new Brain for the Cat
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout	<< "🐱 [Cat] copy constructor called.\n";
	brain_ = new Brain(*other.brain_); // Deep copy of the Brain
}

Cat::~Cat()
{
	std::cout	<< "🐱 [Cat] destructor called.\n";
	delete brain_; // Free the allocated Brain
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other) {
		Animal::operator=(other);
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
