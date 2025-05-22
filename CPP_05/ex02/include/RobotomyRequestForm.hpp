#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "../include/AForm.hpp"
# include "../include/Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target_;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		///////

		void execute(Bureaucrat const &executor) const;
};

#endif
