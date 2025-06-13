#pragma once
#include "Field.h"
#include "StartField.h"
#include "Property.h"
#include "Parking.h"
#include "Jail.h"
#include "CardField.h"
#include "GoJail.h"

class Fields
{
	Deck* deck;

	Field** fields;
	size_t size;
	size_t capacity = 40;
	
	void copyFrom(const Fields& other);
	void moveFrom(Fields&& other);
	void free();

public:

	Fields();
	Fields(const Fields& other);
	Fields(Fields&& other) noexcept;
	Fields& operator=(const Fields& other);
	Fields& operator=(Fields&& other) noexcept;
	~Fields();

	void addField(Field* field);
	void printFields() const;
	void fillFields();
	
	size_t getSize() const;

	Field* operator[](size_t index) const;
};

