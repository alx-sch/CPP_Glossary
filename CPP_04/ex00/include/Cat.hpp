#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "../include/Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		~Cat();

		Cat&	operator=(const Cat& other);

		void	makeSound() const;	// Override Animal's makeSound()
};

#endif
