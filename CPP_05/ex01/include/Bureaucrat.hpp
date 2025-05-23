#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Form;
# include "Form.hpp"

/**
 * Represents a bureaucrat with a name and a grade. 
 * 
 * A Bureaucrat can sign forms and has a grade ranging from 1 (highest) to 150 (lowest).
 * 
 * @param name_ 	The name of the bureaucrat
 * @param grade_ 	The grade of the bureaucrat (1 = highest)
 * 
 * @throws	GradeTooHighException if grade < 1
 * @throws	GradeTooLowException if grade > 150
 */
class	Bureaucrat
{
	private:
		const std::string	name_;
		int					grade_;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();

		/////// Member functions

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form& form);

		/////// Getters

		const std::string&	getName() const;
		int					getGrade() const;

		/////// Exceptions

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
