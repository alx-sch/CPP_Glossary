#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

// HumanA alywas has a weapon.  
class	HumanA {
	public:
		HumanA(std::string nameProvided, Weapon &initialWeapon);
		~HumanA();

		void		attack();

	private:
		std::string	name;
		Weapon		&weapon; // Reference as there is always a weapon
};

#endif
