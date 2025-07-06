#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class	RPN
{
	private:
		// Prevent instantiation, copying, assignment --> Utility / static class
		RPN();
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);
		~RPN();

	public:
		static double	calculate(const std::string &expression);
};

#endif
