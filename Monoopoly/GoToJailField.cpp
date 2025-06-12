#include "GoToJailField.h"

GoToJailField::GoToJailField() : Field(0, "Go To Jail Field")
{}

GoToJailField::GoToJailField(size_t index) : Field(index, "Go To Jail Field")
{}

void GoToJailField::print() const
{
	std::cout << "GoToJailField: " << getDescription() << " at index " << getIndex() << std::endl;
}

Field* GoToJailField::clone() const
{
    return new GoToJailField(*this);
}
