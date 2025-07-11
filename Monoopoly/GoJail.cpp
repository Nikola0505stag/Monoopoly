#include "GoJail.h"

GoJail::GoJail() : Field(0, "Go to Jail")
{}

GoJail::GoJail(size_t index) : Field(index, "Go to Jail")
{}

void GoJail::print() const
{
    //std::cout << "Go to Jail Field: " << getDescription() << " at index: " <<
    // getIndex() << std::endl;

	std::cout << "--------------\n";
	std::cout << "|            |\n";
	std::cout << "|            |\n";
	std::cout << "|------------|\n";
	std::cout << "| Go to Jail |\n";
	std::cout << "|------------|\n";
	std::cout << "|            |\n";
	std::cout << "|            |\n";
	std::cout << "--------------\n";
}

Field* GoJail::clone() const
{
    return new GoJail(*this);
}

void GoJail::applyEffect(Player& player)
{
    std::cout << "You are going to jail.";
	player.setPosition(10);
    player.prisoner();
}
