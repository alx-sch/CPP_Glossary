#include <string>
#include <iostream>

#include "../include/Intern.hpp"
#include "../include/AForm.hpp"

Intern::Intern()
{
	std::cout << "☕️ Intern default constructor called\n";
}

Intern::Intern(const Intern& other)
{
	std::cout << "☕️ Intern copy constructor called\n";
	(void)other; // Avoid unused parameter warning
}

