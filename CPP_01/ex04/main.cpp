/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:12:42 by aschenk           #+#    #+#             */
/*   Updated: 2025/04/23 17:11:13 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>    // For strerror
#include <fstream>    // For file I/O
#include <iostream>
#include <sstream>    // For stringstream

std::string	replaceAll(std::string content, std::string s1, std::string s2);

int	main(int argc, char **argv) {
	// Parameter check
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>\n";
		return 1;
	}

	// Open filestream
	std::ifstream input(argv[1]);
	if (!input) {
		std::cerr << "Error opening file '" << argv[1] << "': " << strerror(errno) << std::endl;
		return 1;
	}

	// Load file content into a string
	std::ostringstream	oss;
	oss << input.rdbuf(); // reads entire content of 'input' and stores it in 'oss'
	std::string	content = oss.str(); // extracts full string from stream buffer
	input.close();

	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	// An empty string would match at every position.
	if (s1.empty()) {
		std::cerr << "Error: string1 must not be empty.\n";
		return 1;
	}

	std::string replaced = replaceAll(content, s1, s2);

	// Load 'replaced' string into output file.
	std::ofstream output((std::string(argv[1]) + ".replace").c_str()); // In C++98, std::ofstream only takes a const char* as the filename argument
	if (!output) {
		std::cerr << "Error: cannot open output file.\n";
		return 1;
	}
	output << replaced;
	output.close();

	return 0;
}
