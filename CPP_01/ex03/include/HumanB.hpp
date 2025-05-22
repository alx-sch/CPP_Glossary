#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

// HumanB may not alywas has a weapon.  
class HumanB {
	public:
		HumanB(std::string name);
		~HumanB();

		void		attack();
		void		setWeapon(Weapon &weapon);

	private:
		std::string	name;
		Weapon		*weapon; // Pointer allows for "no weapon" case (nullptr)
};

#endif
