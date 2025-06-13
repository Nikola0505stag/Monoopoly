#include "StartField.h"

StartField::StartField(): Field(0,"Start Field")
{}

void StartField::print() const
{
	std::cout << "Start Field: " << getDescription() << " at index: " << getIndex() << std::endl;
}

Field* StartField::clone() const
{
	return new StartField(*this);
}

void StartField::applyEffect(Player& player)
{
	player.setMoney(player.getMoney() + 200);
}
