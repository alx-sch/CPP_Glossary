#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "../include/AForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(const std::string& dummy);	// Dummy constructor to satisfy the requirements; 
											// but makes no sense as there are no member variables to initialize.	
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();

		AForm*	makeForm(const std::string& formName, const std::string& target);
};

# endif
