#include "BuyCottageCommand.h"
#include "Monopoly.h"

BuyCottageCommand::BuyCottageCommand(Monopoly& game, size_t playerIndex):
	game(game), playerIndex(playerIndex)
{}

void BuyCottageCommand::execute()
{
	Player& player = game.getPlayer(playerIndex);
	MyString propertyName;
	char buff[1024];
	std::cout << "Input the name of the property you want to buy cottage on: \n";
	std::cin.ignore();
	std::cin.getline(buff, 1024);
	propertyName = buff;

	try
	{
		game.getBank().buyCottage(&player, propertyName);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
}
