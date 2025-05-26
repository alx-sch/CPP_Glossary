#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "../include/AForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();

		AForm*	makeForm(const std::string& formName, const std::string& target);
};

# endif
