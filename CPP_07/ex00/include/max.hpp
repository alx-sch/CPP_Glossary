#ifndef MAX_HPP
# define MAX_HPP

template <typename T>
const T&	max(const T& x, const T& y)
{
	return ( x > y ? x : y );
}

#endif
