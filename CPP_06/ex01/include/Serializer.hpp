#ifndef	SERIALIZER_HPP
# define	SERIALIZER_HPP

# include <stdint.h> // for uintptr_t -> guaranteed to be large enough to hold a pointer
# include "Data.hpp"

class	Serializer
{
	private: // Constructors and destructors private to prevent instantiation
		Serializer();
		Serializer(const Serializer& other);
		Serializer&	operator=(const Serializer& other);
		~Serializer();

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
