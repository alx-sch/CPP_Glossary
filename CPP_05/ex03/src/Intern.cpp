#include <string>
#include <iostream>

#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

#define RED		"\033[31m"
#define RESET	"\033[0m"

Intern::Intern()
{
	std::cout << "☕️ Intern default constructor called\n";
}

Intern::Intern(const std::string& dummy)
{
	std::cout << "☕️ Intern parameterized constructor called\n";
	(void)dummy; // Avoid unused parameter warning
}

Intern::Intern(const Intern& other)
{
	std::cout << "☕️ Intern copy constructor called\n";
	(void)other; // Avoid unused parameter warning
}

Intern&	Intern::operator=(const Intern& other)
{
	std::cout << "☕️ Intern copy assignment operator called\n";
	if (this != &other) {
		// No member variables to copy
	}
	return *this;
}

Intern::~Intern()
{
	std::cout << "☕️ Intern destructor called\n";
}

// Factory functions

AForm*	makeShrubberyCreation(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	makeRobotomyRequest(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	makePresidentialPardon(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

// Struct to pair names with factory functions
struct	FormEntry
{
	const char*	name;	// const char* as pointer to string literal, defined at compile time (e.g., NAME_SC)
	AForm*		(*fctPtr)(const std::string& target);	// 'fctPtr' points to a function like 'AForm* fct(const std::string& target)'.
};

// Static array of all forms; initialized once at compile time
static const	FormEntry formEntries[] =
{
	{ NAME_SC, makeShrubberyCreation }, // No need to explictly reference (&makeShrubberyCreation) as it decays to a pointer automatically
	{ NAME_RR, makeRobotomyRequest },
	{ NAME_PP, makePresidentialPardon }
};

// Creates a form based on the name and target provided.
// Returns a pointer to the newly created form.
AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	for (size_t i = 0; i < sizeof(formEntries) / sizeof(FormEntry); ++i) {
		if (formName == formEntries[i].name) {
			std::cout << "☕️ Intern creates " << formName << ".\n";
			return formEntries[i].fctPtr(target);
		}
	}
	std::cerr << RED << "☕️ Error: Form type '" << formName << "' is not recognized.\n" << RESET;
	return NULL;
}
