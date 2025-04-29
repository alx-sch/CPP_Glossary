/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:05:00 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/29 20:05:33 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Copy Constructor --> "Make a clone from this one"
Fixed::Fixed(const Fixed &other)

Create a new `Fixed` object by copying from `other`, which is a reference
to another existing `Fixed` object.
Also copies internal data from `other` to new object.

Fixed a;
Fixed b = a; // a is `other`, copy constructor is called here

→ creates b from a

***

Copy Assignment Operator --> "Take on their values!"
Fixed &operator=(const Fixed &other)

`operator=` to overload the assignment operator for `Fixed` class.

Assigning the value of `other` (`Fixed` object) to

Fixed a;
Fixed b;
b = a;       // a is `other`, copy assignment operator is called here

→ copies a into b

*/

#pragma once

class	Fixed {
	private:
		int					fp_val;
		static int const	fract_bits = 8; // `static` makes the var class-level rather than instance-level (the same for all instances).

	public:
		Fixed();					// default constructor
		Fixed(const Fixed &other);	// copy constructor
		~Fixed();					// deconstructor

		Fixed	&operator=(const Fixed &other); // copy assignment operator

		int		getRawBits() const;
		void	setRawBits(int const raw);
};
