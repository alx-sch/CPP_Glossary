/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceAll.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:12:41 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 15:47:59 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

// Replaces all occurrences of `s1` in `content` with `s2`.
// Returns a new string with the replacements applied.
std::string replaceAll(std::string content, std::string s1, std::string s2) {
	std::string	result;
	size_t		pos = 0;
	size_t		found;

	while (true) {
		found = content.find(s1, pos); // find the position of match
		// std::string::npos is a constant static member, representing the largest possible value of 'size_t'
		if (found == std::string::npos) { 
			break; // exit the loop if no match is found
		}
		
		// copy up to match
		result.append(content, pos, found - pos);
		
		// add replacement
		result += s2;
		
		// move past the match
		pos = found + s1.length();
	}
	result.append(content, pos); // add remaining part
	
	return result;
}
