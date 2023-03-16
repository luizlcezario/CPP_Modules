#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "Data.hpp"

class Serializer
{
public:
	Serializer();
	~Serializer();
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &rhs);
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};



#endif