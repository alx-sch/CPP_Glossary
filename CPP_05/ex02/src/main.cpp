#include <iostream>

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"

#define RED		"\033[31m"
#define RESET	"\033[0m"

int main()
{
	try {
		Bureaucrat	intern;
		Bureaucrat	manager("Mia", 100);
		Bureaucrat	vice("JD", 50);
		Bureaucrat	president("Donald", 1);
		std::cout << std::endl;

		std::cout << "---------- Testing Shrubbery ---------\n\n";

		ShrubberyCreationForm	shrub("bathtub");
		std::cout << shrub << std::endl;

		std::cout << std::endl << intern.getName() << " tries to execute " << shrub.getName() << "...\n";
		shrub.execute(intern);

		std::cout << std::endl << intern.getName() << " tries to sign " << shrub.getName() << "...\n";
		intern.signForm(shrub);

		std::cout << std::endl << manager.getName() << " tries to sign " << shrub.getName() << "...\n";
		manager.signForm(shrub);

		std::cout << std::endl << intern.getName() << " tries to execute " << shrub.getName() << "...\n";
		shrub.execute(intern);

		std::cout << std::endl << intern << std::endl;
		std::cout << intern.getName() << " gets a promotion!\n";
		for (int i = 0; i < 15; ++i)
			intern.incrementGrade();
		Bureaucrat	junior(intern);
		std::cout << junior << std::endl;

		std::cout << std::endl << junior.getName() << " tries to execute " << shrub.getName() << "...\n";
		shrub.execute(junior);


		std::cout << std::endl;
	}
	catch (std::exception& e) {
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	return 0;
}
