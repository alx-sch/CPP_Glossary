/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:04:26 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/21 19:28:17 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Form; // Forward declaration to avoid circular dependency
# include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string	name_;
		int					grade_;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		///////

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form& form);

		///////

		const std::string&	getName() const;
		int					getGrade() const;

		// Inheriting from std::exception: virtual destructor and virtual: const char* what() const throw()
		// throw() guarantees that the function itself will not throw any exceptions

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
