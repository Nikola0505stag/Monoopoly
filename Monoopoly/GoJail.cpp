#include "GoJail.h"

GoJail::GoJail() : Field(0, "Go to Jail")
{}

GoJail::GoJail(size_t index) : Field(index, "Go to Jail")
{}

void GoJail::print() const
{
    std::cout << "Go to Jail Field: " << getDescription() << " at index: " << getIndex() << std::endl;
}

Field* GoJail::clone() const
{
    return new GoJail(*this);
}
