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

MovePositionCard::MovePositionCard()
{
	setPositionChange(0);
}

MovePositionCard::MovePositionCard(int positionChange)
{
	setPositionChange(positionChange);
}