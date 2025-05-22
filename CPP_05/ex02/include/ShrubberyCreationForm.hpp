#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>

# include "../include/AForm.hpp"
# include "../include/Bureaucrat.hpp"

/**
 * Creates a shrubbery in the form of ASCII art and writes it to a file. 
 * The form is signed by a Bureaucrat and can be executed by another Bureaucrat. 
 * Inherits from AForm. 
 * 
 * Grade required to sign:		145; 
 * Grade required to execute:	137.
 *
 * @param target	The target for the form
 */
class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target_;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

		///////

		void	printStatus(std::ostream& os) const;
		void	execute(Bureaucrat const &executor) const;
};

#endif
