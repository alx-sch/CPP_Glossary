#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string	type_;

	public:
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();

		Animal&	operator=(const Animal& other);

		virtual void	makeSound() const;	// virtual, so derived class' call through base class
											// will call derived class' function
		std::string		getType() const;
};

#endif
