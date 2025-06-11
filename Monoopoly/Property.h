#pragma once
#include "Field.h"
#include "Player.h"
class Property : public Field 
{
	unsigned int price;
	Player* owner;
	unsigned int priceHouse;
	unsigned int priceCastle;

public:
	Property();
	Property(size_t index, const MyString& description, unsigned int price,
		unsigned int priceHouse, unsigned int priceCastle, Player* player);


	void setPrice(unsigned int price);
	void setPriceHouse(unsigned int priceHouse);
	void setPriceCastle(unsigned int priceCastle);
	void setPlayer(Player* player);
	

	unsigned int getPrice() const;
	unsigned int getPriceHouse() const;
	unsigned int getPriceCastle() const;

	Player* getOwner() const;

	void print() const override;
	Field* clone() const override;
};

