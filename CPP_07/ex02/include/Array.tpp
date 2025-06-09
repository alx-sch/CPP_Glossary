// #include <iostream>

// Every template method defined outside the class must have a 'template <typename T>' before the method name.
// Array<T>:: for every member to connect the definition to the right template class.

// Default constructor: empty array
template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

// Consructor with 'size' elements
// 'new T[size]()' zero-initializes all elements.
// '()' makes sure that all elements are initialized to the default value of T (e.g., 0 for int, "" for std::string).
template <typename T>
Array<T>::Array(unsigned int size) : _array(new T[size]()), _size(size) {}

// Copy constructor (deep copy)
template <typename T>
Array<T>::Array(const Array<T>& other) : _array(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = other._array[i];
	}
}

// Assignment operator (deep copy + self-assignment check)
template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other)
{
	if (this != &other) // Self-assignment check
	{
		delete[] _array; // Free existing memory
		_array = NULL;
		_size = other._size;
		if (_size > 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_array[i] = other._array[i];
		}
	}
	return *this;
}

// Destructor: free allocated memory
template <typename T>
Array<T>::~Array()
{
	delete[] _array; // Free the array memory
}

/////////
/////////

// Access operator (non-const)
template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

// Access operator (const)
template <typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	// std::cout << "\nconst operator [] called: ";
	return _array[index];
}

// Returns the size of the array
template <typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}

// Exception message for out-of-bounds access
template <typename T>
const char*	Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Array index out of bounds");
}
