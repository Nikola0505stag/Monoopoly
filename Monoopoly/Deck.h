#pragma once
#include "Card.h"
#include <fstream>
#include <ctime>
#include "MovePositionCard.h"
#include "GroupPaymentCard.h"
#include "PaymentCard.h"

class Deck
{
	Card** cards;
	size_t size;
	size_t capacity = 32;

	void copyFrom(const Deck& other);
	void moveFrom(Deck&& other);
	void free();

public:
	Deck();
	Deck(const Deck& other);
	Deck(Deck&& other) noexcept;
	Deck& operator=(const Deck& other);
	Deck& operator=(Deck&& other) noexcept;
	~Deck();

	void addCard(Card* card);

	void printDeck() const;

	Card* operator[](size_t index) const;

	void shuffle();
	Card* drawCard();
	
	void fillDeck(size_t size,Player* players);
	void emptyDeck();
};

