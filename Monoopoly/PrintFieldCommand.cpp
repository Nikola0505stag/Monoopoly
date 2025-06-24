#include "PrintFieldCommand.h"
#include "Monopoly.h"

PrintFieldCommand::PrintFieldCommand(Monopoly& game)
	: game(game)
{}

void PrintFieldCommand::execute()
{
	int index;
	std::cout << "Insert index: \n";
	std::cin >> index;

	game.getFields()[index]->print();
}
