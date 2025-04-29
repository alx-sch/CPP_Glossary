/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:43:27 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/29 20:02:28 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // for std::cout

/**
Converts a character to uppercase and prints it.

 @param c 	The character to convert and print.
*/
static void shout( char c )
{
	std::cout << (char)toupper(c);
}

/**
The entry point of the program.

If no arguments are provided, it outputs a default message.
If arguments are provided, it converts each character of each argument to
uppercase and prints them to the standard output.

 @param argc 	The number of command-line arguments (including the program name).
 @param argv 	An array of C-style strings representing the command-line arguments.

 @return 		`0` upon successful execution.
*/
int main( int argc, char **argv )
{
	int			i;
	size_t		j;
	std::string str; // std::string type manages memory automatically

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			str = std::string(argv[i]);
			for (j = 0; j < str.length(); j++)
			{
				shout(str[j]);
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
