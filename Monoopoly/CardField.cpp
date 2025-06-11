#include "CardField.h"

CardField::CardField() : Field(0,"Card Field")
{}

CardField::CardField(size_t index) : Field(index, "Card Field")
{}

void CardField::print() const
{
	std::cout << "CardField: " << getDescription() << " at index " << getIndex() << std::endl;
}

Field* CardField::clone() const
{
	return new CardField(*this);
}
