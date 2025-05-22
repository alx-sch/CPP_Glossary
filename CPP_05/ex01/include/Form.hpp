#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat; // Forward declaration to avoid circular dependency
# include "Bureaucrat.hpp"

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
