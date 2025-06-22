#pragma once
#include "MyString.h"
#include "Player.h"

class Field
{

	size_t index;
	MyString description;

public:

	Field();
	Field(size_t index, const MyString& description);

	int getIndex() const;
	void setIndex(size_t index);

	MyString getDescription() const;
	void setDescription(const MyString& description);

	virtual ~Field() = default;
	virtual void print() const = 0;
	virtual Field* clone() const = 0;

	virtual void applyEffect(Player& player) = 0;
};
