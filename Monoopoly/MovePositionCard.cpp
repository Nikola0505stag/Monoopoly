#include "MovePositionCard.h"

void MovePositionCard::setPositionChange(int positionChange)
{
	this->positionChange = positionChange;
}

int MovePositionCard::getPositionChange() const
{
    return positionChange;
}

void MovePositionCard::applyEffect(Player& player)
{
	player.setPosition(player.getPosition() + positionChange);
}

Card* MovePositionCard::clone() const
{
	return new MovePositionCard(*this);
}

void MovePositionCard::print() const
{
	std::cout << "MovePositionCard: Move " << positionChange << " positions." << std::endl;
}

MovePositionCard::MovePositionCard()
{
	setPositionChange(0);
}

MovePositionCard::MovePositionCard(int positionChange)
{
	setPositionChange(positionChange);
}