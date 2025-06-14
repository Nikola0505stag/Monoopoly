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
   /* std::cout << "Property: " << getDescription() << "\n"
        << "Index: " << getIndex() << "\n"
        << "Price: " << getPrice() << "\n"
        << "Price for House: " << getPriceHouse() << "\n"
        << "Price for Castle: " << getPriceCastle() << "\n";
    if (owner == nullptr) 
		std::cout << "Player: None\n";
    else 
        std::cout<< "Player: " << *owner << "\n";*/

    std::cout << "--------------\n";
    std::cout << "|  Property  |\n";
    std::cout << "|------------|\n";
    std::cout << "|" <<getDescription() <<"|\n";
    std::cout << "|    " <<getPrice() << "     |\n";
    std::cout << "|            |\n";
    if (owner == nullptr)
        std::cout << "| Player:None|\n";
    else
		std::cout << "| Player: " << owner->getName() << "|\n";
    std::cout << "|            |\n";
    std::cout << "--------------\n";
        
}

Field* Property::clone() const
{
    return new Property(*this);
}

void Property::applyEffect(Player& player)
{
    if (getOwner() == nullptr) {
        std::cout << "Want to buy? y/n";
        char choice;

        std::cin >> choice;
        if (choice == 'y') {
            if (player.getMoney() >= getPrice()) {
                player.setMoney(player.getMoney() - getPrice());
                setPlayer(&player);
                std::cout << "You bought the property: " << getDescription() << "\n";
            }
            else {
                throw std::invalid_argument("Not enough money to buy the property.\n");
            }
        }
        else {
            std::cout << "You chose not to buy the property.\n";
        }
    }
    else {
        throw std::invalid_argument("Property already owned by another player.\n");
    }
}
