#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>	// for std::find
# include <stdexcept>	// for std::runtime_error

// An "iterator" is type that represents an object used to navigate through the elements of a container.
// It acts like a pointer to elements in the container.

template <typename T>
typename T::iterator	easyfind(T &container, int value) // 'typename' as scope resolution could refer to a type or a value/member -> define it
{
	typename T::iterator	it;
	
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found in the container.");
	return it;
}

#endif
