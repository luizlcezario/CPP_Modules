#include <iostream>
# include "Data.hpp"
# include "Serializer.hpp"

int main()
{
	Data *data = new Data("Luis", 1.80, 80);
	uintptr_t ptr = Serializer::serialize(data);
	
	std::cout << "Name: " << data->getName() << std::endl;
	std::cout << "Len: " << data->getLen() << std::endl;
	std::cout << "Height: " << data->getHeight() << std::endl;
	std::cout << "IMC: " << data->calcIMC() << std::endl;
	std::cout << "is storage in :" << data << std::endl;
	std::cout << "the serializer number is:" << ptr<< std::endl;
	std::cout << "the return from the deserializer is:" << Serializer::deserialize(ptr) << std::endl;
}
