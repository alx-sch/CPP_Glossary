#pragma once

class	Fixed {
	private:
		int					fp_val;
		static int const	fract_bits = 8; // `static` makes the var class-level rather than instance-level (the same for all instances).

	public:
		// Constructors and Destructor
		
		Fixed();					// default constructor
		Fixed(const Fixed &other);	// copy constructor
		Fixed(int const val);		// constructor with int parameter
		Fixed(float const val);		// constructor with float parameter
		~Fixed();					// deconstructor

		// Cpoy Assignment operator
		Fixed	&operator=(const Fixed &other);

		// Conversion functions
		
		float	toFloat() const;
		int		toInt() const;
			
		// Getters and Setters
		
		int		getRawBits() const;
		void	setRawBits(int const raw);
};

/**
Operator overloading - "This is how to print Fixed objects"
Not in the class definition since left-hand side of `<<` is a `std::ostream`, not a `Fixed`.
`std::cout << a;`, where `a` is a `Fixed` object.

`std::ostream &out`: output stream (e.g., `std::cout`, `std::ofstream`)
`const Fixed &fixed`: the `Fixed` object to be outputted
*/
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed); 
