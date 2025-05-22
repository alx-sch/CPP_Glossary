#include <iostream>
#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout	<< "🧠 [Brain] default constructor called.\n";
	for (unsigned int i = 0; i < MAX_IDEAS; ++i)
		ideas_[i] = "No idea";
}

Brain::Brain(const Brain& other)
{
	for (unsigned int i = 0; i < MAX_IDEAS; ++i)
		ideas_[i] = other.ideas_[i]; // Manually copy each idea
	std::cout	<< "🧠 [Brain] copy constructor called.\n";
}

Brain::~Brain()
{
	std::cout	<< "🧠 [Brain] destructor called.\n";
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other) {
		for (unsigned int i = 0; i < MAX_IDEAS; ++i)
			ideas_[i] = other.ideas_[i];
	}
	std::cout	<< "🧠 [Brain] copy assignment operator called.\n";
	return *this;
}

// SETTERS / GETTERS //

void	Brain::setIdea(unsigned int index, const std::string& idea)
{
	if (index < MAX_IDEAS)
		ideas_[index] = idea;
}

std::string	Brain::getIdea(unsigned int index) const
{
	if (index < MAX_IDEAS)
		return ideas_[index];
	return "[Outside of brain's capacity]";
}
