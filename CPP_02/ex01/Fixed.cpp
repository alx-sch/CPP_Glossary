/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:33:35 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/27 21:39:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>		// for roundsf()
#include "Fixed.hpp"

// Constructors and Destructor

Fixed::Fixed() : fp_val(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const val) : fp_val(val << fract_bits) {
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const val) : fp_val(roundf(val * (1 << fract_bits))) {
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called\n";
	*this = other; // Calling copy assignment operator 
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

// Operator overloading

Fixed	&Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {  // Avoid self-assignment and unnecessary operations
		setRawBits(other.getRawBits());
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

// Conversion functions

int		Fixed::toInt() const {
	return fp_val >> fract_bits;
}

float	Fixed::toFloat() const {
	return static_cast<float>(fp_val) / (1 << fract_bits);
}

// Getters and Setters

int		Fixed::getRawBits() const {
	return fp_val;
}

void	Fixed::setRawBits(int const raw) {
	fp_val = raw;
}
