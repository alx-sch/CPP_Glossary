#include <iostream>
#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

int	main ()
{
	{ // Subject Test
		std::cout	<< "\n================== \n"
					<< "== Subject Test == \n"
					<< "================== \n\n";

		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << std::endl;

		delete j;//should not create a leak
		delete i;
	}
	{	// Testing constructors 
		std::cout	<< "\n====================== \n"
					<< "== Constructor Test == \n"
					<< "====================== \n\n";

		Cat cat1;
		std::cout << std::endl;

		Cat cat2(cat1);
		std::cout << std::endl;

		cat1 = cat2;
		std::cout << std::endl;

		Dog dog1;
		std::cout << std::endl;

		Dog dog2(dog1);
		std::cout << std::endl;

		dog1 = dog2;
		std::cout << std::endl;
		
		cat1.makeSound();
		cat2.makeSound();

		std::cout << std::endl;
		
		dog1.makeSound();
		dog2.makeSound();

		std::cout << std::endl;
		// Destructor calls as going out of scope and objects are on the stack.
	}
	{ // Testing Brain (Deep Copy)
		std::cout	<< "\n======================== \n"
					<< "== Brain / Array Test == \n"
					<< "======================== \n\n";

		const int	NUM_ANIMALS = 4;
		Animal*		animals[NUM_ANIMALS];

		// Assigning half Dog and half Cat to the array
		for (int i = 0; i < NUM_ANIMALS; ++i) {
			std::cout	<< "Creating animals[" << i << "]...\n";
			if (i < NUM_ANIMALS / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
			std::cout << std::endl;
		}

		// Let animals make sound
		for (int i = 0; i < NUM_ANIMALS; ++i) {
			std::cout	<< "animals[" << i << "]: ";
			animals[i]->makeSound();
		}

		std::cout << std::endl;

		// Setting two ideas for each dog
		static_cast<Dog*>(animals[0])->getBrain()->setIdea(0, "Eat the bone"); // Need to cast as Animal does not have a brain
		static_cast<Dog*>(animals[0])->getBrain()->setIdea(1, "Eat the cat");
		static_cast<Dog*>(animals[1])->getBrain()->setIdea(0, "Fetch the ball");
		static_cast<Dog*>(animals[1])->getBrain()->setIdea(1, "Fetch the stick");

		// Setting two ideas for each cat
		static_cast<Cat*>(animals[2])->getBrain()->setIdea(0, "Eat the fish"); // Could cast to Dog, just any class that has a brain
		static_cast<Cat*>(animals[2])->getBrain()->setIdea(1, "Eat the mouse");
		static_cast<Cat*>(animals[3])->getBrain()->setIdea(0, "Chase the laser");
		static_cast<Cat*>(animals[3])->getBrain()->setIdea(1, "Chase the string");

		// Printing ideas for each animal
		for (int i = 0; i < NUM_ANIMALS; ++i) {
			std::cout << "animals[" << i << "]'s ideas:\n";

			Brain* brain = NULL;
			brain = static_cast<Dog*>(animals[i])->getBrain(); // Need to cast to Dog OR Cat to access Brain

			if (brain) {
				for (int j = 0; j < 2; ++j) { // just print first 2 ideas to avoid spamming
					std::cout << "  Idea " << j << ": " << brain->getIdea(j) << "\n";
				}
			}
			std::cout << std::endl;
		}

		// Give ideas from one animal to another
		std::cout << "Copying animal[0] into animal[1]...\n";
		*static_cast<Dog*>(animals[1]) = *static_cast<Dog*>(animals[0]);
		
		std::cout << std::endl;

		std::cout << "Copying animal[2] into animal[3]...\n";
		*static_cast<Cat*>(animals[2]) = *static_cast<Cat*>(animals[3]);

		// Printing ideas for each animal again
		for (int i = 0; i < NUM_ANIMALS; ++i) {
			std::cout << std::endl;
			std::cout << "animals[" << i << "]'s ideas:\n";

			Brain* brain = NULL;
			brain = static_cast<Dog*>(animals[i])->getBrain();

			if (brain) {
				for (int j = 0; j < 2; ++j) { // just print first 2 ideas to avoid spamming
					std::cout << "  Idea " << j << ": " << brain->getIdea(j) << "\n";
				}
			}
		}

		// Give animals[0] and [2] different ideas
		std::cout	<< std::endl;
		std::cout	<< "Giving animals[0] and [2] different ideas.\n"
					<< "animals[1] and [3] should still have the same ideas as before\n"
					<< "(deep copy, not just pointers!).\n";
		static_cast<Dog*>(animals[0])->getBrain()->setIdea(0, "Bark at the mailman");
		static_cast<Dog*>(animals[0])->getBrain()->setIdea(1, "Bark at the doorbell");
		static_cast<Cat*>(animals[2])->getBrain()->setIdea(0, "Scratch the couch");
		static_cast<Cat*>(animals[2])->getBrain()->setIdea(1, "Scratch the carpet");

		// Printing ideas for each animal again
		for (int i = 0; i < NUM_ANIMALS; ++i) {
			std::cout << std::endl;
			std::cout << "animals[" << i << "]'s ideas:\n";

			Brain* brain = NULL;
			brain = static_cast<Dog*>(animals[i])->getBrain();

			if (brain) {
				for (int j = 0; j < 2; ++j) { // just print first 2 ideas to avoid spamming
					std::cout << "  Idea " << j << ": " << brain->getIdea(j) << "\n";
				}
			}
		}
		
		// Deleting animals
		for (int i = 0; i < NUM_ANIMALS; ++i) {
			std::cout << std::endl;
			std::cout	<< "Deleting animals[" << i << "]...\n";
			delete animals[i];
			animals[i] = NULL;
		}
	}

	return 0;
}
