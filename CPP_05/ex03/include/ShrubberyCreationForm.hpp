#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>

# include "../include/AForm.hpp"
# include "../include/Bureaucrat.hpp"

# define NAME_SC	"Shrubbery Creation" // Default name of the form

/**
 * The form is signed by a Bureaucrat and can be executed by another Bureaucrat.
 * Creates a shrubbery in the form of ASCII art and writes it to a file. 
 * Inherits from AForm. 
 * 
 * Grade required to sign:		145; 
 * Grade required to execute:	137.
 * 
 * @param target_ 	The target of the shrubbery creation.
 */
class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	target_;

	public:
		ShrubberyCreationForm();
		explicit ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		/////// Member functions

		void	executeAction() const;
		void	printStatus(std::ostream& os) const;

		// Getters

		std::string	getTarget() const;
};

#endif
