#pragma once
#include "Field.h"

class Jail : public Field
{

public:
	Jail();
	Jail(size_t index);



	// Inherited via Field
	void print() const override;

	Field* clone() const override;


	// Inherited via Field
	void applyEffect(Player& player) override;

};

