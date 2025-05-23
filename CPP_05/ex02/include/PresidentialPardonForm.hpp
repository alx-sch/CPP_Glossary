#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "string"

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
 * @param target	The target for the form
 */
class	PresidentialPardonForm : public AForm
{
	private:
		std::string	target_;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

		/////// Member functions

		void	printStatus(std::ostream& os) const;
		void	executeAction() const;

		/////// Getters

		std::string	getTarget() const;
};

#endif
