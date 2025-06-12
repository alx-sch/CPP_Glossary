#include <algorithm>			// for std::sort, std::min_element, std::max_element
#include <cstddef>				// for size_t
#include "../include/Span.hpp"	// <stdexcept> for std::length_error

#define SPAN_TOO_SHORT	"Not enough numbers to calculate a span."

// Constructors and destructor
Span::Span() : _size(0) {}

Span::Span(unsigned int N) : _size(N) {}

Span::Span(const Span& other) : _size(other._size), _numbers(other._numbers) {}

Span&	Span::operator=(const Span& other)
{
	if (this != &other) {
		_size = other._size;
		_numbers = other._numbers;
	}

	return *this;
}

Span::~Span() {}

// Add single number
void	Span::addNumber(int number)
{
	if (_numbers.size() >= _size)
		throw std::length_error(SPAN_FULL);
	_numbers.push_back(number);
}

// Calculate the shortest span (smallest difference between any two numbers)
unsigned int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::length_error(SPAN_TOO_SHORT);

	std::vector<int>	sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end()); // Sort numbers in vector in ascending orderßß

	unsigned int	span;
	unsigned int	shortest = -1; // Wraps around to the largest unsigned int value
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < shortest)
			shortest = span;
	}

	return shortest;
}

// Calculate the longest span (largest difference between any two numbers)
unsigned int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::length_error(SPAN_TOO_SHORT);

	long	min = *std::min_element(_numbers.begin(), _numbers.end()); // '*' to dereference the iterator, to get the actual value
	long	max = *std::max_element(_numbers.begin(), _numbers.end());

	return (max - min);
}
