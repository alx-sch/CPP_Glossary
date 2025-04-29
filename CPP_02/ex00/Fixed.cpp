/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:33:35 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/29 20:05:30 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : fp_val(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called\n";
	*this = other; // Calling copy assignment operator
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {  // Avoid self-assignment and unnecessary operations
		setRawBits(other.getRawBits());
	}
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return fp_val;
}

void	Fixed::setRawBits(int const raw) {
	fp_val = raw;
}
