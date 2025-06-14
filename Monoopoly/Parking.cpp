#include "Parking.h"

Parking::Parking() : Field(0, "Parking Field")
{}

Parking::Parking(size_t index): Field(index, "Parking Field")
{}

void Parking::print() const
{
	//std::cout << "Parking Field: " << getDescription() << " at index: " 
	// << getIndex() << std::endl;

	std::cout << "--------------\n";
	std::cout << "|            |\n";
	std::cout << "|            |\n";
	std::cout << "|------------|\n";
	std::cout << "|  Parking   |\n";
	std::cout << "|------------|\n";
	std::cout << "|            |\n";
	std::cout << "|            |\n";
	std::cout << "--------------\n";
}

Field* Parking::clone() const
{
    return new Parking(*this);
}

void Parking::applyEffect(Player& player)
{
	std::cout << "You are in the parking lot.";
}
