#include <iostream>
#include "../include/Animal.hpp"
#include "../include/AAnimal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

int	main ()
{

	//const AAnimal*	beta = new AAnimal(); // Compilation error: cannot instantiate abstract class
	const Animal*	meta = new Animal(); // Compilation error: cannot instantiate abstract class
	const AAnimal*	j = new Dog();
	const AAnimal*	i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;

	return 0;
}
