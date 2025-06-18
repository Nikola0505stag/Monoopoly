#pragma once
#include "Field.h"
#include "Player.h"

enum Color{
	LightBlue,
	Black,
	Purple,
	Orange,
	Red,
	Yellow,
	Green,
	DarkBlue,
	Van,
	DEFAULT_COLOR
};

class Property : public Field 
{
	unsigned int price;
	unsigned int pricePerNight;
	Player* owner;
	unsigned int priceHouse;
	unsigned int priceCastle;
	Color color;

public:
	Property();
	Property(size_t index, const MyString& description,unsigned int pricePerNight, unsigned int price,
		unsigned int priceHouse, unsigned int priceCastle, Player* player, Color color);


	void setPrice(unsigned int price);
	void setPriceHouse(unsigned int priceHouse);
	void setPriceCastle(unsigned int priceCastle);
	void setPlayer(Player* player);
	void setColor(Color color);
	void setPricePerNight(unsigned int pricePerNight);

	unsigned int getPrice() const;
	unsigned int getPriceHouse() const;
	unsigned int getPriceCastle() const;
	unsigned int getPricePerNight() const;
	Color getColor() const;

	Player* getOwner() const;

	void print() const override;
	Field* clone() const override;

	// Inherited via Field
	void applyEffect(Player& player) override;

	
};

