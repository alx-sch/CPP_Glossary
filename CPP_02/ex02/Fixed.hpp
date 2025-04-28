/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:57:26 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/28 16:55:18 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class	Fixed {
	private:
		int					fp_val;
		static int const	fract_bits = 8;	// `static` makes the var class-level rather than instance-level (the same for all instances).

	public:
		// Constructors and Destructor
		
		Fixed();					// default constructor
		Fixed(const Fixed &other);	// copy constructor
		Fixed(int const val);		// constructor with int parameter
		Fixed(float const val);		// constructor with float parameter
		~Fixed();					// deconstructor

		// Copy Assignment Operator
		Fixed	&operator=(const Fixed &other);

		// Comparison Operators

		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		// Arithmetic Operators

		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		// Increment/Decrement Operators

		Fixed	&operator++();		// ++i; increment obj immediately
		Fixed	&operator--();		// --i
		Fixed	operator++(int);	// i++; int is dummy (C++ specification to tell compilter: post-increment).
		Fixed	operator--(int);	 // i--

		// Min/Max Functions

		static	Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		// Conversion Functions
		
		float	toFloat() const;
		int		toInt() const;
			
		// Getters and Setters
		
		int		getRawBits() const;
		void	setRawBits(int const raw);
};

/**
Operator overloading - "This is how to print Fixed objects"
Not in the class definition since left-hand side of `<<` is a `std::ostream`, not a `Fixed`.
`std::cout << a;`, where `a` is a `Fixed` object.

`std::ostream &out`: output stream (e.g., `std::cout`, `std::ofstream`)
`const Fixed &fixed`: the `Fixed` object to be outputted
*/
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed); 
