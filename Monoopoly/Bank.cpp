#include "Bank.h"

Bank::Bank()
{
	setFields(nullptr);
}

Bank::Bank(Fields* fields)
{
	setFields(fields);
}

void Bank::setFields(Fields* fields)
{
	this->fields = fields;
}

void Bank::sellProperty(Player* player, const MyString& propertyName)
{
	//fields->doesPlayerOwnProperty(player, propertyName) ?
		//std::cout << "Yes" : std::cout << "No";

	if (fields->doesPlayerOwnProperty(player, propertyName)) {
		for (int i = 0; i < fields->getSize(); i++) {
			if ((*fields)[i]->getDescription() == propertyName) {
			
				Property* prop = dynamic_cast<Property*>((*fields)[i]);
				player->setMoney(player->getMoney() + prop->getPrice()/2);
				prop->setMortgaged(true);
				std::cout << "\n\n";
				prop->print();
				break;
			}
		}
	}
	else
		throw std::invalid_argument("Property not yours or not found!");
}

void Bank::buyCottage(Player* player, const MyString& propertyName)
{
	if (fields->doesPlayerOwnProperty(player, propertyName)) {
		for (int i = 0; i < fields->getSize(); i++) {
			if ((*fields)[i]->getDescription() == propertyName) {

				Property* prop = dynamic_cast<Property*>((*fields)[i]);
				if (!prop->isMortgaged()) {
					std::cout << "\n\n" << prop->getPricePerNight() << "\n\n";

					prop->setCottageCount(prop->getCottageCount() + 1);
					player->setMoney(player->getMoney() - prop->getPriceHouse());
					prop->setPricePerNight(prop->getPricePerNight() +
						prop->getPricePerNight() / 5);
					std::cout << "\n\n";
					prop->print();
					std::cout << "\n\n";

				}
				else
					std::cout << "\nProperty is mortgaged! You cannot buy a cottage on it.\n\n";
			}
		}
	}
	else
		throw std::invalid_argument("Property not yours or not found!");
}

void Bank::buyCastle(Player* player, const MyString& propertyName)
{
	if (fields->doesPlayerOwnProperty(player, propertyName)) {
		for (int i = 0; i < fields->getSize(); i++) {
			if ((*fields)[i]->getDescription() == propertyName) {
				
				Property* prop = dynamic_cast<Property*>((*fields)[i]);
				if (!prop->isMortgaged()) {
					prop->setCastleCount(prop->getCastleCount() + 1);
					player->setMoney(player->getMoney() - prop->getPriceCastle());
					prop->setPricePerNight(prop->getPricePerNight() +
						prop->getPricePerNight() / 2);

					std::cout << "\n\n";
					prop->print();
					std::cout << "\n\n";

				}
				else
					std::cout << "\nProperty is mortgaged! You cannot buy a castle on it.\n\n";
			}
		}
	}
	else
		throw std::invalid_argument("Property not yours or not found!");
}


