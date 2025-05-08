/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:00:29 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/08 15:25:09 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	private:
		static const unsigned int	MAX_IDEAS = 100;
		std::string					ideas_[MAX_IDEAS];

	public:
		Brain();
		Brain(const Brain& other);
		~Brain();

		Brain&	operator=(const Brain& other);

		void		setIdea(unsigned int index, const std::string& idea);
		std::string	getIdea(unsigned int index) const;
};

#endif
