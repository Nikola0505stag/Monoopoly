#include "Fields.h"

void Fields::copyFrom(const Fields& other)
{
	size = other.size;
	capacity = other.capacity;
	fields = new Field * [capacity] {};
	for (int i = 0; i < size; i++) {
		fields[i] = other.fields[i]->clone();
	}
	deck = other.deck;
}

void Fields::moveFrom(Fields&& other)
{	
	size = other.size;
	capacity = other.capacity;

	fields = other.fields;

	other.size = 0;
	other.capacity = 0;
	other.fields = nullptr;
	deck = other.deck;
	other.deck = nullptr;
}

void Fields::free()
{
	for (int i = 0; i < size; i++) {
		delete fields[i];
	}
	delete[] fields;

	size = 0;
	capacity = 0;
	deck = nullptr;
}

Fields::Fields()
{
	size = 0;
	capacity = 40;
	deck = nullptr;
	fields = new Field * [capacity] {};
}

Fields::Fields(const Fields& other)
{
	copyFrom(other);
}

Fields::Fields(Fields&& other) noexcept
{
	moveFrom(std::move(other));
}

Fields& Fields::operator=(const Fields& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Fields& Fields::operator=(Fields&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Fields::~Fields()
{
	free();
}

void Fields::addField(Field* field)
{
	if (size >= capacity)
		throw std::invalid_argument("Fields are full, cannot add more fields.");

	fields[size++] = field->clone();
}

void Fields::printFields() const
{
	for (int i = 0; i < size; i++) {
		std::cout << std::endl;
		fields[i]->print();
	}
}

void Fields::fillFields()
{
	addField(new StartField());
	addField(new Property(1,"Mediterranean Avenue",60,50,50,nullptr));
	addField(new CardField(2,deck));
	addField(new Property(3,"Baltic Avenue",60,50,50,nullptr));
	addField(new CardField(4, deck));
	addField(new Property(5,"Red van",200,100,100,nullptr));
	addField(new Property(6, "Oriental Avenue",100,50,50,nullptr));
	addField(new CardField(7, deck));
	addField(new Property(8,"Vermont Avenue",100,50,50,nullptr));
	addField(new Property(9,"Connecticut Avenue",120,50,50,nullptr));
	addField(new Jail(10));
	addField(new Property(11, "St. Charles Place", 140, 100, 100, nullptr));
	addField(new CardField(12, deck));
	addField(new Property(13, "States Avenue",140,100,100,nullptr));
	addField(new Property(14,"Virginia Avenue",160, 100, 100, nullptr));
	addField(new Property(15,"Silver van",200,100,100,nullptr));
	addField(new Property(16,"St. James Place",180,100,100,nullptr));
	addField(new CardField(17, deck));
	addField(new Property(18,"Columbia Avenue",180, 100, 100, nullptr));
    addField(new Property(19,"New York Avenue",200, 100, 100, nullptr));
	addField(new Parking(20));
	addField(new Property(21,"Kentucky Avenue",220,150,150,nullptr));
	addField(new CardField(22, deck));
	addField(new Property(23,"Indiana Avenue",220,150,150,nullptr));
	addField(new Property(24,"Illinois Avenue",240,150,150,nullptr));
	addField(new Property(25,"White van",200,100,100,nullptr));
	addField(new Property(26,"Atlantic Avenue",260,150,150,nullptr));
	addField(new Property(27,"Ventnor Avenue",260,150,150,nullptr));
	addField(new CardField(28, deck));
	addField(new Property(29,"Marvin Gardens",270,150,150,nullptr));
	addField(new GoJail(30));
	addField(new Property(31,"Pacific Avenue",300,200,200,nullptr));
	addField(new Property(32,"North Carolina Avenue", 300,200,200,nullptr));
	addField(new CardField(33, deck));
	addField(new Property(34,"Pennsylvania Avenue",320,200,200,nullptr));
	addField(new Property(35,"Black van",200,100,100,nullptr));
	addField(new CardField(36, deck));
	addField(new Property(37,"Park Place",350,200,200,nullptr));
	addField(new CardField(38, deck));
	addField(new Property(39,"Boardwalk ",400,200,200,nullptr));
}

size_t Fields::getSize() const
{
	return size;
}

Field* Fields::operator[](size_t index) const
{
	return fields[index];
}

void Fields::setDeck(Deck* deck)
{
	this->deck = deck;
}

Deck* Fields::getDeck() const
{
	return deck;
}
