#include "BuyCastleCommand.h"
#include "Monopoly.h"

BuyCastleCommand::BuyCastleCommand(Monopoly& game, size_t playerIndex):
	game(game), playerIndex(playerIndex)
{}

void BuyCastleCommand::execute()
{
	Player& player = game.getPlayer(playerIndex);
	MyString propertyName;
	char buff[1024];
	std::cout << "Input the name of the property you want to buy castle on: \n";
	std::cin.ignore();
	std::cin.getline(buff, 1024);
	propertyName = buff;

	try{
		game.getBank().buyCastle(&player, propertyName);
	}
	catch(const std::exception& e){
			std::cout << "Error: " << e.what() << "\n";
	}
}
