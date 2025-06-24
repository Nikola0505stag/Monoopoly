#include "TradeCommand.h"
#include "Monopoly.h"

TradeCommand::TradeCommand(Monopoly& game, size_t playerIndex):
	game(game), playerIndex(playerIndex)
{}

void TradeCommand::execute()
{
	Player& player = game.getPlayer(playerIndex);

	std::cout << "Insert index of the player you want to trade with: \n";
	int index;
	std::cin >> index;

	if (index > game.getPlayerSize())
		throw std::invalid_argument("Invalid player index");

	Player& otherPlayer = game.getPlayer(index);

	char buff[1024];
	std::cout << "Insert property name you want to trade: \n";
	std::cin.ignore();
	std::cin.getline(buff, 1024);
	MyString prop = buff;

	game.getBank().trade(&player,prop,&otherPlayer);

}
