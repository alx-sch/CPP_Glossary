#include <cstdlib>	// for rand(), srand()
#include <ctime>	// for time

#include "../include/settings.hpp"
#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm(NAME_RR, SIGN_GRADE_RR, EXEC_GRADE_RR), target_(TARGET_RR)
{
	std::cout << "🤖 RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(NAME_RR, SIGN_GRADE_RR, EXEC_GRADE_RR), target_(target)
{
	std::cout << "🤖 RobotomyRequestForm parameterized constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
{
	std::cout << "🤖 RobotomyRequestForm copy constructor called\n";
}

// Only copies the `target_` and sign status; keeps the const members as is
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "🤖 RobotomyRequestForm copy assignment operator called\n";
	if (this != &other){
		AForm::operator=(other);
		target_ = other.target_;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "🤖 RobotomyRequestForm destructor called\n";
}

// Member functions

// Internal function to perform the specific action of the form.
// Here, it robotomizes the target with a 50% success rate.
// -> Use Bureaucrat::executeForm() to call this function.
void	RobotomyRequestForm::executeAction() const
{
	std::srand(std::time(0));  // Sets random seed for number generation
	int	success = std::rand() % 2;  // Generate a random number (0 or 1)

	std::cout << "🤖 BRRRRRZZZZZ — BRRRRRZZZZZ — BRRRRRZZZZZ\n";
	if (success == 0) {
		std::cout << "🤖 ✅ " << target_ << " has been robotomized successfully!\n";
		return;
	}
	else
		std::cout << "🤖 ❌ Robotomization of " << target_ << " has failed.\n";
}

// Getters

std::string	RobotomyRequestForm::getTarget() const
{
	return target_;
}
