#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name(zombieName) {}
Zombie::~Zombie() {
	std::cout << name << " is destroyed.\n";
}

void	Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
