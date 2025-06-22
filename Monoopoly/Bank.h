#pragma once
#include "Player.h"
#include "Fields.h"

class Bank
{
	Fields* fields;

public:

	Bank();
	Bank(Fields* fields);

	void setFields(Fields* fields);
	
	//void printBankFieldsTEST() const;
	void sellProperty(Player* player, const MyString& propertyName);

};

