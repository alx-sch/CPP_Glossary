#ifndef MIN_HPP
# define MIN_HPP

template <typename T>

const T&	min(const T& x, const T& y)
{
	return ( x < y ? x : y );
}

#endif
