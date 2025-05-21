/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:07:13 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/21 15:12:38 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Dwight"), grade_(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: name_(name), grade_(grade) {
	std::cout << "Bureaucrat parameterized constructor called" << std::endl;
	if (grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name_(other.name_), grade_(other.grade_) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

// Only copies the `grade_` and keeps the `name_` as is
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other) {
		// No need to assign name_ as it's const
		grade_ = other.grade_;
	}
	return *this;
}

// Member functions

void Bureaucrat::incrementGrade() {
	if (grade_ <= 1)
		throw Bureaucrat::GradeTooHighException();
	--grade_;
}

void Bureaucrat::decrementGrade() {
	if (grade_ >= 150)
		throw Bureaucrat::GradeTooLowException();
	++grade_;
}


// Getters

const std::string& Bureaucrat::getName() const {
	return name_;
}

int Bureaucrat::getGrade() const {
	return grade_;
}

// Exception classes

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}
