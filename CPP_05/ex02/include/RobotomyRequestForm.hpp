#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>

# include "../include/AForm.hpp"
# include "../include/Bureaucrat.hpp"

/**
 * The form is signed by a Bureaucrat and can be executed by another Bureaucrat.
 * Robotomizes a target with a 50% success rate. 
 * Inherits from AForm. 
 * 
 * Grade required to sign:		72; 
 * Grade required to execute:	45.
 * 
 * @param target_ 	The target of the robotomy request.
 */
class	RobotomyRequestForm : public AForm
{
	private:
		std::string	target_;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

		/////// Member functions

		void	executeAction() const;
		void	printStatus(std::ostream& os) const;

		// Getters

		std::string	getTarget() const;
};

#endif
