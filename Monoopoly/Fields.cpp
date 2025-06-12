#include "Fields.h"

void Fields::copyFrom(const Fields& other)
{
	size = other.size;
	capacity = other.capacity;
	fields = new Field * [capacity] {};
	for (int i = 0; i < size; i++) {
		fields[i] = other.fields[i]->clone();
	}
}

void Fields::moveFrom(Fields&& other)
{	
	size = other.size;
	capacity = other.capacity;

	fields = other.fields;

	other.size = 0;
	other.capacity = 0;
	other.fields = nullptr;
}

void Fields::free()
{
	for (int i = 0; i < size; i++) {
		delete fields[i];
	}
	delete[] fields;

	size = 0;
	capacity = 0;
}

Fields::Fields()
{
	size = 0;
	capacity = 40;
	fields = new Field * [capacity] {};
}

Fields::Fields(const Fields& other)
{
	copyFrom(other);
}

Fields::Fields(Fields&& other) noexcept
{
	moveFrom(std::move(other));
}

Fields& Fields::operator=(const Fields& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Fields& Fields::operator=(Fields&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Fields::~Fields()
{
	free();
}

void Fields::addField(Field* field)
{
	if (size >= capacity)
		throw std::invalid_argument("Fields are full, cannot add more fields.");

	fields[size++] = field->clone();
}

void Fields::printFields() const
{
	for (int i = 0; i < size; i++) {
		std::cout << std::endl;
		fields[i]->print();
	}
}
