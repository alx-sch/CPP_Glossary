/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:09:28 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 17:12:39 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#define RED		"\033[1;31m"	// ERROR
#define YELLOW	"\033[1;33m"	// WARNING
#define BLUE	"\033[34m"		// INFO
#define MAGENTA	"\033[35m" 		// DEBUG
#define RESET	"\033[0m"

class	Harl {
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();

	public:
		void	complain(std::string level);
};
