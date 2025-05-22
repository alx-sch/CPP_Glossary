#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "string"
# include "../include/AForm.hpp"
# include "../include/Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target_;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		///////

		void execute(Bureaucrat const &executor) const;
};

#endif
