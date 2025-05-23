#include <iostream>

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define RESET	"\033[0m"

int main()
{
	std::cout << YELLOW << "\n---------- Testing Shrubbery ---------\n\n" << RESET;
	try {			
		Bureaucrat	intern;
		Bureaucrat	manager("Mia", 100);
		std::cout << std::endl;

		ShrubberyCreationForm	shrub("bathtub");
		std::cout << shrub << std::endl;

		std::cout << intern.getName() << " tries to execute " << shrub.getName() << "...\n";
		intern.executeForm(shrub);

		std::cout << std::endl << intern.getName() << " tries to sign " << shrub.getName() << "...\n";
		intern.signForm(shrub);

		std::cout << std::endl << manager.getName() << " tries to sign " << shrub.getName() << "...\n";
		manager.signForm(shrub);

		std::cout << std::endl << intern.getName() << " tries to execute " << shrub.getName() << "...\n";
		intern.executeForm(shrub);

		std::cout << std::endl << intern << std::endl;
		std::cout << intern.getName() << " gets a promotion!\n";
		for (int i = 0; i < 15; ++i)
				intern.incrementGrade();
		Bureaucrat	junior(intern); // Promote intern to junior ;) intern should ideally go out of scope here, but oh well
		std::cout << junior << std::endl;

		std::cout << std::endl << junior.getName() << " tries to execute " << shrub.getName() << "...\n";
		junior.executeForm(shrub);

		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "\n--------- Testing Robotomy ---------\n\n" << RESET;
	try {
		Bureaucrat	genius("Dr. Egghead", 30);
		Bureaucrat	greaseMonkey("Bob the Builder", 50);
		std::cout << std::endl;

		RobotomyRequestForm	robot("Duck");
		std::cout << robot << std::endl;

		std::cout << greaseMonkey.getName() << " tries to execute " << robot.getName() << "...\n";
		greaseMonkey.executeForm(robot);

		std::cout << std::endl << greaseMonkey.getName() << " tries to sign " << robot.getName() << "...\n";
		greaseMonkey.signForm(robot);

		std::cout << std::endl << greaseMonkey.getName() << " tries to execute " << robot.getName() << "...\n";
		greaseMonkey.executeForm(robot);

		std::cout << std::endl << genius.getName() << " tries to execute " << robot.getName() << "...\n";
		genius.executeForm(robot);

		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "\n--------- Testing Pres Pardon ---------\n\n" << RESET;
	try {
		Bureaucrat	president("Donald", 1);
		Bureaucrat	vice("JD", 33);
		std::cout << std::endl;

		PresidentialPardonForm	pardon;
		std::cout << pardon << std::endl;

		std::cout << vice.getName() << " tries to execute " << pardon.getName() << "...\n";
		vice.executeForm(pardon);
		std::cout << std::endl << vice.getName() << " tries to sign " << pardon.getName() << "...\n";
		vice.signForm(pardon);

		std::cout << std::endl << president.getName() << " tries to execute " << pardon.getName() << "...\n";
		president.signForm(pardon);
		std::cout << std::endl;
		std::cout << president.getName() << " tries to execute " << pardon.getName() << "...\n";
		president.executeForm(pardon);
		std::cout << std::endl;

		// This would segfault if exception wouldn't be caught below
		Bureaucrat	dummy("dummy", 999);
	}
	catch (std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}

	return 0;
}
