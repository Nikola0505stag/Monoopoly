#include "Jail.h"

Jail::Jail() : Field(0, "Jail")
{}

Jail::Jail(size_t index) : Field(index, "Jail")
{}

void Jail::print() const
{
	//std::cout << "Jail: " << getDescription() << " at index " << getIndex() << std::endl;
	std::cout << "--------------\n";
	std::cout << "|            |\n";
	std::cout << "|            |\n";
	std::cout << "|------------|\n";
	std::cout << "|    Jail    |\n";
	std::cout << "|------------|\n";
	std::cout << "|            |\n";
	std::cout << "|            |\n";
	std::cout << "--------------\n";
}

Field* Jail::clone() const
{
	return new Jail(*this);
}

void Jail::applyEffect(Player& player)
{
	std::cout << "You are just visiting the prison.";
}
