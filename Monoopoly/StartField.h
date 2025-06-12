#pragma once
#include "Field.h"

class StartField : public Field
{
public:

	StartField();

	void print() const override;

	Field* clone() const override;

};

