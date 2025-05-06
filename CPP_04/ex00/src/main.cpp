/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:11:07 by aschenk           #+#    #+#             */
/*   Updated: 2025/05/06 15:52:16 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

int	main ()
{
	{ // Subject Test
		std::cout	<< "\n=================== \n"
					<< "== Subject Test == \n"
					<< "=================== \n\n";

		const Animal*	meta = new Animal();
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound(); //will output the dog sound!
		meta->makeSound(); //will output the animal sound!

		delete meta;
		delete i;
		delete j;
	}
	// {
	// 	std::cout	<< "\n=================== \n"
	// 				<< "== Wrong Test == \n"
	// 				<< "=================== \n\n";

	// 	const WrongAnimal*	meta = new WrongAnimal();
	// 	const WrongAnimal*	j = new WrongDog();
	// 	const WrongAnimal*	i = new WrongCat();

	// 	std::cout << j->getType() << " " << std::endl;
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound(); //will output the cat sound!
	// 	j->makeSound(); //will output the dog sound!
	// 	meta->makeSound(); //will output the animal sound!

	// 	delete meta;
	// 	delete i;
	// 	delete j;

	// }
	// // Create an array of Animal pointers
	// Animal*	animals[4];

	// // Fill the array with Cat and Dog objects
	// for (int i = 0; i < 2; ++i) {
	// 	animals[i] = new Cat();
	// }
	// for (int i = 2; i < 4; ++i) {
	// 	animals[i] = new Dog();
	// }

	// // Call makeSound() on each animal
	// for (int i = 0; i < 4; ++i) {
	// 	animals[i]->makeSound();
	// }

	// // Clean up
	// for (int i = 0; i < 4; ++i) {
	// 	delete animals[i];
	// }

	return 0;
}
