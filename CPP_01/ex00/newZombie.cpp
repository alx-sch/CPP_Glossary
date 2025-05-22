#include "Zombie.hpp"

// Creates a new zombie with `name` on the heap.
Zombie	*newZombie( std::string name ) {
	Zombie* z = new Zombie(name);
	return z;
}
