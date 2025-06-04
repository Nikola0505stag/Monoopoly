#pragma once
#define START_MONEY 1500
#include "MyString.h"

class Player
{
	MyString name;
	int money;
	int position;

public:
	Player();
	Player(MyString name);

	MyString getName() const;
	void setName(MyString name);

	int getMoney() const;
	void setMoney(int money);

	int getPosition() const;
	void setPosition(int position);

	friend std::ostream& operator<<(std::ostream& os, const Player& player);
	friend std::istream& operator>> (std::istream& is, Player& player);
};

