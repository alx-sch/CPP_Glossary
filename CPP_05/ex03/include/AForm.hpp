#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;
# include "Bureaucrat.hpp"

/**
 * ABSTRACT CLASS; 
 * Represents a bureaucratic form requiring signing and execution grades. 
 * 
 * A Form can be signed by a Bureaucrat whose grade is high enough. 
 * The grade range is 1 (highest) to 150 (lowest).
 * 
 * @param name_ 		The name of the form
 * @param sign_grade_ 	The required grade to sign the form (1 = highest)
 * @param exec_grade_ 	The required grade to execute the form (1 = highest)
 * @param target_ 		The target for the form
 * 
 * @throws	GradeTooHighException if sign_grade or exec_grade < 1
 * @throws	GradeTooLowException if sign_grade or exec_grade > 150
 * @throws	NotSignedException if the form is not signed when executing
 */
class	AForm
{
	private:
		const std::string	name_;
		bool				is_signed_;
		const int			sign_grade_;
		const int			exec_grade_;

	protected:
		std::string			target_;

		// Constructor is protected to prevent instantiation of abstract class
		AForm(const std::string& name, int sign_grade, int exec_grade, const std::string& target);

	public:
		AForm();
		AForm(const std::string& name, int sign_grade, int exec_grade);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual ~AForm();

		/////// Member functions

		void			beSigned(const Bureaucrat& bureaucrat);
		void			execute(Bureaucrat const &executor) const;
		virtual void	printStatus(std::ostream& os) const = 0;
		virtual void	executeAction() const = 0;

		/////// Getters

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		std::string	getTarget() const;

		/////// Exceptions

		class	GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class	NotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
