#include "Zombie.hpp" 

// Creates a new zombie with `name` on the stack, let it announce, 
// and zombie is then destroyed, going out of scope.
void	randomChump(std::string name) {
	Zombie z(name); 
	z.announce();
} 
