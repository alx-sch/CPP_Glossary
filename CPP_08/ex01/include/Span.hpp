#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>		// for std::vector
# include <iterator>	// for std::distance
# include <stdexcept>	// for std::length_error

# define SPAN_FULL	"Span is full, cannot add more numbers."

class	Span
{
	private:
		unsigned int		_size;	// Maximum size of the span
		std::vector<int>	_numbers; // Vector to store the numbers

	public:
		// Constructor and destructor
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		// Add single number
		void	addNumber(int number);

		// Add range of numbers using iterators
		// Template methods needd to be defined in the header file
		template <typename InputIterator>
		void	addNumbers(InputIterator begin, InputIterator end)
		{
			if (std::distance(begin, end) + _numbers.size() > _size) // Would adding the range to current vector exceed the size?
				throw std::length_error(SPAN_FULL);
			_numbers.insert(_numbers.end(), begin, end);
		}

		// Span calculations
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
};

#endif
