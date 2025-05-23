#include <iostream>
#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

#define RED		"\033[31m"
#define RESET	"\033[0m"

int main()
{
	{
		std::cout << "---------- Testing Contructors ---------\n\n";

		Form	form1;
		std::cout << std::endl << form1 << std::endl << std::endl;

		Form	form2("Registration", 50, 100);
		Form	form3(form2);
		std::cout << std::endl << form3 << std::endl << std::endl;
	}

	std::cout << "\n-------- Testing Exceptions ------------\n\n";

	try {
		Bureaucrat	senior("Susy Senior", 42);
		Bureaucrat	junior("Jim Junior", 142);

		Form birthDayCard("Birthday Card", 145, 145);
		Form topSecretDocument("Top Secret Document", 50, 50);
		std::cout << std::endl;

		std::cout << senior << std::endl;
		std::cout << junior << std::endl;
		std::cout << std::endl;
		std::cout << birthDayCard << std::endl << std::endl;
		std::cout << topSecretDocument << std::endl;

		std::cout << std::endl << junior.getName() << " tries to sign " << birthDayCard.getName() << "...\n";
		junior.signForm(birthDayCard);
		std::cout << std::endl;
		std::cout << junior.getName() << " tries to sign " << topSecretDocument.getName() << "...\n";
		junior.signForm(topSecretDocument);
		std::cout << std::endl;
		std::cout << topSecretDocument << std::endl << std::endl;

		std::cout << senior.getName() << " tries to sign " << birthDayCard.getName() << "...\n";
		senior.signForm(birthDayCard);
		std::cout << std::endl;
		std::cout << senior.getName() << " tries to sign " << topSecretDocument.getName() << "...\n";
		senior.signForm(topSecretDocument);
		std::cout << topSecretDocument << std::endl;

		std::cout << "\n-- Creating a form with invalid grade --\n";
		Form invalidForm("Broken Form", 100, 151);  // should throw

		std::cout << "I won't be printed because error is thrown above\n";

	}
	catch (std::exception& e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}

	return 0;
}
