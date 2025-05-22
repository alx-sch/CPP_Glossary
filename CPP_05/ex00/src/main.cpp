#include <iostream>
#include "../include/Bureaucrat.hpp"

#define RED		"\033[31m"
#define BLUE	"\033[34m"
#define RESET	"\033[0m"

int main()
{
	{
		std::cout << "---------- Testing Contructors ---------\n\n";

		Bureaucrat deffy;
		std::cout << deffy << std::endl;

		Bureaucrat jim("Jim", 2);
		Bureaucrat cpy(jim);
		std::cout << cpy << std::endl;

		Bureaucrat kevin("Kevin", 150);
		std::cout << kevin << std::endl;
		kevin = jim;
		std::cout << kevin << std::endl;
	}

	std::cout << "\n-------- Testing Exceptions ------------\n\n";

	try {
		// Grade too high (0)
		Bureaucrat b2("Jim", 0);  // This should throw
		// Jump immediately to catch block when exception is thrown
		// Below is not executed
		std::cout << b2 << std::endl;
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
		std::cout << b4 << std::endl;

		b4.incrementGrade();  // Grade becomes 1
		std::cout << "After increment: " << b4 << std::endl;

		b4.incrementGrade();  // Grade would become 0 → should throw
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << RED << "Exception caught during increment: " << e.what() << RESET << std::endl;
	}

	std::cout << "----------------------------------------\n";

	try {
		Bureaucrat b5("Stanley", 149);
		std::cout << b5 << std::endl;

		b5.decrementGrade();  // Grade becomes 150
		std::cout << "After decrement: " << b5 << std::endl;

		b5.decrementGrade();  // Grade becomes 151 → should throw
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << BLUE << "Exception caught during decrement: " << e.what() << RESET << std::endl;
	}

	return 0;
}
