#include "Property.h"

Property::Property() : Field()
{
    setPrice(0);
	setPlayer(nullptr);
    setPriceHouse(0);
    setPriceCastle(0);
    setColor(Color::DEFAULT_COLOR);
    setPricePerNight(0);
    setMortgaged(false);
    setCastleCount(0);
    setCottageCount(0);
}

Property::Property(size_t index, const MyString& description, unsigned int pricePerNight, unsigned int price,
    unsigned int priceHouse, unsigned int priceCastle, Player* player, Color color)
    : Field(index, description)
{
    setPrice(price);
    setPlayer(player);
    setPriceCastle(priceCastle);
	setPriceHouse(priceHouse);
    setColor(color);
    setPricePerNight(pricePerNight);
    setMortgaged(false);
    setCastleCount(0);
    setCottageCount(0);
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

void Property::setColor(Color color)
{
    this->color = color;
}

void Property::setPricePerNight(unsigned int pricePerNight)
{
    if(pricePerNight<0)
		throw std::invalid_argument("Price per night cannot be negative.");
	this->pricePerNight = pricePerNight;
}

void Property::setMortgaged(bool mortgaged)
{
	this->mortgaged = mortgaged;
}

void Property::setCottageCount(size_t cottageCount)
{
    if(cottageCount > 4)
		throw std::invalid_argument("Cottage count cannot exceed 4.");

    this->cottageCount = cottageCount;
}

void Property::setCastleCount(size_t castleCount)
{
    if(castleCount > 4)
		throw std::invalid_argument("Castle count cannot exceed 4.");

    this->castleCount = castleCount;
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

unsigned int Property::getPricePerNight() const
{
    return pricePerNight;
}

size_t Property::getCottageCount() const
{
    return cottageCount;
}

size_t Property::getCastleCount() const
{
    return castleCount;
}

Color Property::getColor() const
{
    return color;
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
    std::cout << "|      "  << color<<"     |\n";
    std::cout << "|Mortgaged:"; mortgaged ? std::cout << "Yes" : std::cout << "No";
    std::cout << "|\n";
	std::cout << "|Cot.Count: " << cottageCount << "|\n";
	std::cout << "|Cas.Count: " << castleCount << "|\n";
    std::cout << "|Pr. night: " << pricePerNight << "|\n";
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

bool Property::isMortgaged() const
{
    return mortgaged;
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
        //throw std::invalid_argument("Property already owned by another player.\n");
        Dice dice;
        dice.rollOneDice();
		std::cout << "\nDays u would stay on this property: " << dice.getSum() << "\n";
        player.setMoney(player.getMoney() - dice.getSum() * this->pricePerNight);
        this->owner->setMoney(this->owner->getMoney() + dice.getSum() * this->pricePerNight);
    }
}
