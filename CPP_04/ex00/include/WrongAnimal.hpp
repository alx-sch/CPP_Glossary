#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
	protected:
		std::string	type_;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal& other);

		void		makeSound() const; // NOT virtual -> 'wrong' sound when 'wrong' cat calls it
		std::string	getType() const;
};

#endif
