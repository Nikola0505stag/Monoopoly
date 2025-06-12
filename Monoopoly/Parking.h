#pragma once
#include "Field.h"

class Parking : public Field
{

public:
	Parking();
	Parking(size_t index);

	void print() const override;

	Field* clone() const override;

};

