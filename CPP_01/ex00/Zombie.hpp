#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie {
	public: 
		Zombie(std::string zombieName);
		~Zombie();

		void		announce();

	private:
		std::string	name;
};

#endif
