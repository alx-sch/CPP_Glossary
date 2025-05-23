#include <string>
#include <iostream>
#include <exception>

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

#define RED		"\033[31m"
#define RESET	"\033[0m"

# define NAME	"Dwight"
# define GRADE	150

Bureaucrat::Bureaucrat() : name_(NAME), grade_(GRADE)
{
	std::cout << "💼 Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name_(name), grade_(grade)
{
	std::cout << "💼 Bureaucrat parameterized constructor called\n";
	if (grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name_(other.name_), grade_(other.grade_)
{
	std::cout << "💼 Bureaucrat copy constructor called\n";
}

// Only copies the `grade_` and keeps the `name_` as is
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "💼 Bureaucrat copy assignment operator called\n";
	if (this != &other) {
		// No need to assign name_ as it's const
		grade_ = other.grade_;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "💼 Bureaucrat destructor called\n";
}

// Member functions

void	Bureaucrat::incrementGrade()
{
	if (grade_ <= 1)
		throw Bureaucrat::GradeTooHighException();
	--grade_;
}

void	Bureaucrat::decrementGrade()
{
	if (grade_ >= 150)
		throw Bureaucrat::GradeTooLowException();
	++grade_;
}

void	Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
		std::cout << "💼 " << name_ << " signed " << form.getName() << ".\n";
	} catch (const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try {
		form.execute(*this);
		std::cout << "💼 " << name_ << " executed " << form.getName() << ".\n";
	} catch (const std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
}

// Getters

const std::string& Bureaucrat::getName() const
{
	return name_;
}

int Bureaucrat::getGrade() const
{
	return grade_;
}

// Exception classes

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "💼 Bureaucrat's grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "💼 Bureaucrat's grade too low!";
}

// Overloaded operator<< for Bureaucrat

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << "💼 " << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
