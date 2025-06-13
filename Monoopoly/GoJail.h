#pragma once
#include "Field.h"

class GoJail : public Field
{
public:
	GoJail();
	GoJail(size_t index);

	void print() const override;
	Field* clone() const override;

	// Inherited via Field
	void applyEffect(Player& player) override;
};

