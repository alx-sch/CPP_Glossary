#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "../include/Animal.hpp"
# include "../include/Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	brain_;

	public:
		Dog();
		Dog(const Dog& other);
		~Dog();

		Dog&	operator=(const Dog& other);

		void	makeSound() const;

		Brain*	getBrain() const;
};	

#endif
