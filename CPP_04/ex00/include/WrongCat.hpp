#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <string>
# include "../include/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		~WrongCat();

		WrongCat&	operator=(const WrongCat& other);

		void	makeSound() const; // Override WrongAnimal's makeSound()
};

#endif
