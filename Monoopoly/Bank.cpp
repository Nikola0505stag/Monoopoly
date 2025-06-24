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
				Color color = prop->getColor();
				int totalColorProps = 0;
				int ownedColorProps = 0;
				if (!prop->isMortgaged()) {
					if(prop->getCastleCount() > 0 || prop->getCottageCount() > 4)
						throw std::invalid_argument
						("You can only build castles!");

					for (int j = 0; j < fields->getSize(); j++) {
						Field* current = (*fields)[j];
						Property* p = dynamic_cast<Property*>(current);
						if (p && p->getColor() == color) {
							totalColorProps++;
							if (p->getOwner() == player)
								ownedColorProps++;
						}
					}

					if (totalColorProps != ownedColorProps)
						throw std::invalid_argument("You must own all properties of this color to build cottages.");

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
					if (prop->getCottageCount() < 4 && prop->getCastleCount() < 1)
						throw std::invalid_argument
						("You must build 4 cottages before you can build a castle!");
					prop->setCastleCount(prop->getCastleCount() + 1);
					prop->setCottageCount(0);
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

void Bank::sellCottage(Player* player, const MyString& propertyName)
{
	if (fields->doesPlayerOwnProperty(player, propertyName)) {
		for (int i = 0; i < fields->getSize(); i++) {
			if ((*fields)[i]->getDescription() == propertyName) {

				Property* prop = dynamic_cast<Property*>((*fields)[i]);
				if (!prop->isMortgaged()) {
					//if(prop->getCastleCount() > 1)
					prop->setCottageCount(prop->getCottageCount() - 1);
					player->setMoney(player->getMoney() + prop->getPriceHouse());
					prop->setPricePerNight(prop->getPricePerNight() -
						prop->getPricePerNight() / 5);

					std::cout << "\n\n";
					prop->print();
					std::cout << "\n\n";

				}
				else
					std::cout << "\nProperty is mortgaged! You cannot sell a cottage from it.\n\n";
			}
		}
	}
	else
		throw std::invalid_argument("Property not yours or not found!");
}

void Bank::sellCastle(Player* player, const MyString& propertyName)
{
	if (fields->doesPlayerOwnProperty(player, propertyName)) {
		for (int i = 0; i < fields->getSize(); i++) {
			if ((*fields)[i]->getDescription() == propertyName) {

				Property* prop = dynamic_cast<Property*>((*fields)[i]);
				if (!prop->isMortgaged()) {
					prop->setCastleCount(prop->getCastleCount() - 1);
					player->setMoney(player->getMoney() + prop->getPriceCastle());
					prop->setPricePerNight(prop->getPricePerNight() -
						prop->getPricePerNight() / 2);

					std::cout << "\n\n";
					prop->print();
					std::cout << "\n\n";

				}
				else
					std::cout << "\nProperty is mortgaged! You cannot sell a castle from it.\n\n";
			}
		}
	}
	else
		throw std::invalid_argument("Property not yours or not found!");
}

void Bank::trade(Player* player, const MyString& propertyName, Player* otherPlayer)
{
	std::cout << "\n\nTrading " << propertyName << " with " << otherPlayer->getName() << "\n\n";

	int price;
	std::cin >> price;
	std::cout << price;
	char answer;
	std::cout << "Want to trade? (y/n): ";
	std::cin >> answer;

	if (answer == 'y') {
		if (fields->doesPlayerOwnProperty(player, propertyName)) {
			for (int i = 0; i < fields->getSize(); i++) {
				if ((*fields)[i]->getDescription() == propertyName) {

					Property* prop = dynamic_cast<Property*>((*fields)[i]);
					if (!prop->isMortgaged()) {
						player->setMoney(player->getMoney() + price);
						otherPlayer->setMoney(otherPlayer->getMoney() - price);
						prop->setOwner(otherPlayer);
						std::cout << "\n\n";
						prop->print();
						std::cout << "\n\n";
					}
					else
						std::cout << "\nProperty is mortgaged! You cannot trade it.\n\n";
				}
			}
		}
		else
			throw std::invalid_argument("Property not yours or not found!");
	}
	else {
		std::cout << "Trade cancelled.\n";
	}
}


