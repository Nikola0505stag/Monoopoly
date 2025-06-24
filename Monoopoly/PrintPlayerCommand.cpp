#include "PrintPlayerCommand.h"
#include "Monopoly.h"

PrintPlayerCommand::PrintPlayerCommand(Monopoly& game, size_t playerIndex):
	game(game), playerIndex(playerIndex)
{}

void PrintPlayerCommand::execute()
{
	std::cout << game.getPlayer(playerIndex) << "\n";
}
