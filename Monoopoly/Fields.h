#pragma once
#include "Field.h"

class Fields
{
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
};

