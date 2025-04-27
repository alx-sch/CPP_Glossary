/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:33:35 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/24 17:00:34 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : fp_val(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called\n";
	*this = other; // Overloaded assignment operator, calls copy assignment operator
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {  // Avoid self-assignment and unnecessary operations
		fp_val = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

////

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return fp_val;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << raw << "Destructor called\n";
}
