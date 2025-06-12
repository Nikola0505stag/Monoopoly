#pragma once
#include "Field.h"

class GoToJailField : public Field
{
public:
	GoToJailField();
	GoToJailField(size_t index);

	void print() const override;

	Field* clone() const override;

};

