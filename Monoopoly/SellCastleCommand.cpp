#include "SellCastleCommand.h"
#include "Monopoly.h"

SellCastleCommand::SellCastleCommand(Monopoly& game, size_t playerIndex):
	game(game), playerIndex(playerIndex)
{}

void SellCastleCommand::execute()
{
	Player& player = game.getPlayer(playerIndex);
	MyString propertyName;
	char buff[1024];
	std::cout << "Input the name of the property you want to sell cottage from: \n";
	std::cin.ignore();
	std::cin.getline(buff, 1024);
	propertyName = buff;

	game.getBank().sellCastle(&player, propertyName);
}
