#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class	ScalarConverter
{
	private: // Constructors and destructors private to prevent instantiation
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
		~ScalarConverter();
	
	public:
		static void	convert(const std::string& input);
};

#endif
