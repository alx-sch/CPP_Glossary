/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:07:13 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/20 17:21:19 by aschenk          ###   ########.fr       */
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

