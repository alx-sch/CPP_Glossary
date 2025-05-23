#include <string>
#include <iostream>
#include "../include/Bureaucrat.hpp"

# define NAME	"Dwight"
# define GRADE	150

Bureaucrat::Bureaucrat() : name_(NAME), grade_(GRADE)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name_(name), grade_(grade)
{
	std::cout << "Bureaucrat parameterized constructor called" << std::endl;
	if (grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name_(other.name_), grade_(other.grade_)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

// Only copies the `grade_` and keeps the `name_` as is
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other) 
		grade_ = other.grade_;
	return *this;
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

// Getters

const std::string&	Bureaucrat::getName() const
{
	return name_;
}

int	Bureaucrat::getGrade() const
{
	return grade_;
}

// Exception classes

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

// Overloaded operator<< for Bureaucrat

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
