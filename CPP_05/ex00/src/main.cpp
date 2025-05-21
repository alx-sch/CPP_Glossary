/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:58:54 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/21 15:10:52 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Bureaucrat.hpp"

#define RED		"\033[31m"
#define BLUE	"\033[34m"
#define RESET	"\033[0m"

int main()
{
	{
		std::cout << "---------- Testing Contructors ---------\n";

		Bureaucrat jim("Jim", 2);
		Bureaucrat cpy(jim);
		std::cout << "Name of cpy is '" << cpy.getName() << "' and grade is " << cpy.getGrade() << std::endl;

		Bureaucrat kevin("Kevin", 150);
		std::cout << "Name of kevin is '" << kevin.getName() << "' and grade is " << kevin.getGrade() << std::endl;
		kevin = jim;
		std::cout << "Name of kevin is '" << kevin.getName() << "' and grade is " << kevin.getGrade() << std::endl;
	}

	std::cout << "\n-------- Testing Exceptions ------------\n";

	try {
		Bureaucrat b1; // Default constructor
		std::cout << b1.getName() << " has grade " << b1.getGrade() << std::endl;
	
		// Grade too high (0)
		Bureaucrat b2("Jim", 0);  // This should throw
		// Jump immediately to catch block when exception is thrown
		// Below is not executed
		std::cout << b2.getName() << " has grade " << b2.getGrade() << std::endl;
	}
	// Catch an exception of type GradeTooHighException, passed as const reference 'e'
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << "----------------------------------------\n";

	try {
		// Grade too low (151)
		Bureaucrat b3("Kevin", 151);  // This should throw
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << BLUE << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << "----------------------------------------\n";

	try {
		Bureaucrat b4("Angela", 2);
		std::cout << b4.getName() << " starts with grade " << b4.getGrade() << std::endl;

		b4.incrementGrade();  // Grade becomes 1
		std::cout << "After increment: " << b4.getGrade() << std::endl;

		b4.incrementGrade();  // Grade would become 0 → should throw
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << RED << "Exception caught during increment: " << e.what() << RESET << std::endl;
	}

	std::cout << "----------------------------------------\n" << std::endl;

	try {
		Bureaucrat b5("Stanley", 149);
		std::cout << b5.getName() << " starts with grade " << b5.getGrade() << std::endl;

		b5.decrementGrade();  // Grade becomes 150
		std::cout << "After decrement: " << b5.getGrade() << std::endl;

		b5.decrementGrade();  // Grade becomes 151 → should throw
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << BLUE << "Exception caught during decrement: " << e.what() << RESET << std::endl;
	}

	return 0;
}
