#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>

# include "../include/AForm.hpp"
# include "../include/Bureaucrat.hpp"

/**
 * Grants a presidential pardon to a target.
 * The form is signed by a Bureaucrat and can be executed by another Bureaucrat.
 * Inherits from AForm.
 * 
 * Grade required to sign:		25;
 * Grade required to execute:	5.
 * 
 * @param target_ 	The target of the presidential pardon.
 */
class	PresidentialPardonForm : public AForm
{
	private:
		std::string	target_;

	public:
		PresidentialPardonForm();
		explicit PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		/////// Member functions

		void	executeAction() const;
		void	printStatus(std::ostream& os) const;

		// Getters

		std::string	getTarget() const;
};

#endif
