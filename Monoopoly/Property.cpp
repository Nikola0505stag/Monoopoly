#include "Property.h"

Property::Property() : Field()
{
    setPrice(0);
	setPlayer(nullptr);
    setPriceHouse(0);
    setPriceCastle(0);
}

Property::Property(size_t index, const MyString& description, unsigned int price,
    unsigned int priceHouse, unsigned int priceCastle, Player* player)
    : Field(index, description)
{
    setPrice(price);
    setPlayer(player);
    setPriceCastle(priceCastle);
	setPriceHouse(priceHouse);
}

void Property::setPrice(unsigned int price)
{
    this->price = price;
}

void Property::setPriceHouse(unsigned int priceHouse)
{
	this->priceHouse = priceHouse;
}

void Property::setPriceCastle(unsigned int priceCastle)
{
    this->priceCastle = priceCastle;
}

void Property::setPlayer(Player* player)
{
    this->owner = player;
}

unsigned int Property::getPrice() const
{
    return price;
}

unsigned int Property::getPriceHouse() const
{
    return priceHouse;
}

unsigned int Property::getPriceCastle() const
{
    return priceCastle;
}

Player* Property::getOwner() const
{
    return owner;
}

void Property::print() const
{
    std::cout << "Property: " << getDescription() << "\n"
        << "Index: " << getIndex() << "\n"
        << "Price: " << getPrice() << "\n"
        << "Price for House: " << getPriceHouse() << "\n"
        << "Price for Castle: " << getPriceCastle() << "\n"
        << "Player: " << *owner;
        
}

Field* Property::clone() const
{
    return new Property(*this);
}
