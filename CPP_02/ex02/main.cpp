/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:57:16 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/28 17:28:59 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	// SUBJECT MAIN
	// {
	// 	Fixed			a;
	// 	Fixed const		b( Fixed( 5.05f ) * Fixed( 2 ) );

	// 	std::cout << a << std::endl;
	// 	std::cout << ++a << std::endl;
	// 	std::cout << a << std::endl;
	// 	std::cout << a++ << std::endl;
	// 	std::cout << a << std::endl;

	// 	std::cout << b << std::endl;
		
	// 	std::cout << Fixed::max( a, b ) << std::endl;
	// }
	// OWN TESTS
	{
		// Test default constructor
		Fixed	f1;
		std::cout << "f1 (default constructor): " << f1 << std::endl;

		// Test int constructor
		Fixed	f2(42);
		std::cout << "f2 (int constructor): " << f2 << std::endl;

		// Test float constructor
		Fixed	f3(10.5f);
		std::cout << "f3 (float constructor): " << f3 << std::endl;

		// Test copy constructor
		Fixed	f4(f3);
		std::cout << "f4 (copy constructor): " << f4 << std::endl;

		// Test assignment operator
		Fixed	f5;
		f5 = f4;
		std::cout << "f5 (after assignment from f4): " << f5 << std::endl << std::endl;

		// Test pre-increment and post-increment
		std::cout << "Pre-increment f5: " << ++f5 << std::endl;
		std::cout << "Post-increment f5: " << f5++ << std::endl;
		std::cout << "f5 after post-increment: " << f5 << std::endl;

		// Test pre-decrement and post-decrement
		std::cout << "Pre-decrement f5: " << --f5 << std::endl;
		std::cout << "Post-decrement f5: " << f5-- << std::endl;
		std::cout << "f5 after post-decrement: " << f5 << std::endl<< std::endl;


		// Test arithmetic operators
		std::cout << "f5 + f4: " << (f5 + f4) << std::endl;
		std::cout << "f5 - f4: " << (f5 - f4) << std::endl;
		std::cout << "f5 * f4: " << (f5 * f4) << std::endl;
		std::cout << "f5 / f4: " << (f5 / f4) << std::endl << std::endl;

		// Test comparison operators
		std::cout << "f5 == f4: " << (f5 == f4) << std::endl;
		std::cout << "f5 != f4: " << (f5 != f4) << std::endl;
		std::cout << "f5 < f4: " << (f5 < f4) << std::endl;
		std::cout << "f5 > f4: " << (f5 > f4) << std::endl;
		std::cout << "f5 <= f4: " << (f5 <= f4) << std::endl;
		std::cout << "f5 >= f4: " << (f5 >= f4) << std::endl << std::endl;

		// Test conversion to float
		std::cout << "f5 as float: " << f5.toFloat() << std::endl;

		// Test conversion to int
		std::cout << "f5 as int: " << f5.toInt() << std::endl << std::endl;

		// Test max/min functions
		std::cout << "Max of f5 and f2: " << Fixed::max(f5, f2) << std::endl;
		std::cout << "Min of f5 and f2: " << Fixed::min(f5, f2) << std::endl << std::endl;

		const Fixed	f6(42.42f);
		std::cout << "const f6: " << f6 << std::endl;
			
		// Test static methods
		std::cout << "Max (using static method) between f5 and f6: " << Fixed::max(f5, f6) << std::endl;
		std::cout << "Min (using static method) between f5 and f6: " << Fixed::min(f5, f6) << std::endl;
	}

	return 0;
}
