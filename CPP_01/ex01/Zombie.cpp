#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::~Zombie() {
	std::cout << name << " is destroyed.\n";
}

void	Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string zombieName) {
	name = zombieName;
}
