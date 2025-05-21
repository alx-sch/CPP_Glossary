/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:02:01 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/21 19:28:44 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form() : name_("Template"), is_signed_(false), sign_grade_(150), exec_grade_(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int sign_grade, int exec_grade)
	: name_(name), is_signed_(false), sign_grade_(sign_grade), exec_grade_(exec_grade)
{
	std::cout << "Form parameterized constructor called" << std::endl;
	if (sign_grade_ < 1 || exec_grade_ < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade_ > 150 || exec_grade_ > 150)
		throw Form::GradeTooLowException();
}
Form::Form(const Form& other)
	:	name_(other.name_), is_signed_(other.is_signed_),
		sign_grade_(other.sign_grade_), exec_grade_(other.exec_grade_)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

// Only copies the `is_signed_` and keeps the const members as is
Form& Form::operator=(const Form& other)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other) {
		is_signed_ = other.is_signed_;
	}
	return *this;
}

// Member functions

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > sign_grade_)
		throw Form::GradeTooLowException();
	is_signed_ = true;
}

// Getters

std::string Form::getName() const
{
	return name_;
}

bool Form::getIsSigned() const
{
	return is_signed_;
}

int Form::getSignGrade() const
{
	return sign_grade_;
}

int Form::getExecGrade() const
{
	return exec_grade_;
}

// Exception classes

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

// Overloading the << operator for Form

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName() << std::endl;
	os << "   Is signed: ";
	if (form.getIsSigned())
		os << "Yes";
	else
		os << "No";
	os << std::endl;
	os << "   Sign grade: " << form.getSignGrade() << std::endl;
	os << "   Execution grade: " << form.getExecGrade();
	return os;
}
