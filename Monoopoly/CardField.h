#pragma once
#include "Field.h"
class CardField : public Field
{

public:

	CardField();
	CardField(size_t index);
	
	void print() const override;
	
	Field* clone() const override;


};

