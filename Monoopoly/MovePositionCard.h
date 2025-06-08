#pragma once
#include "Card.h"

class MovePositionCard : public Card
{
	int positionChange;

public:
	MovePositionCard();
	MovePositionCard(int positionChange);

	void setPositionChange(int positionChange);
	int getPositionChange() const;

	void applyEffect(Player& player) override;

	Card* clone() const override;

	// Inherited via Card
	void print() const override;
};

