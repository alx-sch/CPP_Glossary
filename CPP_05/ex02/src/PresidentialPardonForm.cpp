#include <string>
#include <iostream>

#include "../include/PresidentialPardonForm.hpp"
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

#define NAME		"Presidential Pardon"
#define SIGN_GRADE	25
#define EXEC_GRADE	5
#define TARGET		"Tech Billionaire"

PresidentialPardonForm::PresidentialPardonForm() : AForm(NAME, SIGN_GRADE, EXEC_GRADE), target_(TARGET)
{
	std::cout << "🦅 PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(NAME, SIGN_GRADE, EXEC_GRADE), target_(target)
{
	std::cout << "🦅 PresidentialPardonForm parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other)
{
	std::cout << "🦅 PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "🦅 PresidentialPardonForm destructor called" << std::endl;
}

// Only copies the `target_` and sign status; keeps the const members as is
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "🦅 PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		target_ = other.target_;
	}
	return *this;
}

// Member functions

// Internal function to perform the specific action of the form.
// Here, it grants a presidential pardon to the target.
// -> Use Bureaucrat::executeForm() to call this function.
void	PresidentialPardonForm::executeAction() const
{
	std::cout << "🦅 " << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// Prints the status of the form.
void	PresidentialPardonForm::printStatus(std::ostream& os) const
{
	os << "🦅 Form: " << getName() << std::endl;
	os << "   Target: " << target_ << std::endl;
	os << "   Is signed: ";
	if (getIsSigned())
		os << "Yes";
	else
		os << "No";
	os << std::endl;
	os << "   Sign grade: " << getSignGrade() << std::endl;
	os << "   Execution grade: " << getExecGrade() << std::endl;
}

// Getters

std::string	PresidentialPardonForm::getTarget() const
{
	return target_;
}
