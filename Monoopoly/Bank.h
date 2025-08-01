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
	void buyCottage(Player* player, const MyString& propertyName);
	void buyCastle(Player* player, const MyString& propertyName);
	void sellCottage(Player* player, const MyString& propertyName);
	void sellCastle(Player* player, const MyString& propertyName);
	void trade(Player* player, const MyString& propertyName, Player* otherPlayer);

};

