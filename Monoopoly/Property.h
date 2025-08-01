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
	bool mortgaged;
	size_t cottageCount;
	size_t castleCount;

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
	void setMortgaged(bool mortgaged);
	void setCottageCount(size_t cottageCount);
	void setCastleCount(size_t castleCount);

	unsigned int getPrice() const;
	unsigned int getPriceHouse() const;
	unsigned int getPriceCastle() const;
	unsigned int getPricePerNight() const;
	size_t getCottageCount() const;
	size_t getCastleCount() const;
	Color getColor() const;

	Player* getOwner() const;
	void setOwner(Player* player);

	void print() const override;
	Field* clone() const override;
	bool isMortgaged() const;

	// Inherited via Field
	void applyEffect(Player& player) override;

	
};

