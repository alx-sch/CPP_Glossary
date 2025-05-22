#include <iostream>
#include <HumanA.hpp>

HumanA::HumanA(std::string nameProvided, Weapon &initialWeapon)
	: name(nameProvided), weapon(initialWeapon) {}
HumanA::~HumanA() {}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
