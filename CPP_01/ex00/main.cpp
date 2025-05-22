#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main() {
	Zombie*	z = newZombie("Heap");

	z->announce();
	randomChump("Stack");
	delete z;

	return 0;
}
