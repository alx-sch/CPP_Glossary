#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "../include/Animal.hpp"
# include "../include/Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	brain_;

	public:
		Cat();
		Cat(const Cat& other);
		~Cat();

		Cat&	operator=(const Cat& other);

		void	makeSound() const;	// Override Animal's makeSound()

		Brain*	getBrain() const;
};

#endif
