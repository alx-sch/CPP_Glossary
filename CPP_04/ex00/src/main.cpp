#include <iostream>
#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int	main ()
{
	{ // Subject Test
		std::cout	<< "\n================== \n"
					<< "== Subject Test == \n"
					<< "================== \n\n";

		const Animal*	meta = new Animal();
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		std::cout << std::endl;

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		std::cout << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound(); //will output the dog sound!
		meta->makeSound(); //will output the animal sound!

		std::cout << std::endl;

		delete meta;
		delete i;
		delete j;
	}
	{
		std::cout	<< "\n================ \n"
					<< "== Wrong Test == \n"
					<< "================ \n\n";

		const WrongAnimal*	meta = new WrongAnimal();
		const WrongAnimal*	i = new WrongCat();

		std::cout << std::endl;

		std::cout << i->getType() << " " << std::endl;
		
		std::cout << std::endl;
		
		i->makeSound(); // will output the WrongAnimal sound!
		meta->makeSound(); // will output the animal sound!

		std::cout << std::endl;

		delete meta;
		delete i;
	}

	return 0;
}
