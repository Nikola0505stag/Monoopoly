#include "CardField.h"

CardField::CardField() : Field(0,"Card Field")
{
	setDeck(nullptr);
}

CardField::CardField(size_t index, Deck* deck) : Field(index, "Card Field")
{
	setDeck(deck);
}

void CardField::print() const
{
	std::cout << "CardField: " << getDescription() << " at index " << getIndex() << std::endl;
	if (deck != nullptr)
	{
		std::cout << "Deck: \n";
		deck->printDeck();
	}
	if (deck == nullptr)
		std::cout << "Deck: None\n";
}

Field* CardField::clone() const
{
	return new CardField(*this);
}

void CardField::setDeck(Deck* deck)
{
	this->deck = deck;
}

Deck* CardField::getDeck() const
{
	return deck;
}

void CardField::applyEffect(Player& player)
{
	if (deck == nullptr)
		throw std::invalid_argument("Deck is empty.");

	Card* card = deck->drawCard();
	card->applyEffect(player);
}
