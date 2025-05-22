#include <iostream>
#include <fstream>
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

#define RED		"\033[31m"
#define RESET	"\033[0m"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target_("The Void")
{
	std::cout << "🌳 ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137), target_(target)
{
	std::cout << "🌳 ShrubberyCreationForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target_(other.target_)
{
	std::cout << "🌳 ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "🌳 ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "🌳 ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		target_ = other.target_;
	}
	return *this;
}

// Member function to execute the form

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();

	std::ofstream file((target_ + "_shrubbery").c_str()); // As std::ofstream expects a const char* (tareget_ is not)
	if (!file)
	{
		std::cerr << RED <<"Error: Could not open file for writing.\n" << RESET;
		return;
	}
	file << "       _-_\n"
			"    _-_-_-_\n"
			"  _-_-_-_-_-_\n"
			"     /\\\n"
			"    /  \\\n"
			"   /    \\\n"
			"  /      \\\n"
			" /        \\\n"
			"/          \\\n";
	file.close();
}
