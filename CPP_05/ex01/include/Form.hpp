#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;
# include "Bureaucrat.hpp"

/**
 * Represents a bureaucratic form requiring signing and execution grades.
 * 
 * A Form can be signed by a Bureaucrat whose grade is high enough.
 * The grade range is 1 (highest) to 150 (lowest).
 * 
 * @param name The name of the form
 * @param sign_grade The required grade to sign the form (1 = highest)
 * @param exec_grade The required grade to execute the form (1 = highest)
 * 
 * @throws Form::GradeTooHighException if sign_grade or exec_grade < 1
 * @throws Form::GradeTooLowException if sign_grade or exec_grade > 150
 */
class Form
{
	private:
		const std::string	name_;
		bool				is_signed_;
		const int			sign_grade_;
		const int			exec_grade_;

	public:
		Form();
		Form(const std::string& name, int sign_grade, int exec_grade);
		Form(const Form& other);
		virtual ~Form();

		Form&	operator=(const Form& other);

		///////

		void	beSigned(const Bureaucrat& bureaucrat);

		///////

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		///////

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
