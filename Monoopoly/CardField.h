#pragma once
#include "Field.h"
#include "Deck.h"
class CardField : public Field
{
	Deck* deck;

public:

	CardField();
	CardField(size_t index, Deck* deck);
	
	void print() const override;
	
	Field* clone() const override;

	void setDeck(Deck* deck);
	Deck* getDeck() const;

	void applyEffect(Player& player) override;

};

