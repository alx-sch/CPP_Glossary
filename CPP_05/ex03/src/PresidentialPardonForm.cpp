#include "../include/settings.hpp"
#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm(NAME_PP, SIGN_GRADE_PP, EXEC_GRADE_PP), target_(TARGET_PP)
{
	std::cout << "🦅 PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(NAME_PP, SIGN_GRADE_PP, EXEC_GRADE_PP), target_(target)
{
	std::cout << "🦅 PresidentialPardonForm parameterized constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other)
{
	std::cout << "🦅 PresidentialPardonForm copy constructor called\n";
}

// Only copies the `target_` and sign status; keeps the const members as is
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "🦅 PresidentialPardonForm copy assignment operator called\n";
	if (this != &other) {
		AForm::operator=(other);
		target_ = other.target_;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "🦅 PresidentialPardonForm destructor called\n";
}

// Member functions

// Internal function to perform the specific action of the form.
// Here, it grants a presidential pardon to the target.
// -> Use Bureaucrat::executeForm() to call this function.
void	PresidentialPardonForm::executeAction() const
{
	std::cout << "🦅 " << target_ << " has been pardoned by Zaphod Beeblebrox.\n";
}

// Getters

std::string	PresidentialPardonForm::getTarget() const
{
	return target_;
}
