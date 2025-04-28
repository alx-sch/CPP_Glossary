/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:33:35 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/28 10:51:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
A fixed-point is just an integer here you pretend some bits are after
a decimal point.
The last 8 bits are the fractional part, and the rest is the integer part
(int got 32 bits, so 32 - 8 = 24 bits for the integer part).

8 bits can represent 256 values, so the range of the fractional part is
(0/256 to 255/256) -> (0/256 to 255/256); where 255/256 equals 0.99609375.
 */

#include <iostream>
#include <cmath>		// for roundsf()
#include "Fixed.hpp"

// Constructors and Destructor

Fixed::Fixed() : fp_val(0) {
	std::cout << "Default constructor called\n";
}

// Integer value is shifted left by 8 bits to make space for the fractional part.
// Shifting left by 8 bits is equivalent to multiplying by 256 (2^8).
Fixed::Fixed(int const val) : fp_val(val << fract_bits) {
	std::cout << "Int constructor called\n";
}

// Bit-wise shifting is only valid for integers.
// The float value is multiplied by 256 (1<<8) to convert it to fixed-point representation.
// roundf() is used to round the float value to the nearest integer.
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

// Right-shift the fixed-point value by 8 bits to convert it to an integer.
// Basically: int = fixed-point value / 256
int		Fixed::toInt() const {
	return fp_val >> fract_bits;
}

// Divide the fixed-point value by 256 (1<<8) to convert it to a float.
// static_cast<float>(fp_val): C++ type casting.
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
