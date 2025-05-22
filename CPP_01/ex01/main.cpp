#include <iostream>
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main() {
	int		N = 5;
	Zombie	*horde = zombieHorde(N, "Horde");

	for (int i = 0; i < N; ++i) {
		std::cout << i << ": ";
		horde[i].announce();
	}
	delete[] horde;

	return 0;
}
