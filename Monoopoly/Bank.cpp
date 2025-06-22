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

			}
		}
	}
}


