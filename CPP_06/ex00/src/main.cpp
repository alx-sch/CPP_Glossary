#include "../include/ScalarConverter.hpp"
#include "../include/utils.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <value>\n";
		return 1;
	}

	std::string	input = process(argv[1]);
	ScalarConverter::convert(input);

	return 0;
}
