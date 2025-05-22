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
