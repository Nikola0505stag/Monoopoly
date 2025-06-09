#include "Deck.h"

void Deck::copyFrom(const Deck& other)
{
	size = other.size;
	capacity = other.capacity;
	cards = new Card * [capacity];
	for (size_t i = 0; i < size; ++i) {
		cards[i] = other.cards[i]->clone();
	}
}

void Deck::moveFrom(Deck&& other)
{
	size = other.size;
	capacity = other.capacity;
	cards = other.cards;
	other.cards = nullptr;
	other.size = 0;
	other.capacity = 0;
}

void Deck::free()
{
	for (size_t i = 0; i < size; ++i) {
		delete cards[i];
	}
	delete[] cards;
	cards = nullptr;
	size = 0;
	capacity = 0;
}

Deck::Deck()
{
	size = 0;
	capacity = 64;
	cards = new Card * [capacity] {nullptr};
}

Deck::Deck(const Deck& other)
{
	copyFrom(other);
}

Deck::Deck(Deck&& other) noexcept
{
	moveFrom(std::move(other));
}

Deck& Deck::operator=(const Deck& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Deck& Deck::operator=(Deck&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Deck::~Deck()
{
	free();
}

void Deck::addCard(Card* card)
{
	if (size >= capacity) {
		throw std::invalid_argument("Deck is full, cannot add more cards.");
	}
	cards[size++] = card->clone();
}

void Deck::printDeck() const
{
	for (int i = 0; i < size; ++i) {
		cards[i]->print();
	}
}

Card* Deck::operator[](size_t index) const
{
	if (index >= size) {
		throw std::out_of_range("Index out of range.");
	}
	return cards[index];
}

void Deck::shuffle()
{
	srand(time(0));
	if (size == 0) {
		throw std::invalid_argument("Deck is empty, cannot shuffle.");
	}
	for (size_t i = size - 1; i > 0; --i) {
		size_t j = rand() % (i + 1);
		std::swap(cards[i], cards[j]);
	}
}

Card* Deck::drawCard()
{
	if (size == 0) {
		throw std::out_of_range("Deck is empty, cannot draw a card.");
	}

	Card* card = cards[size - 1]->clone();
	cards[size - 1] = nullptr;
	size--;

	return card;
}

void Deck::fillDeck(size_t size, Player* players)
{
	// capacity = 32

	for (int i = 0; i < 10; i++) {
		addCard(new MovePositionCard(i + 1)); 
	}
	for (int i = 10; i < 20; i++) {
		addCard(new PaymentCard(i * 7));
	}
	for (int i = 20; i < 32; i++) {
		if (i % 2 == 0)
			addCard(new GroupPaymentCard(size,i * 5,players));
		else 
			addCard(new GroupPaymentCard(size, i * -5, players));
	}
	
}

void Deck::emptyDeck()
{
	for (size_t i = 0; i < size; ++i) {
		delete cards[i];
		cards[i] = nullptr;
	}
	size = 0;
}




