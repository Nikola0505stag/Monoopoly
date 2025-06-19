
#include "Field.h"

Field::Field()
{
    setIndex(0);
    setDescription("DEFAULT_DESCRIPTION");
}

Field::Field(size_t index, const MyString& description)
{
    setIndex(index);
    setDescription(description);
}

int Field::getIndex() const
{
    return index;
}

void Field::setIndex(size_t index)
{
    this->index = index;
}

MyString Field::getDescription() const
{
    return description;
}

void Field::setDescription(const MyString& description)
{
    this->description = description;
}
