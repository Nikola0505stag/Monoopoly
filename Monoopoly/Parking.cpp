#include "Parking.h"

Parking::Parking() : Field(0, "Parking Field")
{}

Parking::Parking(size_t index): Field(index, "Parking Field")
{}

void Parking::print() const
{
	std::cout << "Parking Field: " << getDescription() << " at index: " << getIndex() << std::endl;
}

Field* Parking::clone() const
{
    return new Parking(*this);
}
