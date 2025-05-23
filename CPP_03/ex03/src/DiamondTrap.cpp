#include <string>
#include <iostream>
#include "../include/DiamondTrap.hpp"
#include "../include/colors.hpp"

DiamondTrap::DiamondTrap()
	:	ClapTrap(DEFAULT_NAME + "_clap_name"),
		ScavTrap(),	// inherits name from ClapTrap called above; own ClapTrap call is ignored
		FragTrap()	// inherits name from ClapTrap called above; own ClapTrap call is ignored
{
	this->name_ = DEFAULT_NAME;
	this->hitPoints_ = FragTrap::DEFAULT_HIT_POINTS;
	this->energyPoints_ = ScavTrap::DEFAULT_ENERGY_POINTS;
	this->attackDamage_ = FragTrap::DEFAULT_ATTACK_DAMAGE;
	
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "DiamondTrap"
				<< RESET << " default constructor called.\n";
}

DiamondTrap::DiamondTrap(std::string name)
	:	ClapTrap(name + "_clap_name"),
		ScavTrap(name),	// inherits name from ClapTrap called above; own ClapTrap call is ignored
		FragTrap(name)	// inherits name from ClapTrap called above; own ClapTrap call is ignored
{
	this->name_ = name;
	this->hitPoints_ = FragTrap::DEFAULT_HIT_POINTS;
	this->energyPoints_ = ScavTrap::DEFAULT_ENERGY_POINTS;
	this->attackDamage_ = FragTrap::DEFAULT_ATTACK_DAMAGE;
	
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "DiamondTrap"
				<< RESET << " parameterized constructor called.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	:	ClapTrap(other),
		ScavTrap(other),
		FragTrap(other)
{
	name_ = other.name_;
	
	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "DiamondTrap"
				<< RESET << " copy constructor called.\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout	<< "🏁 " << BLUE << name_ << RESET << ": " << GREEN << "DiamondTrap"
				<< RESET << " destructor called.\n";
}

/**
No need to call ScavTrap or FragTrap assignment operators:
- All state (data members) is inherited from ClapTrap, which is assigned explicitly.
- ScavTrap and FragTrap add behavior, not state that needs reassignment.
*/
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
		name_ = other.name_;
	}

	std::cout	<< "🐣 " << BLUE << name_ << RESET << ": " << GREEN << "DiamondTrap"
				<< RESET << " copy assignment operator called.\n";
	
	return *this;
}

/// GAME FUNCTIONS //

/**
DiamondTrap's special ability: it can tell its own name and the name of its base class (ClapTrap).
It costs 1 energy point to use this ability. If the unit has no hit points or energy points,
it cannot use this ability.
*/
void	DiamondTrap::whoAmI()
{
	if (hitPoints_ > 0 && energyPoints_ > 0) {
		std::cout	<< "💎 " << BLUE << name_ << RESET << ": " << "My " << GREEN << "DiamondTrap"
					<< RESET << " name is: '" << YELLOW << name_ << RESET << "'.\n"
					<< "💎 " << BLUE << name_ << RESET << ": " << "My " << GREEN << "ClapTrap"
					<< RESET << " name is:    '" << YELLOW << ClapTrap::name_ << RESET << "'.\n";
		energyPoints_ -= 1;
	}
	else {
		std::cout	<< "☠️  " << BLUE << name_ << RESET << " is kaputt! It doesn't even know who it is.\n";
	}
}

// GETTERS //

/**
Returns the DiamondTrap's own name instead of the inherited ClapTrap name.

This override is necessary because ClapTrap also has a name_ member, and its
name() returns the base class member (name_ = "<name>_clap_name").
*/
std::string	DiamondTrap::name() const {
	return name_;
}

unsigned int	DiamondTrap::getMaxHitPoints() const {
	return FragTrap::DEFAULT_HIT_POINTS;	// DiamindTrap's max HP is FragTrap's max HP
}

