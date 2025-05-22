#include "Zombie.hpp"

// Creates `N` zombies in an array (all the same `name`) 
// and returns pointer to the first entry.
Zombie	*zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N]; // Cannot use list init here -> setter fct used
	
	for (int i = 0; i < N; ++i) {
		horde[i].setName(name);
	}

	return horde;
}
