#include <iostream>

int	main() {
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string	&stringREF = string;

	// Print address
	std::cout << "string address is:   '" << &string << "'\n";
	std::cout << "stringPTR points to: '" << stringPTR << "'\n";
	std::cout << "stringREF refers to: '" << &stringREF << "'\n";

	std::cout << std::endl;

	// Print value
	std::cout << "string value is:     '" << string << "'\n";
	std::cout << "value via stringPTR: '" << *stringPTR << "'\n";
	std::cout << "value via stringREF: '" << stringREF << "'\n";

	return 0;
}
