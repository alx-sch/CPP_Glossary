#include "../include/AForm.hpp"
#include "../include/settings.hpp"

AForm::AForm()
	: name_(NAME_AF), is_signed_(SIGNED_AF), sign_grade_(SIGN_GRADE_AF), exec_grade_(EXEC_GRADE_AF)
{
	std::cout << "📝 Form default constructor called\n";
}

AForm::AForm(const std::string& name, int sign_grade, int exec_grade)
	: name_(name), is_signed_(SIGNED_AF), sign_grade_(sign_grade), exec_grade_(exec_grade)
{
	std::cout << "📝 Form parameterized constructor called\n";
	if (sign_grade_ < 1 || exec_grade_ < 1)
		throw AForm::GradeTooHighException();
	else if (sign_grade_ > 150 || exec_grade_ > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
	:	name_(other.name_), is_signed_(other.is_signed_),
		sign_grade_(other.sign_grade_), exec_grade_(other.exec_grade_)
{
	std::cout << "📝 Form copy constructor called\n";
}

// Only copies the `is_signed_` and keeps the const members as is
AForm&	AForm::operator=(const AForm& other)
{
	std::cout << "📝 Form copy assignment operator called\n";
	if (this != &other)
		is_signed_ = other.is_signed_;
	return *this;
}

AForm::~AForm()
{
	std::cout << "📝 Form destructor called\n";
}

// Member functions

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > getSignGrade())
		throw AForm::GradeTooHighException();
	is_signed_ = true;
}

// Internal function to execute the form.
// -> Use Bureaucrat::executeForm() to call this function.
void	AForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooHighException();
	executeAction();
}

// Getters

std::string	AForm::getName() const
{
	return name_;
}

bool	AForm::getIsSigned() const
{
	return is_signed_;
}

int	AForm::getSignGrade() const
{
	return sign_grade_;
}

int	AForm::getExecGrade() const
{
	return exec_grade_;
}

// Exception classes

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "📝 Form's grade is too high!";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "📝 Form's grade is too low!";
}

const char*	AForm::NotSignedException::what() const throw()
{
	return "📝 Form is not signed!";
}

// Overloading the << operator

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << "📝 Form: " << form.getName() << std::endl;
	os << "   Target: " << form.getTarget() << std::endl;
	os << "   Is signed: ";
	if (form.getIsSigned())
		os << "Yes";
	else
		os << "No";
	os << std::endl;
	os << "   Sign grade: " << form.getSignGrade() << std::endl;
	os << "   Exec grade: " << form.getExecGrade() << std::endl;
	return os;
}
