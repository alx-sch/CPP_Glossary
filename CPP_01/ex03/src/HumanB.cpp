#include <iostream>
#include <HumanB.hpp>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}
HumanB::~HumanB() {}

void	HumanB::attack() {
	if (!weapon)
		std::cout << name << " tries to attack but has no weapon!\n";
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon) {
	weapon =  &new_weapon;
}
