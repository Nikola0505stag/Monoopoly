#include "SellPropertyCommand.h"
#include "Monopoly.h"

SellPropertyCommand::SellPropertyCommand(Monopoly& game, size_t playerIndex):
	game(game), playerIndex(playerIndex)
{}

void SellPropertyCommand::execute()
{
	Player& player = game.getPlayer(playerIndex);
	MyString propertyName;
	char buff[1024];
	std::cout << "Input the name of the property you want to sell: \n";
	std::cin.ignore();
	std::cin.getline(buff, 1024);
	propertyName = buff;
	//std::cout << propertyName;

	game.getBank().sellProperty(&player, propertyName);

}
