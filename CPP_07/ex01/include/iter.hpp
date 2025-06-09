#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef> // for size_t

// F is the callable type: function pointer, function template, functor, lambda, etc.
// Using 'void (*func)(T&)' instead would restrict to plain functions taking exactly T& (const or non-const).
// This causes problems if T is const but the function expects non-const T&, or vice versa.

// Iterates over an array and applies a function to each element.
template <typename T, typename F>
void	iter(T* array, size_t length, F func)
{
	size_t	i = 0;

	if (!array || length == 0)
		return;

	while (i < length)
	{
		func(array[i]);
		i++;
	}
}

#endif
