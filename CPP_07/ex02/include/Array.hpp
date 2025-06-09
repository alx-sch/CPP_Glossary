#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>		// for size_t
# include <exception>	// for std::exception

template <typename T>
class	Array
{
	private:
		T*				_array;		// Pointer to the array
		unsigned int	_size;		// Size of the array

	public:
		Array();
		explicit Array(unsigned int size); // 'explicit' prevents implicit conversions (Array a = 5; would not compile)
		Array(const Array<T>& other);
		Array<T>&		operator=(const Array<T>& other);
		~Array();

		T&				operator[](unsigned int index);
		const T&		operator[](unsigned int index) const;

		unsigned int	size() const;

		class	OutOfBoundsException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

// Include the template definitions AFTER they are declared above.
// With template classes, the compiler needs to see both, the declaration and the definition whenever it uses it with a specific type.
# include "Array.tpp"

#endif
