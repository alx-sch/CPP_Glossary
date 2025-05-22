#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal
{
	protected:
		std::string	type_;

	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		virtual ~AAnimal();

		AAnimal&	operator=(const AAnimal& other);

		virtual void	makeSound() const = 0;	// Pure virtual → abstract class
		std::string		getType() const;
};

#endif
