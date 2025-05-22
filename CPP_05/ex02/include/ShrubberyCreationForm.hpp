#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "../include/AForm.hpp"
# include "../include/Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target_;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		///////

		void execute(Bureaucrat const &executor) const;
};

#endif
