#include <string>
#include <iostream>

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

#define RED		"\033[31m"
#define RESET	"\033[0m"

AForm::AForm() : name_("Template"), is_signed_(false), sign_grade_(150), exec_grade_(150)
{
	std::cout << "📝 Form default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int sign_grade, int exec_grade)
	: name_(name), is_signed_(false), sign_grade_(sign_grade), exec_grade_(exec_grade)
{
	std::cout << "📝 Form parameterized constructor called" << std::endl;
	if (sign_grade_ < 1 || exec_grade_ < 1)
		throw AForm::GradeTooHighException();
	else if (sign_grade_ > 150 || exec_grade_ > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
	:	name_(other.name_), is_signed_(other.is_signed_),
		sign_grade_(other.sign_grade_), exec_grade_(other.exec_grade_)
{
	std::cout << "📝 Form copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "📝 Form destructor called" << std::endl;
}

// Only copies the `is_signed_` and keeps the const members as is
AForm&	AForm::operator=(const AForm& other)
{
	std::cout << "📝 Form copy assignment operator called" << std::endl;
	if (this != &other) {
		is_signed_ = other.is_signed_;
	}
	return *this;
}

// Member functions

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > getSignGrade())
		throw AForm::GradeTooHighException();
	is_signed_ = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	try {
		if (!getIsSigned())
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > getExecGrade())
			throw AForm::GradeTooHighException();
		executeAction();
	}
	catch (const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
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

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "📝 Form is not signed!";
}

// Overloading the << operator for Form

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	form.printStatus(os);
	return os;
}
