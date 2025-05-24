#include <iostream>

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"		// for form name
#include "../include/RobotomyRequestForm.hpp"		// for form name
#include "../include/PresidentialPardonForm.hpp"	// for form name

void processForm(Bureaucrat& bureaucrat, AForm* formPtr)
{
	if (formPtr) {
		bureaucrat.signForm(*formPtr);
		bureaucrat.executeForm(*formPtr);
		delete formPtr;
	}
}

int main()
{
	Intern		intern;
	Bureaucrat	bob("Bob", 1);
	AForm*		formPtr = NULL;

	std::cout << std::endl;

	// Test creating Shrubbery Creation form
	formPtr = intern.makeForm(NAME_SC, "backyard");
	processForm(bob, formPtr);
	std::cout << std::endl;

	// Test creating Robotomy Request form
	formPtr = intern.makeForm(NAME_RR, "Bender");
	processForm(bob, formPtr);
	std::cout << std::endl;

	// Test creating Presidential Pardon form
	formPtr = intern.makeForm(NAME_PP, "Lindsay Lohan");
	processForm(bob, formPtr);
	std::cout << std::endl;

	// Test creating unknown form
	formPtr = intern.makeForm("Unknown Form", "Nobody");
	processForm(bob, formPtr);
	std::cout << std::endl;

	return 0;
}
